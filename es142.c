#include <stdio.h>
#define N 10

int main(){ 
    int src[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &src[i]);
    }

    int sinistra = 0;
    int destra = N - 1;

    while (sinistra < destra)
    {
        if(src[sinistra] % 2 != 0){
            sinistra++;
        }

        else if(src[destra] % 2 == 0){
            destra--;
        }

        else {
            int temp = src[sinistra];
            src[sinistra] = src[destra];
            src[destra] = temp;
            sinistra++;
            destra--;
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d ", src[i]);
    }

return(0); 
  
}
