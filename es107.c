/*
  Siano date due liste concatenate di numeri interi, entrambe già 
  ordinate in ordine CRESCENTE.

  Si implementi il sottoprogramma RICORSIVO:
  Lista merge_liste(Lista l1, Lista l2)

  Il sottoprogramma deve fondere le due liste in un'unica lista 
  mantenendo l'ordine crescente. 
  
  REGOLE FONDAMENTALI:
  1. La funzione DEVE essere ricorsiva.
  2. NON è consentito allocare nuova memoria (VIETATO usare malloc). 
     Devi semplicemente riorganizzare i puntatori "next" dei nodi 
     già esistenti per incatenarli nel giusto ordine.

  La funzione deve restituire il puntatore alla testa della nuova 
  lista unificata. Il main e le funzioni di supporto sono già forniti.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Prototipi
Lista merge_liste(Lista l1, Lista l2);

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
    Lista lista1 = NULL;
    Lista lista2 = NULL;
    Lista fusa = NULL;

    // Costruiamo la prima lista: 1 -> 4 -> 8 -> 10
    lista1 = inserisci_coda(lista1, 1);
    lista1 = inserisci_coda(lista1, 4);
    lista1 = inserisci_coda(lista1, 8);
    lista1 = inserisci_coda(lista1, 10);

    // Costruiamo la seconda lista: 2 -> 3 -> 8 -> 15 -> 20
    lista2 = inserisci_coda(lista2, 2);
    lista2 = inserisci_coda(lista2, 3);
    lista2 = inserisci_coda(lista2, 8);
    lista2 = inserisci_coda(lista2, 15);
    lista2 = inserisci_coda(lista2, 20);

    printf("Lista 1: ");
    stampa_lista(lista1);

    printf("Lista 2: ");
    stampa_lista(lista2);

    // Chiamata alla funzione da implementare
    fusa = merge_liste(lista1, lista2);

    printf("\nLista Fusa: ");
    stampa_lista(fusa);

    // Basterà una sola free, perché ora i nodi sono tutti in un'unica catena
    free_lista(fusa);

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

Lista merge_liste(Lista l1, Lista l2) {
    if(l1 == NULL){
        return l2;
    }

    if(l2 == NULL){
        return l1;
    }

    if(l1->valore <= l2->valore){
        l1->next = merge_liste(l1->next, l2);

        return l1;
    }

    l2->next = merge_liste(l2->next, l1);
    return l2;
}