#include <stdio.h>
# define DIM 5
int main() {
    int matrix [DIM][DIM];
    int ruotata [DIM][DIM];

    // Inserimento della matrice da tastiera
    printf("-- Inserire una matrice %dx%d --\n", DIM, DIM);
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            printf("Inserire il valore [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // calcolo della matrice ruotata di 90 gradi in senso anti orario
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            ruotata[DIM - 1 - j][i] = matrix[i][j];
        }
    }

    // stampo la matrice originale
    printf("-- La matrice originale -- \n");
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    // stampo la matrice ruotata
    printf("-- La matrice ruotata -- \n");
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            printf("%3d", ruotata[i][j]);
        }
        printf("\n");
    }



}