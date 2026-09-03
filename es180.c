#include<stdio.h>

int main(){
    int numero;

    scanf("%d", &numero);

    if(numero % 3 == 0){
        printf("Multiplo di 3");
    }

    if(numero % 5 == 0){
        printf("Multiplo di 5");
    }
    
    return 0;
}