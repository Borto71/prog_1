/*
  Sia data una lista concatenata di numeri interi.
  Si scriva una funzione, chiamata estrai_negativi, che prende in input
  il puntatore al puntatore della testa della lista (Lista *l).

  La funzione deve "scollegare" tutti i nodi che contengono un valore 
  strettamente minore di zero dalla lista originale e collegarli tra loro 
  per formare una NUOVA lista, che verrà restituita dalla funzione.
  La lista originale dovrà quindi contenere solo i valori maggiori o uguali a zero.

  ATTENZIONE: 
  - L'operazione DEVE essere distruttiva: non è consentito utilizzare 
    malloc() all'interno della funzione estrai_negativi. 
  - L'ordine relativo dei nodi deve essere mantenuto.

  Si aggiungano gli #include necessari. Non modificare il main fornito.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Funzione fornita per l'inserimento in coda
Lista inserisci_coda(Lista l, int val) {
    Nodo* nuovo = malloc(sizeof(Nodo));
    nuovo->info = val;
    nuovo->next = NULL;
    if (l == NULL) return nuovo;
    Nodo* corr = l;
    while (corr->next != NULL) {
        corr = corr->next;
    }
    corr->next = nuovo;
    return l;
}

// Funzione fornita per la stampa
void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("%d -> ", l->info);
        l = l->next;
    }
    printf("NULL\n");
}

// Funzione fornita per liberare la memoria
void free_list(Lista l) {
    Nodo* temp;
    while (l != NULL) {
        temp = l;
        l = l->next;
        free(temp);
    }
}

// IMPLEMENTARE QUESTA FUNZIONE
Lista estrai_negativi(Lista *l) {
    if(*l == NULL){
        return NULL;
    }

    if((*l)->info < 0){
        Nodo *nodo_negativo = *l;

        *l = (*l)->next;

        Lista altri_negativi = estrai_negativi(l);

        nodo_negativo->next = altri_negativi;
        return nodo_negativo;
    }

    return estrai_negativi(&((*l)->next) );
}

int main() {
    Lista originale = NULL;
    Lista negativi = NULL;
    int n, val;
    
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    
    printf("Inserisci i %d numeri (positivi e negativi):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        originale = inserisci_coda(originale, val);
    }
    
    printf("\nLista iniziale:\n");
    stampa_lista(originale);
    
    // Passiamo l'indirizzo della lista originale
    negativi = estrai_negativi(&originale);
    
    printf("\nLista dopo l'estrazione (solo >= 0):\n");
    stampa_lista(originale);
    
    printf("\nLista dei negativi estratti (< 0):\n");
    stampa_lista(negativi);
    
    free_list(originale);
    free_list(negativi);
    
    return 0;
}