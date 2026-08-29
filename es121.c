/*
  Si consideri il tipo List, che implementa una lista di interi.
  
  Si implementi la funzione RICORSIVA 'rimuovi_dispari'. 
  La funzione riceve in input il puntatore alla testa di una lista, 
  scorre la lista e RIMUOVE tutti i nodi che contengono un valore dispari.
  
  Per ogni nodo rimosso, la funzione deve deallocare correttamente la memoria 
  tramite free(). La funzione deve restituire il puntatore alla testa 
  della lista così modificata.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} List;

// ... (Si assumano presenti le funzioni append e print_list per il main)

/*
  Rimuove i nodi dispari deallocandoli e restituisce la nuova testa.
  DEVE essere ricorsiva.
*/
List *rimuovi_dispari(List *l) {
  if(l == NULL){
    return NULL;
  }

  if(l->value % 2 == 1){
    List *temp = l->next;

    free(l);

    return rimuovi_dispari(temp);

  }

  l->next = rimuovi_dispari(l->next);
  return l;
}

int main(void) {
  // ... (Lettura e creazione lista come negli es precedenti)
  // l = rimuovi_dispari(l);
  // ... (Stampa e deallocazione finale)
  return 0;
}