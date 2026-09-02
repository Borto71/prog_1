#include<stdio.h> 
#define N 3 
#define M 4 
#define K 3 

int main(){  
    int sum;   
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

        for(k = 0; k < K; k++){
            int P = vec[k];

            if(P < 1 && P > N*M){
                errore = 1;
                break;
            }

            int r = (P - 1) / M;
            int c = (P - 1) % M;

            somma = mat[r][c];
        }

        if(errore == 1){
            printf("-1");
        } else {
            printf("%d", somma);
        }
    }

    if(type == 2){
        int somma = 0;
        int errore = 0;

        for(k = 0; k < K; k++){
            int P = vec[k];

            if(P < 1 && P > N*M){
                errore = 1;
                break;
            }

            int centro_r = (P - 1) / M;
            int centro_c = (P - 1) % M;

            for(int r = centro_r - 1; r < centro_r + 1; r++){
                for(int c = centro_c - 1; c < centro_c + 1; c++){
                    if(r >= 0 && r < N && c >= 0 && c < M){
                        somma += mat[r][c];
                    }
                }

            }
        }

        if(errore == 1){
            printf("-1");
        } else {
            printf("%d", somma);
        }
    }
}

