#include <stdio.h>
#define D 10
int main(){
	char a1[D];
    char a2[D];
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
         if((a1[i] >= 'a' && a1[i] <= 'z') || (a1[i] >= 'A' && a1[i] <= 'Z')){
            a2[j] = a1[i];
            j++;
         }
    }

    a2[j] = '\0';

    for(i = 0; i < D; i++){
        printf("%c ", a1[i]);
    }

    printf("\n");

    for(i = 0; i < j; i++){
        printf("%c ", a2[i]);
    }
	return 0;
}