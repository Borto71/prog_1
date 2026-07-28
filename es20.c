#include <stdio.h>
# define DIM 5
int main() {
    int matrix [DIM][DIM];
    int simmetrica = 1;

    // Inserimento della matrice da tastiera
    printf("-- Inserire una matrice %dx%d --\n", DIM, DIM);
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            printf("Inserire il valore [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Controllo che sia simmetrica rispetto alla diagonale principale
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            if(matrix[i][j] != matrix[j][i]){ // controllo con la transposta
                simmetrica = 0;
            }
        }
    }

    if(simmetrica == 1){
        printf("\nLa matrice è simmetrica rispetto alla diagonale");
    }else{
        printf("\nLa matrice non è simmetrica rispetta alla digaonale");
    }
}