#include <stdio.h>
#define MAX 4

int simmetrica(int matrice[MAX][MAX]){
    int results = 0;
    for(int i = 0; i < MAX; i++){
        for(int j = i+1; j < MAX; j++){
            if(matrice[i][j] == matrice[j][i]){
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int matrix[MAX][MAX];

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("Insereire il valore [%d][%d] della matrice: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    if(simmetrica(matrix) == 1){
        printf("\nRisultato: La matrice e' SIMMETRICA rispetto alla diagonale principale.\n");
    }else{
        printf("\nRisultato: La matrice NON e' simmetrica.\n");
    }
}