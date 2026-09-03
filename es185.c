#include <stdio.h>
#define N 10

int main()
{   int src[N];
    int i,n;
    int supporto[N];

    for(i=0; i<N; i++)
		scanf("%d",&src[i]);
   
    do{
	    scanf("%d",&n);	
    }while(n<=0 || n>N);
 
    for(i = 0; i < N; i++){
        int nuovo_indice = (i + n) % N;
        supporto[nuovo_indice] = src[i];
    }

    for(i = 0; i < N; i++){
        src[i] = supporto[i];
        printf("%d ", src[i]);
    }
  
    return 0;
}