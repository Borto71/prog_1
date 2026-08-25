/*
  Scrivere un programma che, dato un file di testo il cui nome è inserito da
  tastiera, legga una serie di parole e costruisca una lista concatenata 
  contenente SOLO le parole palindrome.

  Il file contiene un numero indefinito di parole, ciascuna di lunghezza 
  massima 50 caratteri, separate da spazi o ritorni a capo.

  Completare il programma definendo i seguenti sottoprogrammi:

  1. int is_palindroma(char *parola, int inizio, int fine)
     Sottoprogramma RICORSIVO che verifica se una stringa è palindroma 
     (cioè si legge uguale da sinistra a destra e da destra a sinistra, 
     es. "osso", "radar"). Restituisce 1 se è palindroma, 0 altrimenti.

  2. Lista estrai_palindrome(char *nome_file)
     Sottoprogramma che apre il file, legge le parole una ad una e, 
     utilizzando la funzione is_palindroma, inserisce le parole palindrome 
     in una nuova lista concatenata. Ogni nodo della lista deve contenere 
     una stringa allocata dinamicamente. Restituisce la testa della lista. 
     Se il file non esiste, restituisce NULL.

  3. void free_lista(Lista l)
     Sottoprogramma che dealloca l'intera lista, ricordandosi di deallocare 
     sia la struttura del nodo che la stringa in esso contenuta.

  Il main e la funzione di stampa sono già forniti. Si aggiungano gli #include necessari.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char *parola;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

/* Prototipi */
int is_palindroma(char *parola, int inizio, int fine);
Lista estrai_palindrome(char *nome_file);
void free_lista(Lista l);
void stampa_lista(Lista l);

int main() {
    char nome_file[100];
    Lista l = NULL;

    printf("Inserisci il nome del file: ");
    scanf("%99s", nome_file);

    l = estrai_palindrome(nome_file);
    
    if (l == NULL) {
        printf("Nessuna parola trovata o errore di apertura.\n");
        return -1;
    }

    printf("Parole palindrome trovate:\n");
    stampa_lista(l);

    free_lista(l);

    return 0;
}

void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("- %s\n", l->parola);
        l = l->next;
    }
}

/* ==============================================
   IMPLEMENTARE I SEGUENTI SOTTOPROGRAMMI
   ============================================== */

// FUNZIONE RICORSIVA
int is_palindroma(char *parola, int inizio, int fine) {
    if(inizio >= fine){
        return 1;
    }

    if(parola[inizio] == parola[fine]){
        return is_palindroma(parola, inizio + 1, fine - 1);
    }

    return 0;
}

Lista estrai_palindrome(char *nome_file) {
    FILE *fp;
    fp = fopen(nome_file, "r");
    char buffer[51];
    int pal;

    if(fp == NULL){
        return NULL;
    }

    Nodo *coda = NULL;
    Nodo * testa = NULL;
    while (fscanf(fp, "%s", buffer) == 1)
    {
        int len = strlen(buffer);
        pal = is_palindroma(buffer, 0, len - 1);

        if(pal == 1){
            Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));
            nuovo_nodo->parola = (char *) malloc((len + 1) * sizeof(char));
            strcpy(nuovo_nodo->parola, buffer);

            nuovo_nodo->next = testa;
            testa = nuovo_nodo;
        }
    }

    fclose(fp);
    return testa;
}

void free_lista(Lista l) {
    if(l == NULL){
        return ;
    }    

    free_lista(l->next);
    free(l->parola);
    free(l);
}