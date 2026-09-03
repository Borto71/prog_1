#include<stdio.h>
#define N 3
int main(){
    int i, j, m1[N][N];
    int m2[N][N];
	
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &m1[i][j]);
        }
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            int cont = 0;
            for(int r = i - 1; r <= i + 1; r++){
                for(int c = j - 1; c <= j + 1; c++){
                    if(r >= 0 && r < N && c >= 0 && c < N){
                        if(m1[r][c] != 0){
                            cont++;
                        }
                    }
                }
            }
            m2[i][j] = cont;
        }
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%3d", m2[i][j]);
        }
        printf("\n");
    }
	
  return 0;
}