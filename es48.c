#include <stdio.h>
int iterativo(int);
int ricorsiva(int);

int iterativo(int n){
    int res = 0;
    for(int i=1; i<=n; i++){
        res += i;
    }

    return res;
}

int ricorsiva(int n){
    int res = 0;
    if(n == 0)
        return 0;
    
    res = n + ricorsiva(n-1);

    return res;
}

int main(){
    int numero;

    printf("Inserire un numero: ");
    scanf("%d", &numero);

    int it = iterativo(numero);
    int ri = ricorsiva(numero);

    printf("\nRisultato iterativo è: %d", it);
    printf("\nRisultato ricorsivo è: %d", ri);

}