#include <stdio.h>
int iterativo(int);
int ricorsiva(int);

int iterativo(int n){
    while(n > 0){
        printf("%d\n", n);
        n--;
    }

    printf("Liftoff\n");
}

int ricorsiva(int n){
    if(n == 0)
        printf("Liftoff\n");
    else{
        printf("%d\n", n);
        ricorsiva(n-1);
    }
}

int main(){
    int numero;

    printf("Inserire un numero: ");
    scanf("%d", &numero);

    iterativo(numero); 
    ricorsiva(numero);

}