/*
  Sia data una lista concatenata di numeri interi.
  Si scriva una funzione, chiamata rimuovi_duplicati, che prende in input 
  il puntatore alla testa della lista.

  La funzione deve analizzare la lista e rimuovere i nodi in modo che non 
  vi siano valori uguali consecutivi. Ad esempio, se la lista originale è:
  8 -> 8 -> 8 -> 3 -> 5 -> 5 -> 8 -> NULL
  
  La funzione dovrà modificarla in:
  8 -> 3 -> 5 -> 8 -> NULL
  
  (Nota: l'ultimo 8 viene mantenuto perché non è consecutivo ai primi).

  I nodi scartati devono essere deallocati fisicamente tramite la funzione free().
  La funzione deve restituire il puntatore alla testa della lista modificata.

  ATTENZIONE: La funzione rimuovi_duplicati DEVE essere ricorsiva.
  
  Non modificare il main fornito. Si aggiungano gli #include necessari.
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

// Funzione fornita per liberare la memoria a fine programma
void free_list(Lista l) {
    Nodo* temp;
    while (l != NULL) {
        temp = l;
        l = l->next;
        free(temp);
    }
}

// IMPLEMENTARE QUESTA FUNZIONE (RICORSIVA)
Lista rimuovi_duplicati(Lista l) {
    if(l == NULL){
        return NULL;
    }

    if(l->next == NULL){
        return l;
    }

    if(l->info == l->next->info){
        Lista *temp = l->next;
        free(l);

        return rimuovi_duplicati(temp);
    }

    l->next = rimuovi_duplicati(l->next);
    return l;
}

int main() {
    Lista l = NULL;
    int n, val;
    
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    
    if (n > 0) {
        printf("Inserisci i %d numeri:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            l = inserisci_coda(l, val);
        }
    }
    
    printf("\nLista originale:\n");
    stampa_lista(l);
    
    l = rimuovi_duplicati(l);
    
    printf("\nLista senza duplicati consecutivi:\n");
    stampa_lista(l);
    
    free_list(l);
    
    return 0;
}