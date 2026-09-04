#include <stdio.h>
#include <stdlib.h>

typedef struct elem_ {
  int num;
  struct elem_ *next;
} elem;

// Prototipo della funzione:
elem* duplica_pari(elem* l);

elem* duplica_pari(elem* l){
    if(l == NULL){
        return NULL;
    }

    if(l->num % 2 == 0){
        elem *duplicato = malloc(sizeof(elem));
        duplicato = l;
        elem *temp = l->next;

        l->next = duplicato;
        duplicato->next = duplica_pari(temp);

        return l;
    }

    l->next = duplica_pari(l->next);
    return l;
}