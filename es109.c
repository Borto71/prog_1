/*
  Sia dato un file di testo contenente una sequenza di numeri interi, 
  separati da spazi o ritorni a capo.

  Si completi il programma implementando i seguenti sottoprogrammi:

  1. Lista inserisci_ordinato(Lista l, int val)
     Sottoprogramma RICORSIVO che riceve in input la testa di una lista 
     (ordinata in senso CRESCENTE) e un nuovo intero "val". 
     La funzione deve allocare un nuovo nodo e inserirlo nella posizione 
     corretta in modo che la lista RISULTI ANCORA ORDINATA.
     La funzione restituisce la testa della lista aggiornata.

  2. Lista crea_lista_ordinata(char *nome_file)
     Sottoprogramma che apre il file specificato, legge tutti i numeri 
     interi in esso contenuti e, per ciascuno di essi, utilizza la funzione 
     'inserisci_ordinato' per aggiungerli alla lista. 
     Restituisce la testa della lista finale. Se il file non esiste, 
     restituisce NULL.

  Il main e le funzioni di supporto sono già forniti.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Prototipi
Lista inserisci_ordinato(Lista l, int val);
Lista crea_lista_ordinata(char *nome_file);
void stampa_lista(Lista l);
void free_lista(Lista l);

/* =========================================================
   MAIN (NON MODIFICARE)
   ========================================================= */
int main() {
    char nome_file[100];
    Lista l = NULL;

    printf("Inserisci il nome del file di testo: ");
    scanf("%99s", nome_file);

    l = crea_lista_ordinata(nome_file);

    if (l == NULL) {
        printf("Errore di apertura file o file vuoto.\n");
    } else {
        printf("Lista costruita in ordine crescente:\n");
        stampa_lista(l);
    }

    free_lista(l);
    return 0;
}

// Funzioni di utilità
void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("%d -> ", l->valore);
        l = l->next;
    }
    printf("NULL\n");
}

void free_lista(Lista l) {
    if (l == NULL) return;
    free_lista(l->next);
    free(l);
}

/* ==============================================
   IMPLEMENTARE I SEGUENTI SOTTOPROGRAMMI
   ============================================== */

Lista inserisci_ordinato(Lista l, int val) {
    if(l == NULL || val <= l->valore){
        Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));
        nuovo_nodo->valore = val;

        nuovo_nodo->next = l;

        return nuovo_nodo;
    }

    l->next = inserisci_ordinato(l->next, val);

    return l;
}

Lista crea_lista_ordinata(char *nome_file) {
    FILE *fin;
    int buffer;
    Nodo *testa = NULL;

    fin = fopen(nome_file, "r");

    if(fin == NULL){
        return NULL;
    }

    while (fscanf(fin, "%d", &buffer) == 1)
    {
        testa = inserisci_ordinato(testa, buffer);
    }

    fclose(fin);

    return testa;
}