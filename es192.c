#include <stdio.h>
#include <stdlib.h>

typedef struct elem_ {
  int num;
  struct elem_ *next;
} elem;

// Prototipo della funzione che devi scrivere:
elem* inserisci_zero_dopo_dispari(elem* l);

elem* inserisci_zero_dopo_dispari(elem* l){
    if(l == NULL){
        return NULL;
    }
    
    if(l->num % 2 == 0){
        l->next = inserisci_zero_dopo_dispari(l->next);

        return l;
    }

    elem *nuovo_elemento = malloc(sizeof(elem));
    nuovo_elemento->num = 0;

    elem *temp = l->next;

    l->next = nuovo_elemento;

    nuovo_elemento->next = inserisci_zero_dopo_dispari(temp);\

    return l;
}