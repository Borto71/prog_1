/*
  Si consideri il tipo List, che implementa una lista concatenata di interi.

  Si implementino le due funzioni:
  - lista_positivi_quadrati: prende in input un array di interi e la sua 
    lunghezza. Alloca e restituisce una nuova lista che contiene SOLO i numeri 
    strettamente positivi presenti nell'array. Inoltre, il valore salvato 
    nella lista non deve essere il numero originale, ma il suo quadrato.
    Questa funzione DEVE essere ricorsiva.
    (Es. array: [-2, 3, 0, 4] -> lista: 9 -> 16).
    
  - free_list: dealloca tutta la memoria allocata per la lista passata 
    come argomento.

  Non si modifichi il resto del codice. Si aggiungano gli #include necessari.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *next;
} List;

// stampa la lista l a video
void print_list(List *l) {
  while (l) {
    printf("%d ", l->value);
    l = l->next;
  }
  printf("\n");
}

/*
  Costruisce ricorsivamente la lista contenente i quadrati dei soli
  numeri positivi presenti nell'array.
*/
List *lista_positivi_quadrati(int arr[], int length) {
    
    if(length == 0){
        return 0;
    }

    if(arr[length] > 0){
        List *nuova_lista = malloc(sizeof(List));

        nuova_lista->value = arr[length];
        nuova_lista->next = lista_positivi_quadrati(arr + 1, length - 1);

        return nuova_lista;
    }

    return lista_positivi_quadrati(arr + 1, length - 1);
}

/*
  Dealloca tutta la memoria della lista
*/
void free_list(List *l) {
  if(l == NULL){
    return ;
  }

  free_list(l->next);
  free(l);
}

int main(void) {
  int length;
  printf("Quanti numeri vuoi inserire? ");
  scanf("%i", &length);
  
  if (length <= 0) return 0;

  int *arr = malloc(length * sizeof(int));
  printf("Inserisci i numeri: ");
  for (int pos = 0; pos < length; pos++) {
    scanf("%i", &arr[pos]);
  }

  List *l = lista_positivi_quadrati(arr, length);
  printf("La lista risultante è: ");
  print_list(l);
  
  free_list(l);
  free(arr);
  return 0;
}