
#include <stdio.h>
int iterativo(int);
int ricorsiva(int);

int iterativo(int n){
    int acc = 0;
    while (n > 0)
    {   
        acc += n % 10;
        n = n/10;
    }
    return acc;
}

int ricorsiva(int n){
    int acc = 0;
    if(n == 0)
        return 0;

    acc += n%10 + ricorsiva(n/10);
}

int main(){
    int numero;

    printf("Inserire un numero: ");
    scanf("%d", &numero);

    int ri = ricorsiva(numero);
    int it = iterativo(numero);

    printf("Iterativo: %d\n", it);
    printf("Ricorsivo: %d\n", ri);