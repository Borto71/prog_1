/*
  Sia dato un file di testo il cui nome è inserito da tastiera. Il file
  contiene una sequenza di numeri interi positivi (di lunghezza indefinita), 
  uno per ogni riga.

  Completare il programma definendo i seguenti sottoprogrammi:

  1. Il sottoprogramma costruisci_lista che prende in input il nome del file e 
     restituisce una lista concatenata contenente i numeri letti dal file nello 
     stesso ordine in cui appaiono nel file. Se vi sono problemi nell'apertura 
     del file, la funzione deve restituire NULL.
  
  2. Il sottoprogramma RICORSIVO filtra_lista che prende in input un 
     puntatore alla testa della lista e un intero k. Il sottoprogramma deve 
     modificare la lista rimuovendo (e deallocando correttamente) tutti i nodi 
     il cui valore è un multiplo di k (cioè valore % k == 0). Il sottoprogramma 
     deve poi restituire il puntatore alla nuova testa della lista modificata.
  
  3. Il sottoprogramma free_list che prende in input un puntatore alla 
     testa della lista e dealloca tutta la memoria occupata dai nodi.

  Il programma principale (main) e la funzione di stampa sono già forniti e 
  non devono essere modificati. Si aggiungano gli #include necessari.
*/

#include <stdio.h>
#include <stdlib.h> // Aggiunto per malloc e free

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

/* Prototipi delle funzioni */
Lista costruisci_lista(char *nome_file);
Lista filtra_lista(Lista l, int k);
void free_list(Lista l);
void stampa_lista(Lista l);

int main() {
    char nome_file[100];
    int k;
    Lista l = NULL;

    scanf("%99s", nome_file);
    scanf("%d", &k);

    l = costruisci_lista(nome_file);
    
    if (l == NULL) {
        printf("Errore o file vuoto.\n");
        return -1;
    }

    printf("Lista originale:\n");
    stampa_lista(l);

    l = filtra_lista(l, k);

    printf("Lista filtrata:\n");
    stampa_lista(l);

    free_list(l);

    return 0;
}

void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("%d ", l->valore);
        l = l->next;
    }
    printf("\n");
}

/* ==============================================
   IMPLEMENTARE I SEGUENTI SOTTOPROGRAMMI
   ============================================== */

Lista costruisci_lista(char *nome_file) {
    FILE *fp;
    fp = fopen(nome_file, "r");
    int numero;

    if(fp == NULL){
        return NULL;
    }

    Nodo *coda = NULL;
    Nodo *testa = NULL;
    while (fscanf(fp, "%d", &numero) == 1)
    {
        Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));
        nuovo_nodo->valore = numero;
        nuovo_nodo->next = NULL;

        if(testa == NULL){
            testa = nuovo_nodo;
            coda = nuovo_nodo;
        } else {
            coda->next = nuovo_nodo;
            coda = nuovo_nodo;
        }
    }

    fclose(fp);
    return testa;
}

// QUESTA FUNZIONE DEVE ESSERE RICORSIVA
Lista filtra_lista(Lista l, int k) {
    if(l == NULL){
        return NULL;
    }

    l->next = filtra_lista(l->next, k);
    if(l->valore % k == 0){
        Nodo *temp = l->next;
        free(l);
        return temp;
    }

    return l;
}

void free_list(Lista l) {
    if(l == NULL){
        return ;
    }

    free(l->next);
    free(l);
}