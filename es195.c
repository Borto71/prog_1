#include <stdio.h>
#include <stdlib.h>

typedef struct elem_ {
  int num;
  struct elem_ *next;
} elem;

// Prototipo:
elem* equilibra_lista(elem* l);

elem* equilibra_lista(elem* l){
    if(l == NULL){
        return NULL;
    }

    if(l->num < 0){
        elem *temp = l->next;
        free(l);
        return equilibra_lista(temp);
    }

    if(l->num > 0 && l->num % 2 != 0){
        elem *sdoppio = malloc(sizeof(elem));
        elem *temp = l->next;

        sdoppio->num = l->num;
        l->next = sdoppio;

        sdoppio->next = equilibra_lista(temp);

        return l;
    }

    l->next = equilibra_lista(l->next);
    return l;
}