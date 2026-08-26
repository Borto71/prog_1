/*
  Sia data una matrice di interi di dimensione 4x5.

  Un elemento della matrice M[i][j] è detto "punto di sella" se verifica 
  CONTEMPORANEAMENTE queste due condizioni:
  1. È il valore STRETTAMENTE MAGGIORE di tutti gli altri elementi della sua riga (i).
  2. È il valore STRETTAMENTE MINORE di tutti gli altri elementi della sua colonna (j).

  Si scriva un programma in C che, letta la matrice da tastiera, trovi e 
  stampi a video le coordinate (riga, colonna) e il valore di tutti i punti di sella.

  Completare il programma implementando la funzione:
  int is_punto_sella(int M[NR][NC], int r, int c)
  che restituisce 1 se l'elemento in posizione (r, c) è un punto di sella, 
  e 0 altrimenti.
*/

#include <stdio.h>

#define NR 4
#define NC 5

/* Prototipo della funzione */
int is_punto_sella(int M[NR][NC], int r, int c);

int main() {
    int matrice[NR][NC];
    int i, j;
    int trovati = 0;

    printf("Inserisci i valori della matrice 4x5:\n");
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("Punti di sella trovati:\n");
    
    // Scansione della matrice alla ricerca dei punti di sella
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            
            if (is_punto_sella(matrice, i, j) == 1) {
                printf("Elemento %d alle coordinate (%d, %d)\n", matrice[i][j], i, j);
                trovati++;
            }
            
        }
    }

    if (trovati == 0) {
        printf("Nessun punto di sella presente nella matrice.\n");
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

int is_punto_sella(int M[NR][NC], int r, int c) {
    int punto_sella = 1;

    for(int i = 0; i < NR; i++){
        if(r != i){
            if(M[r][c] >= M[i][c]){
                punto_sella = 0;
            }
        }
    }

    for(int j = 0; j < NC; j++){
        if(c != j){
            if(M[r][c] <= M[r][j]){
                punto_sella = 0;
            }
        }
    }

    return punto_sella; 
}