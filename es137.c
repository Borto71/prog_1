#include<stdio.h>
#define N 3
#define M 4
#define K 3
int main(){
  int mat[N][M];
  int vec[K];
  int type;
  int i, j, k;
  
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      scanf("%d",&mat[i][j]);
    }
  }

  for(k=0;k<K;k++){
    scanf("%d",&vec[k]);
  }
  
  scanf("%d",&type);
  
  if(type == 1){
    int somma = 0;
    int errore = 0;

    // Scorro l'array vec per leggere i K "indici segreti"
    for(k = 0; k < K; k++){
        int P = vec[k]; // Es: leggo 7

        // Controllo che il numero sia valido (tra 1 e 12)
        if(P < 1 || P > (N * M)){
            errore = 1;
            break; 
        }

        // Trasformo il numero (es: 7) nelle due coordinate
        int r = (P - 1) / M;
        int c = (P - 1) % M;

        // Sommo il valore della matrice in quella posizione
        somma += mat[r][c];
    }

    if(errore == 1){
        printf("-1\n");
    } else {
        printf("%d\n", somma);
    }
  }

if(type == 2){
    int somma = 0;
    int errore = 0;

    // 1. Scorro l'array vec per prendere i K centri delle sottomatrici
    for(k = 0; k < K; k++){
        int P = vec[k];

        // 2. Controllo errori: il numero P deve essere valido
        if(P < 1 || P > (N * M)){
            errore = 1;
            break;
        }

        // 3. Spacchetto P per trovare il "centro" della mia finestra 3x3
        int centro_r = (P - 1) / M;
        int centro_c = (P - 1) % M;

        // 4. Creo la finestra 3x3 attorno al centro (r e c vanno da -1 a +1 rispetto al centro)
        for(int r = centro_r - 1; r <= centro_r + 1; r++){
            for(int c = centro_c - 1; c <= centro_c + 1; c++){
                
                // 5. IL FILTRO MAGICO: Sommo solo se la cella esiste davvero dentro i confini N e M
                if(r >= 0 && r < N && c >= 0 && c < M){
                    somma += mat[r][c];
                }
            }
        }
    }

    // 6. Stampa finale
    if(errore == 1){
        printf("-1\n");
    } else {
        printf("%d\n", somma);
    }
  }
}