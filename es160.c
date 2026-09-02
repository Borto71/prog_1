#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *tail;
} List;

void print_list(List *l) {
  for (List *cursor = l; cursor != NULL; cursor = cursor->tail)
    printf("%i ", cursor->value);

  printf("\n");
}

List *construct_list(int value, List *tail) {
  List *result = malloc(sizeof(List));
  result->value = value;
  result->tail = tail;
  return result;
}

// ritorna la lista ottenuta da l eliminando il suo
// ultimo elemento; si assuma che l non sia vuota;
// è permesso modificare l
List *remove_last_rec(List *l) {
    if(l->tail == NULL){
        free(l);
        return NULL;
    }

    l->tail = remove_last_rec(l->tail);
    return l;
}

// ritorna la lista ottenuta da l eliminando il suo
// ultimo elemento; si assuma che l non sia vuota;
// è permesso modificare l
List *remove_last_ite(List *l) {
    if(l->tail == NULL){
        free(l);
        return NULL;
    }

    List *cursor = l;
    while (cursor->tail->tail != NULL)
    {
        cursor = cursor->tail;
    }

    free(cursor->tail);
    cursor->tail = NULL;

    return l;
}

int main(void) {
  // chiede la lunghezza della lista l1 e la crea di tale lunghezza
  int length;
  scanf("%i", &length);
  List *l1 = NULL;
  while (length > 0)
  	l1 = construct_list(length--, l1);

  print_list(l1);
  l1 = remove_last_rec(l1);
  print_list(l1);

  // chiede la lunghezza della lista l2 e la crea di tale lunghezza
  scanf("%i", &length);
  List *l2 = NULL;
  while (length > 0)
  	l2 = construct_list(length--, l2);

  print_list(l2);
  l2 = remove_last_ite(l2);
  print_list(l2);

  return 0;
}