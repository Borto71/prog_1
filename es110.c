/*
  Sia data una matrice quadrata di interi di dimensione N x N.

  Si dice che la matrice forma un "Quadrato Magico" (nella sua 
  versione semplificata) se la somma degli elementi di ogni riga, 
  la somma degli elementi di ogni colonna e la somma degli elementi 
  di ENTRAMBE le diagonali (principale e secondaria) restituiscono 
  tutte esattamente lo STESSO valore.

  Ad esempio, questa matrice 3x3 è un quadrato magico perché 
  righe, colonne e diagonali sommano tutte a 15:
  8  1  6
  3  5  7
  4  9  2

  Si completi il programma implementando il sottoprogramma:
  int is_quadrato_magico(int M[N][N])

  Il sottoprogramma deve restituire 1 se la matrice è un quadrato 
  magico, e 0 in caso contrario.

  Il main è già fornito e non deve essere modificato.
*/

#include <stdio.h>

#define N 3

// Prototipo
int is_quadrato_magico(int M[N][N]);

int main() {
    int matrice[N][N];
    int i, j;

    printf("Inserisci i %d valori della matrice %dx%d:\n", N*N, N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    if (is_quadrato_magico(matrice) == 1) {
        printf("\nLa matrice E' un Quadrato Magico!\n");
    } else {
        printf("\nLa matrice NON e' un Quadrato Magico.\n");
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

int is_quadrato_magico(int M[N][N]) {
    // INSERISCI QUI IL TUO CODICE
    
}