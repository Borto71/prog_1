#include <stdio.h>
#define R 3
#define C 4

int main(){
	int m[R][C];
	int i, j;

	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			scanf("%d",&m[i][j]);
    
	for(i = 0; i < R; i++){
        int pari = 0;
        for(j = 0; j < C; j++){;
            if(m[i][j] % 2 == 0){
                pari ++;
            }

            if(pari == 4){
                printf("%d ", i);
            }
        }
        
    }

	return 0;
}