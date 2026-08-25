/*
  Sia definito un tipo struct punto { int x; int y; }.
  Sia data una lista concatenata di punti (Lista).

  Si implementi la funzione RICORSIVA `filtra_quadrante` che riceve 
  in input un array di struct Punto e la sua dimensione. 
  La funzione deve creare e restituire una lista concatenata contenente 
  SOLO i punti che si trovano nel primo quadrante (cioè con x > 0 e y > 0). 
  
  La lista risultante deve mantenere l'ordine in cui i punti compaiono 
  nell'array originale.

  Non si modifichi il main né le funzioni di stampa e deallocazione già 
  fornite. Si aggiungano eventuali #include se necessari.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct punto {
    int x;
    int y;
} Punto;

typedef struct nodo {
    Punto p;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Prototipi
Lista filtra_quadrante(Punto arr[], int dim);
void stampa_lista(Lista l);
void free_lista(Lista l);

int main() {
    Punto array_punti[] = {
        {3, 4}, {-1, 5}, {2, 8}, {0, 2}, {7, 1}, {-3, -4}
    };
    int dim = 6;

    Lista l = filtra_quadrante(array_punti, dim);

    printf("Punti nel primo quadrante:\n");
    stampa_lista(l);

    free_lista(l);
    return 0;
}

void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("(%d, %d) ", l->p.x, l->p.y);
        l = l->next;
    }
    printf("\n");
}

void free_lista(Lista l) {
    if (l == NULL) return;
    free_lista(l->next);
    free(l);
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

Lista filtra_quadrante(Punto arr[], int dim) {
    if(dim == 0){
        return 0;
    }

    if(arr[0].x > 0 && arr[0].y > 0){
        Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));
        nuovo_nodo->p = arr[0];

        nuovo_nodo->next = filtra_quadrante(arr + 1, dim - 1);
        
        return nuovo_nodo;
    }

    return  filtra_quadrante(arr + 1, dim - 1);
}