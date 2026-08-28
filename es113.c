/*
  Sia data una lista concatenata che memorizza una sequenza di numeri interi.

  Si scriva una funzione, chiamata rimuovi_multipli, che prende in input 
  il puntatore alla testa della lista e un intero k. 
  La funzione deve rimuovere dalla lista (deallocando fisicamente la memoria) 
  tutti e soli i nodi il cui campo informativo è un multiplo di k. 
  La funzione deve restituire il puntatore alla testa della lista modificata.
  
  ATTENZIONE: La funzione rimuovi_multipli DEVE essere ricorsiva.

  Si implementi inoltre la funzione free_list per deallocare l'intera lista 
  al termine del programma, in modo da non avere memory leak.

  Non modificare il main fornito. Si aggiungano gli #include necessari.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
    int info;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Funzione di utilità per inserire in coda (già fornita)
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

// Funzione di utilità per stampare la lista (già fornita)
void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("%d -> ", l->info);
        l = l->next;
    }
    printf("NULL\n");
}

// IMPLEMENTARE LA FUNZIONE RICORSIVA
Lista rimuovi_multipli(Lista l, int k) {
    if(l == NULL){
        return NULL;
    }

    if(l->info % k == 0){
        Lista *prossimo = l->next;
        free(l);

        return rimuovi_multipli(prossimo, k);
    }

    l->next = rimuovi_multipli(l->next, k);
    return l;
}

// IMPLEMENTARE LA FUNZIONE DI DEALLOCAZIONE
void free_list(Lista l) {
    if(l == NULL){
        return ;
    }

    free_list(l->next);
    free(l);
}

int main() {
    Lista l = NULL;
    int n, val, k;
    
    printf("Quanti numeri vuoi inserire nella lista? ");
    scanf("%d", &n);
    
    printf("Inserisci i %d numeri:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        l = inserisci_coda(l, val);
    }
    
    printf("Inserisci il valore k per i multipli da rimuovere: ");
    scanf("%d", &k);
    
    printf("Lista originale: \n");
    stampa_lista(l);
    
    // Chiamata alla funzione da implementare
    l = rimuovi_multipli(l, k);
    
    printf("Lista dopo la rimozione dei multipli di %d: \n", k);
    stampa_lista(l);
    
    // Chiamata alla funzione di pulizia
    free_list(l);
    
    return 0;
}