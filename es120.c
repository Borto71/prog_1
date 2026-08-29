/*
  Si consideri il tipo List, che implementa una lista di interi.
  
  Si implementi la funzione ricorsiva 'espandi_pari' che, data una lista 
  già costruita, la modifica inserendo un nuovo nodo contenente il valore 0 
  immediatamente DOPO ogni nodo che contiene un valore pari.
  
  Ad esempio, se la lista di partenza è:
  1 -> 4 -> 7 -> 2
  
  La funzione modificherà la lista in modo che diventi:
  1 -> 4 -> 0 -> 7 -> 2 -> 0
  
  La funzione non restituisce nulla (modifica la lista in place tramite 
  i puntatori esistenti). La funzione DEVE essere ricorsiva.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} List;

// Funzione fornita per aggiungere in coda (serve al main)
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

/*
  Modifica la lista inserendo uno 0 dopo ogni elemento pari.
  DEVE essere ricorsiva.
*/
void espandi_pari(List *l) {
  if(l == NULL){
    return ;
  }

  if(l->value % 2 == 0){
    List *temp = malloc(sizeof(List));
    temp->value = 0;

    temp->next = l->next;
    l->next = temp;

    espandi_pari(temp->next);
  }

  espandi_pari(l->next);
}

int main(void) {
  List *l = NULL;
  int n, val;
  
  printf("Quanti elementi ha la lista iniziale? ");
  scanf("%d", &n);
  
  printf("Inserisci gli elementi: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    l = append(l, val);
  }

  printf("Lista prima della modifica: \n");
  print_list(l);
  
  espandi_pari(l);
  
  printf("Lista dopo la modifica: \n");
  print_list(l);
  
  free_list(l);
  return 0;
}