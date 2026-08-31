/*
  Si consideri il tipo List, che implementa una lista concatenata di interi.

  Si scriva la funzione RICORSIVA 'sdoppia_multipli'. 
  La funzione riceve in input il puntatore alla testa di una lista e la 
  modifica (in-place) in questo modo: per ogni nodo che contiene un valore 
  multiplo di 3, la funzione deve inserire un NUOVO NODO immediatamente 
  successivo, contenente il valore del nodo originale diviso per 3.

  Ad esempio, data la lista iniziale:
  9 -> 4 -> 12 -> 5 -> NULL

  La funzione modificherà la lista come segue:
  - 9 è multiplo di 3, quindi inserisce 3.
  - 4 non è multiplo di 3, non fa nulla.
  - 12 è multiplo di 3, inserisce 4.
  - 5 non è multiplo di 3.
  
  Lista finale:
  9 -> 3 -> 4 -> 12 -> 4 -> 5 -> NULL

  Si presti attenzione a non processare i nuovi nodi appena inseriti!
  La funzione non restituisce nulla (void).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} List;

/*
  Funzione ricorsiva che sdoppia i nodi multipli di 3.
*/
void sdoppia_multipli(List *l) {
  if(l == NULL){
    return ;
  }

  if(l->value % 3 == 0){
    List *nuovo_nodo = malloc(sizeof(List));

    nuovo_nodo->value = l->value / 3;
    nuovo_nodo->next = l->next;
    l->next = nuovo_nodo;

    sdoppia_multipli(l->next);
  } else {
    sdoppia_multipli(l->next);
    }
}


// --- FUNZIONI DI SUPPORTO NON DA MODIFICARE ---

// Aggiunge un nodo in coda alla lista
List *append(List *l, int val) {
  if (l == NULL) {
    List *nuovo = malloc(sizeof(List));
    nuovo->value = val;
    nuovo->next = NULL;
    return nuovo;
  }
  l->next = append(l->next, val);
  return l;
}

// Stampa la lista a video
void print_list(List *l) {
  while (l) {
    printf("%d -> ", l->value);
    l = l->next;
  }
  printf("NULL\n");
}

// Dealloca l'intera lista
void free_list(List *l) {
  if (l == NULL) return;
  free_list(l->next);
  free(l);
}

int main(void) {
  List *l = NULL;
  
  // Costruzione della lista di test
  l = append(l, 9);
  l = append(l, 4);
  l = append(l, 12);
  l = append(l, 5);

  printf("Lista prima della modifica:\n");
  print_list(l);
  
  sdoppia_multipli(l);
  
  printf("\nLista dopo la modifica:\n");
  print_list(l);
  
  free_list(l);
  return 0;
}