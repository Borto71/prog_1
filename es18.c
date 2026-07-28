#include <stdio.h>
# define DIM 8
int main() {
    int matrix [DIM][DIM];
    int identita = 1;
    
    // Inserimento della matrice
    printf("-- Inserire i valori della matrice quadrata --\n");
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            printf("Inserire il valore della matrice [%d][%d] \n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // controllo che sia una matrice identita
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            if(i == j){
                if(matrix[i][j] != 1){
                    identita = 0;
                }else{
                    if(matrix[i][j] != 0){
                        identita = 0;
                    }
                }
            }
        }
    }


    if(identita == 1){
        printf("La matrice è una matrice identità (%d) \n", identita);
    }else{
        printf("La matrice non è una matrice identità (%d) \n", identita);
    }
}