/*
Sia data una matrice quadrata A di interi sicuramente positivi di dimensione N x N.

Per ogni elemento della diagonale principale A[k][k], con 0 <= k < N, si consideri il 
suo intorno diagonale, cioè l’insieme delle celle valide della matrice che:

1. si trovano nella finestra 3 x 3 centrata in A[k][k];
2. non coincidono con A[k][k];
3. non appartengono alla diagonale principale della matrice A.

Un elemento della diagonale principale A[k][k] si dice dominante localmente se 
soddisfa entrambe le seguenti condizioni:

- il suo valore è strettamente maggiore della media aritmetica degli elementi 
  appartenenti al suo intorno diagonale;
- ogni elemento del suo intorno diagonale ha un numero di cifre strettamente 
  minore rispetto al numero di cifre di A[k][k].

Si scriva un programma in linguaggio C che, letta una matrice quadrata di interi positivi, 
individui e stampi tutti gli indici k per cui l’elemento A[k][k] è dominante localmente.
*/

#include <stdio.h>

#define N 4

// Ti consiglio di creare una funzione di supporto per contare le cifre!
int conta_cifre(int numero) {
    if(numero == 0){
        return 0;
    }

    return 1 + conta_cifre(numero / 10);
}

int main(void) {
    int A[N][N];
    int i, j, k;
    int r, c;
    int somma, conta;
    int cifreCentro, cifreElemento;
    int dominante;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    // Per ogni elemento della diagonale principale
    for (k = 0; k < N; k++) {
        int somma= 0;
        int conta = 0;
        int dominante = 1;
         
        for(r = -1; r <= 1; r++){
            for(c = -1; c <= 1; c++){
                if(k+r >= 0 && k+c >= 0 && k+r < N && k+c < N){
                    if(r != c){
                        somma = somma + A[k+r][k+c];
                        conta++;
                        cifreCentro = conta_cifre(A[k][k]);
                        cifreElemento = conta_cifre(A[k+r][k+c]);

                        if(cifreElemento >= cifreCentro){
                            dominante = 0;
                        }
                    }
                }
            }
        }

        float media = (float) somma / conta; 
        if(A[k][k] <= media){
            dominante = 0;
        }
         
        if (dominante) {
            printf("%d ", k);
        }
    }     

    return 0;
}