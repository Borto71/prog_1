/*

Sia data una matrice quadrata A di interi sicuramente positivi di dimensione N x N.

Per ogni elemento della diagonale principale A[k][k], con 0 <= k < N, si consideri il suo intorno diagonale, cioè l’insieme delle celle valide della matrice che:

si trovano nella finestra 3 x 3 centrata in A[k][k];
non coincidono con A[k][k];
non appartengono alla diagonale principale della matrice A.

In altre parole, l’intorno diagonale di A[k][k] contiene tutti gli elementi adiacenti orizzontalmente, verticalmente o diagonalmente a A[k][k], 
escludendo però l’elemento centrale e gli eventuali elementi che si trovano anch’essi sulla diagonale principale della matrice A.

Un elemento della diagonale principale A[k][k] si dice dominante localmente se soddisfa entrambe le seguenti condizioni:

il suo valore è strettamente maggiore della media aritmetica degli elementi appartenenti al suo intorno diagonale;
ogni elemento del suo intorno diagonale ha un numero di cifre strettamente minore rispetto al numero di cifre di A[k][k].

Si scriva un programma in linguaggio C che, letta una matrice quadrata di interi positivi, individui e stampi tutti gli indici k 
per cui l’elemento A[k][k] è dominante localmente.

Si consideri ad esempio:

A = 

125	8	3	4
6	12	99	2
5	7	312	4
1	3	80	90


Gli indici dominanti sono: 0, 2. Infatti, per l'elemento A[0][0] = 125, il suo intorno diagonale è formato dagli elementi 6 e 8, con media = 7 < 125 e numero di cifre pari a 1 < 3. Al contrario, per l'elemento A[1][1] = 12, gli elementi dell'interno diagonale sono 8, 3, 6, 99, 5, 7, con media = 21.33 > 12; inoltre, 99 ha lo stesso numero di cifre di 12, quindi non è dominante.

*/

#include <stdio.h>

int conta_cifre(int);

#define N 4

int main(void) {
    int A[N][N];
    int i, j, k;
    int r, c;
    int somma, conta;
    int cifreCentro, cifreElemento;
    int valore;
    int dominante;


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    for (k = 0; k < N; k++) {
        somma = 0;
        conta = 0;
        dominante = 1;

        for(r = k - 1; r <= k + 1; r++){
            for(c = k - 1; c <= k + 1; k++){
                if(r >= 0 && r < N && c >= 0 && c < N && r != k && c != k && r != c){
                    somma += A[r][c];
                    conta++;
                    cifreElemento = conta_cifre(A[r][c]);
                    cifreCentro = conta_cifre(A[k][k]);
                }
            }
        }

        float media = (float) somma / conta;

        if(A[k][k] <= media && cifreCentro > cifreElemento){
            dominante = 0;
        }
         
        if (dominante == 1) {
            printf("%d ", k);
        }
    }     

    return 0;
}

int conta_cifre(int numero){
    if(numero == 0){
        return 0;
    }

    if(numero <= 9){
        return 1;
    }

    return 1 + conta_cifre(numero / 10);
}