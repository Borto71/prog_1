#include <stdio.h>
#include <stdlib.h>

typedef struct elem_ {
  int num;
  struct elem_ *next;
} elem;

// Prototipo della funzione:
elem* elimina_multipli(elem* l, int k);

elem* elimina_multipli(elem* l, int k){
    if(l == NULL){
        return NULL;
    }

    if(l->num % k != 0){
        l->next = elimina_multipli(l->next, k);
        return l;
    }

    elem *nuova_lista = l->next;
    free(l);

    return elimina_multipli(nuova_lista, k);
}