/*
  Sia data una lista concatenata di numeri interi.

  Si scriva una funzione, chiamata clona_pari, che prende in input
  il puntatore alla testa della lista originale. La funzione deve 
  analizzare la lista e creare dinamicamente una NUOVA lista contenente 
  SOLO i valori pari presenti nella lista di partenza, mantenendo l'ordine 
  in cui compaiono.

  La funzione deve restituire il puntatore alla testa della nuova lista.
  La lista originale NON deve essere modificata in alcun modo.

  ATTENZIONE: La funzione clona_pari DEVE essere ricorsiva e deve
  utilizzare malloc() per creare i nuovi nodi.

  Si implementi anche la funzione dealloca_lista per liberare la memoria 
  di una lista (da chiamare nel main per evitare memory leak).

  Non modificare il main fornito. Si aggiungano gli #include necessari.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int info;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Funzione fornita per l'inserimento in coda (per la lista originale)
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

// IMPLEMENTARE QUESTA FUNZIONE (RICORSIVA)
Lista clona_pari(Lista l) {
    if(l == NULL){
        return NULL;
    }

    if(l->info % 2 == 0){
        Nodo *nuovo_nodo = malloc(sizeof(Nodo));
        nuovo_nodo->info = l->info;

        nuovo_nodo->next = clona_pari(l->next);

        return nuovo_nodo;
    }

    return clona_pari(l->next);
}

// IMPLEMENTARE QUESTA FUNZIONE
void dealloca_lista(Lista l) {
    if(l == NULL){
        return ;
    }

    dealloca_lista(l->next);
    free(l);
}

int main() {
    Lista originale = NULL;
    Lista clonata = NULL;
    int n, val;
    
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    
    if (n > 0) {
        printf("Inserisci i %d numeri:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            originale = inserisci_coda(originale, val);
        }
    }
    
    printf("\nLista originale:\n");
    stampa_lista(originale);
    
    // Chiamata alla funzione da implementare
    clonata = clona_pari(originale);
    
    printf("\nNuova lista (solo numeri pari):\n");
    stampa_lista(clonata);
    
    // Pulizia della memoria di entrambe le liste
    dealloca_lista(originale);
    dealloca_lista(clonata);
    
    return 0;
}