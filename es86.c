/*
  Sia dato il tipo List, che implementa una lista di numeri interi.

  Si implementino le seguenti funzioni:
  
  - `filtra_positivi`: riceve come parametro una lista `l` e alloca e 
    restituisce una NUOVA lista contenente SOLO i valori di `l` che sono 
    strettamente maggiori di zero, mantenendo l'ordine originale. 
    Questa funzione DEVE essere ricorsiva.
    (Es. Se input è: -5 -> 10 -> 0 -> 3 -> -2, l'output è: 10 -> 3).
    
  - `free_list`: dealloca correttamente tutta la memoria di una lista
    passata come parametro.

  Il resto del programma (compresa la funzione di inserimento in coda fornita 
  per comodità di test) non deve venire modificato. Si aggiungano gli #include.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} List;

void print_list(List *l) {
  for (List *cursor = l; cursor != NULL; cursor = cursor->next)
    printf("%d -> ", cursor->value);
  printf("NULL\n");
}

// Funzione helper per creare la lista iniziale (già implementata)
List *insert_tail(List *l, int val) {
  if (l == NULL) {
    List *new_node = malloc(sizeof(List));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
  }
  l->next = insert_tail(l->next, val);
  return l;
}

// DEVE ESSERE RICORSIVA e allocare una NUOVA lista
List *filtra_positivi(List *l) {
  if(l == NULL){
    return NULL;
  }

  if(l->value > 0){
    List *nuova_lista = (List *) malloc(sizeof(List));
    nuova_lista->value = l->value;

    nuova_lista->next = filtra_positivi(l->next);

    return nuova_lista;
  }

  return filtra_positivi(l->next);
}

// Dealloca la memoria della lista
void free_list(List *l) {
  if(l == NULL){
    return ;
  }

  free_list(l->next);
  free(l);
}

int main(void) {
  List *originale = NULL;
  int n, val;
  
  printf("Quanti numeri vuoi inserire? ");
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++) {
      scanf("%d", &val);
      originale = insert_tail(originale, val);
  }
  
  printf("Lista originale: ");
  print_list(originale);
  
  List *filtrata = filtra_positivi(originale);
  
  printf("Lista filtrata (solo positivi): ");
  print_list(filtrata);
  
  free_list(originale);
  free_list(filtrata);
  
  return 0;
}