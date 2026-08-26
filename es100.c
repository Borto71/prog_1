/*
  Sia data una lista concatenata di numeri interi.
  
  Si implementi il sottoprogramma RICORSIVO:
  Lista rimuovi_duplicati(Lista l)

  La funzione deve scorrere la lista e rimuovere i nodi in modo che 
  non ci siano mai due nodi consecutivi con lo stesso valore. 
  Quando si incontrano elementi identici adiacenti, deve esserne 
  conservato solo il primo.
  
  Esempio:
  Lista originale: 5 -> 5 -> 5 -> 2 -> 8 -> 8 -> 5 -> NULL
  Lista modificata: 5 -> 2 -> 8 -> 5 -> NULL
  
  La funzione deve restituire il puntatore alla testa della lista 
  modificata e deallocare correttamente la memoria dei nodi eliminati.
  Non si modifichi il main né le funzioni già fornite.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Prototipi
Lista rimuovi_duplicati(Lista l);
void stampa_lista(Lista l);
void free_lista(Lista l);
Lista inserisci_coda(Lista l, int val);

/* =========================================================
   MAIN E FUNZIONI DI UTILITA' (NON MODIFICARE)
   ========================================================= */
int main() {
    Lista l = NULL;

    // Costruiamo la lista: 5 -> 5 -> 5 -> 2 -> 8 -> 8 -> 5
    l = inserisci_coda(l, 5);
    l = inserisci_coda(l, 5);
    l = inserisci_coda(l, 5);
    l = inserisci_coda(l, 2);
    l = inserisci_coda(l, 8);
    l = inserisci_coda(l, 8);
    l = inserisci_coda(l, 5); // Questo non è consecutivo ai primi 5, quindi rimane

    printf("Lista originale:\n");
    stampa_lista(l);

    // Chiamata alla funzione da implementare
    l = rimuovi_duplicati(l);

    printf("Lista senza duplicati consecutivi:\n");
    stampa_lista(l);

    free_lista(l);
    return 0;
}

Lista inserisci_coda(Lista l, int val) {
    Nodo *n = malloc(sizeof(Nodo));
    n->valore = val;
    n->next = NULL;
    if (l == NULL) return n;
    Nodo *tmp = l;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = n;
    return l;
}

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
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

Lista rimuovi_duplicati(Lista l) {
    if(l == NULL){
        return NULL;
    }

    if(l->valore == l->next->valore){
        Nodo *cancellare = l->next;

        l->next = cancellare->next;

        free(cancellare);

        return rimuovi_duplicati(l);
    }

    l->next = rimuovi_duplicati(l->next);

    return l;
}