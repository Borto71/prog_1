/*
  Si consideri il classico tipo List per numeri interi.
  
  Si implementi la funzione RICORSIVA `rimuovi_negativi` che riceve 
  una lista `l` e modifica la lista eliminando e deallocando tutti 
  i nodi che contengono un valore strettamente minore di zero.
  La funzione deve restituire il nuovo puntatore alla testa della lista.
  
  Assicurati di non causare memory leak quando elimini un nodo!
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} List;

// IMPLEMENTA QUESTA FUNZIONE (DEVE ESSERE RICORSIVA)
List *rimuovi_negativi(List *l) {
    if(l == NULL){
        return 0;
    }

    l->next = rimuovi_negativi(l->next);
    if(l->value < 0){
        List *temp = l->next;
        free(l);    
        return temp;
    }

    return l;
}

// (Ometti il main e le funzioni di stampa/inserimento per brevità, 
// concentrati solo sulla logica ricorsiva di rimozione)