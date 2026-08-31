#include <stdio.h>
#include <string.h>
#define D 10
int main(){
	char a1[D], a2[D];
	int i;
    int j = 0;
	
	for(i=0; i<D; i++)
		scanf("%c",&a1[i]);
    
    for(i = 0; i < D; i++){
        if(a1[i] >= '0' && a1[i] <= '9'){
            a1[i] = '*';
        }
    }

    for(i = 0; i < D; i++){
        if((a1[i] >= 'a' && a2[i] <= 'z') || (a1[i] >= 'A' && a2[i] <= 'Z')){
            a2[j] = a1[i];
            j++;
        }
    }
	
    for(i=0; i<D; i++)
		printf("%c ", a1[i]);

    printf("\n");

    for(i=0; i<j; i++)
		printf("%c ", a2[i]);
	
	return 0;

}