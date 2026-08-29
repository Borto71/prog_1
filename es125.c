/*
  Sia data una matrice quadrata M di interi positivi di dimensione N x N.

  Per ogni elemento della DIAGONALE SECONDARIA M[i][j] (ovvero dove la somma
  degli indici di riga e colonna è pari a N - 1), si consideri il suo 
  "intorno a croce". L'intorno a croce di una cella è definito come l'insieme 
  delle celle valide della matrice che si trovano immediatamente sopra, sotto, 
  a destra e a sinistra rispetto a M[i][j].

  Un elemento della diagonale secondaria si dice "punto di snodo" se soddisfa 
  ENTRAMBE le seguenti condizioni:
  
  1. Il suo valore è strettamente MINORE della somma degli elementi appartenenti 
     al suo intorno a croce;
  2. Nell'intorno a croce ci sono ESATTAMENTE due valori pari.

  Si scriva un programma in linguaggio C che, letta una matrice quadrata 
  di interi positivi, individui e stampi le coordinate (riga, colonna) 
  e il valore di tutti i "punti di snodo".

  Ad esempio, data una matrice N=4:
  10  3   5   8
  2   4   14  1
  9   12  7   3
  11  6   2   20

  Gli elementi sulla diagonale secondaria sono:
  - M[0][3] = 8   (intorno: 5, 1) -> Somma = 6, Pari = 0
  - M[1][2] = 14  (intorno: 5, 4, 1, 7) -> Somma = 17, Pari = 1 (solo il 4)
  - M[2][1] = 12  (intorno: 4, 9, 7, 6) -> Somma = 26, Pari = 2 (il 4 e il 6)
  - M[3][0] = 11  (intorno: 9, 6) -> Somma = 15, Pari = 1 (solo il 6)

  L'unico "punto di snodo" è M[2][1] = 12, poiché 12 < 26 e ha esattamente due 
  vicini pari. Il programma dovrà stampare: 
  Trovato snodo in (2, 1) con valore 12
*/

#include <stdio.h>

#define N 4

int main(void) {
    int M[N][N];
    int i, j;
    
    // Lettura della matrice
    printf("Inserisci i %d elementi della matrice %dx%d:\n", N*N, N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    
    printf("\nPunti di snodo trovati:\n");
    
    for(int i = 0; i < N; i++){
        int j = N - 1 - i;
        int somma = 0;
        int pari = 0;

        if(i-1 >= 0){
            somma += M[i-1][j];
            if(M[i-1][j] % 2 == 0){
                pari++;
            }
        }

        if(i+1 <= N){
            somma += M[i+1][j];
            if(M[i+1][j] % 2 == 0){
                pari++;
            }
        }

        if(j+1 <= N){
            somma += M[i][j+1];
            if(M[i][j+1] % 2 == 0){
                pari++;
            }
        }

        if(j-1 >= 0){
            somma += M[i][j-1];
            if(M[i][j-1] % 2 == 0){
                pari++;
            }
        }

        if(M[i][j] < somma && pari == 2){
            printf("Coordinate: [%d, %d] Valore: %d \n", i, j, M[i][j]);
        }

    }
    return 0;
}