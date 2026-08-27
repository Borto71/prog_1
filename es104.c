/*
  Sia data una matrice quadrata di interi di dimensione N x N (con N pari).
  Si vuole "comprimere" questa matrice in una nuova matrice di 
  dimensione M x M, dove M = N / 2.

  La compressione avviene analizzando blocchi non sovrapposti di 
  dimensione 2x2. Per ogni blocco 2x2 della matrice originale, 
  il valore da inserire nella matrice compressa è il MASSIMO 
  tra i 4 valori del blocco.

  Esempio di mappatura:
  L'elemento compressa[0][0] sarà il massimo del blocco 2x2 formato da:
  originale[0][0], originale[0][1], originale[1][0], originale[1][1].
  
  L'elemento compressa[0][1] valuterà il blocco successivo:
  originale[0][2], originale[0][3], originale[1][2], originale[1][3].

  Si implementi il sottoprogramma:
  void comprimi_matrice(int originale[N][N], int compressa[M][M])
  
  Il main è già fornito e non deve essere modificato.
*/

#include <stdio.h>

#define N 6
#define M (N/2)

// Prototipo
void comprimi_matrice(int originale[N][N], int compressa[M][M]);

int main() {
    int originale[N][N];
    int compressa[M][M];
    int i, j;

    printf("Inserisci i 36 valori della matrice 6x6:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &originale[i][j]);
        }
    }

    comprimi_matrice(originale, compressa);

    printf("\nMatrice Compressa 3x3 (Max Pooling):\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            printf("%3d ", compressa[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

void comprimi_matrice(int originale[N][N], int compressa[M][M]) {
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            int max = originale[i*2][j*2];

            if(originale[i*2][(j*2) + 1] > max){
                max = originale[i*2][(j*2) + 1];
            }

            if(originale[(i*2) + 1][j*2] > max){
                max = originale[(i*2) + 1][j*2];
            }

            if(originale[(i*2) + 1][(j*2) + 1] > max){
                max = originale[(i*2) + 1][(j*2) + 1];
            }

            compressa[i][j] = max;
        }
    }
    
}