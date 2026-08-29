/*
  Si considerino le seguenti definizioni per un Punto2D e una Lista di Punti.
  
  Si scriva la funzione RICORSIVA 'crea_percorso', che riceve due array di 
  interi (uno contenente le coordinate X e uno le coordinate Y) e la loro 
  lunghezza (che è identica per entrambi).
  
  La funzione deve allocare e restituire una nuova lista dove ogni nodo 
  contiene un puntatore a un Punto2D appena allocato.
  Esempio: X = [1, 5], Y = [2, 7] -> Lista: (1,2) -> (5,7) -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct punto {
  int x;
  int y;
} Punto2D;

typedef struct list {
  Punto2D *punto;
  struct list *next;
} List;

/*
  Crea ricorsivamente una lista di Punti a partire da due array paralleli.
*/
List *crea_percorso(int arrX[], int arrY[], int length) {
  if(length == 0){
    return 0;
  }

  List *nuova_lista = malloc(sizeof(List)); 
  Punto2D *punto = malloc(sizeof(Punto2D)); 

  nuova_lista->punto = punto;

  punto->x = arrX[0];
  punto->y = arrY[0];

  nuova_lista->next = crea_percorso(arrX + 1, arrY + 1, length - 1);

  return nuova_lista;
}

// Dealloca la lista E le struct Punto2D in essa contenute
void free_percorso(List *l) {
  if(l == NULL){
    return NULL;
  }

  free_percorso(l->next);
  free(l->punto);
  free(l);
}

int main(void) {
  int X[] = {0, 3, 5, -2};
  int Y[] = {0, 4, 12, 8};
  
  List *percorso = crea_percorso(X, Y, 4);
  
  // ... (Stampa del percorso)
  
  free_percorso(percorso);
  return 0;
}