/*
  Si consideri il tipo List che implementa una lista di stringhe.
  
  Si scriva la funzione RICORSIVA 'filtra_lunghezza' che riceve in input 
  la testa di una lista di stringhe e un intero 'min_len'.
  
  La funzione deve allocare e restituire una NUOVA lista che contenga 
  solo i duplicati delle stringhe la cui lunghezza è MAGGIORE O UGUALE 
  a 'min_len'. Le stringhe nella nuova lista devono essere nuove stringhe 
  allocate dinamicamente (non semplici puntatori a quelle vecchie).
  
  Si aggiungano gli #include necessari.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  char *word;
  struct list *next;
} List;

/*
  Alloca e restituisce una nuova lista filtrata.
  DEVE essere ricorsiva.
*/
List *filtra_lunghezza(List *l, int min_len) {
  if(l == NULL){
    return NULL;
  }
  int lunghezza = strlen(l->word);

  if(lunghezza >= min_len){
    List *nuova_lista = malloc(sizeof(List));
    char *parola = malloc(lunghezza + 1);

    nuova_lista->word = parola;
    strcpy(nuova_lista->word, l->word);

    nuova_lista->next = filtra_lunghezza(l->next, min_len);

    return nuova_lista;
  }

  return filtra_lunghezza(l->next, min_len);
}

// Stampa la lista di stringhe
void print_list(List *l) {
  while (l) {
    printf("%s -> ", l->word);
    l = l->next;
  }
  printf("NULL\n");
}

// Dealloca lista e stringhe
void free_list(List *l) {
  if (l == NULL) return;
  free_list(l->next);
  free(l->word);
  free(l);
}

// Funzione main di test
int main(void) {
  // Costruiamo manualmente una lista per il test
  List *l3 = malloc(sizeof(List));
  l3->word = "C"; l3->next = NULL;
  
  List *l2 = malloc(sizeof(List));
  l2->word = "Esame"; l2->next = l3;
  
  List *l1 = malloc(sizeof(List));
  l1->word = "Programmazione"; l1->next = l2;

  printf("Lista originale:\n");
  print_list(l1);

  List *filtrata = filtra_lunghezza(l1, 5);
  printf("\nLista filtrata (lunghezza >= 5):\n");
  print_list(filtrata);

  free_list(filtrata);
  // Nota: l1 non alloca dinamicamente le stringhe in questo main fittizio,
  // quindi non chiamiamo free_list(l1) per evitare errori.
  free(l1); free(l2); free(l3);
  return 0;
}