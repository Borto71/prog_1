/*
  Sia data una lista concatenata di numeri interi.

  Si implementi il sottoprogramma RICORSIVO:
  Lista inverti_lista(Lista l)

  Il sottoprogramma deve invertire fisicamente l'ordine dei nodi 
  della lista originale. 
  
  Ad esempio, se la lista è:  1 -> 2 -> 3 -> 4 -> NULL
  Deve essere modificata in:  4 -> 3 -> 2 -> 1 -> NULL

  REGOLE FONDAMENTALI:
  1. La funzione DEVE essere ricorsiva.
  2. NON è consentito allocare nuova memoria (VIETATO usare malloc) 
     né deallocare nodi. Devi riorganizzare i puntatori "next" 
     dei nodi già esistenti.

  La funzione deve restituire il puntatore alla NUOVA testa della lista 
  (che corrisponde a quello che era l'ultimo nodo della lista originale).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Prototipi
Lista inverti_lista(Lista l);

// Funzioni di utilità
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

/* =========================================================
   MAIN (NON MODIFICARE)
   ========================================================= */
int main() {
    Lista l = NULL;

    // Costruiamo la lista: 10 -> 20 -> 30 -> 40
    l = inserisci_coda(l, 10);
    l = inserisci_coda(l, 20);
    l = inserisci_coda(l, 30);
    l = inserisci_coda(l, 40);

    printf("Lista originale: \n");
    stampa_lista(l);

    // Chiamata alla funzione da implementare
    l = inverti_lista(l);

    printf("\nLista invertita: \n");
    stampa_lista(l);

    free_lista(l);

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

Lista inverti_lista(Lista l) {
    if(l == NULL){
        return l;
    }

    Lista nuova_testa = inverti_lista(l->next);

    l->next->next = l;
    l->next = NULL;

    return nuova_testa;
}