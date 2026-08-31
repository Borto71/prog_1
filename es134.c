#include <stdio.h>

int is_zero(int);

int main(){
	int num;

    scanf("%d", &num);

    int cifra = is_zero(num);

    if(cifra == 1){
        printf("OK\n");
    }

    if(cifra == 0){
        printf("KO\n");
    }
	
    return 0;
}

int is_zero(int numero){
    if(numero == 0){
        return 0;
    }

    int cifra = numero % 10;

    if(cifra == 0){
        return 1;
    }

    return is_zero(numero / 10);
}