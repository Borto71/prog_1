#include<stdio.h>

int main(){
  int n, d, type, i, j;

  // Acquisizione dati
  scanf("%d", &n);
  
  int m1[n][n];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m1[i][j]=0;
    }
  }
  
  scanf("%d", &d);
  scanf("%d", &type);

  if(type == 0){
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            m1[n - 2 - r][c + 1] = 1;
        }
    }
  }
  
  if(type == 1){
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(r + c < d){
                m1[n - 2 -r][1 + c] = 1;
            }
        }
    }
  }

  if(type == 2){
    for(int k = 1; k <= n-d; k++){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                m1[k + r][k + c] = k;
            }
        }
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ", m1[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}