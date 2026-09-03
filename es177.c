#include <stdio.h>

int conta_cifre(int);

int main(){
	int num;
    scanf("%d", &num);

    if(conta_cifre(num) == 1){
        printf("OK");
    } else {
        printf("KO");
    }

	return 0;
}

int conta_cifre(int numero){
    if(numero == 0){
        return 0;
    }

    int cifra = numero % 10;
    if(cifra == 0){
        return 1;
    }

    return 0 + conta_cifre(numero / 10);
}
