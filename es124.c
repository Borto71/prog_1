/*
  Si consideri il tipo List, che implementa una lista di interi.
  
  Si assuma che la lista passata come parametro sia SEMPRE ordinata in 
  senso crescente (dal numero più piccolo al più grande).
  
  Si implementi la funzione RICORSIVA 'inserisci_ordinato' che riceve
  la testa della lista e un intero 'val'. La funzione deve allocare un 
  nuovo nodo contenente 'val' e inserirlo nella lista in modo tale 
  che la lista RISULTI ANCORA ORDINATA in senso crescente.
  
  La funzione deve restituire la testa della lista aggiornata.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} List;

/*
  Inserisce 'val' mantenendo l'ordinamento.
  DEVE essere ricorsiva.
*/
List *inserisci_ordinato(List *l, int val) {
  // IMPLEMENTARE (DEVE ESSERE RICORSIVA)
}

void print_list(List *l) {
  while (l) {
    printf("%d -> ", l->value);
    l = l->next;
  }
  printf("NULL\n");
}

void free_list(List *l) {
  if (l == NULL) return;
  free_list(l->next);
  free(l);
}

int main(void) {
  List *l = NULL;
  
  // Inseriamo numeri non in ordine, ma la funzione 
  // li posizionerà correttamente!
  l = inserisci_ordinato(l, 10);
  l = inserisci_ordinato(l, 3);
  l = inserisci_ordinato(l, 7);
  l = inserisci_ordinato(l, 1);
  l = inserisci_ordinato(l, 20);

  printf("Lista ordinata:\n");
  print_list(l);
  
  free_list(l);
  return 0;
}