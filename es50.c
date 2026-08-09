
#include <stdio.h>
int iterativo(int);
int ricorsiva(int);

int iterativo(int n){
    int p1, p2, res;
    for(int i = 1; i <= n; i++){
        // boh no idea veramente
    }
}

int ricorsiva(int n){
    int res = 0;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    res += ricorsiva(n-1) + ricorsiva(n-2);

    return res;
}

int main(){
    int numero;

    printf("Inserire un numero: ");
    scanf("%d", &numero);

    // iterativo(numero); 
    int ri = ricorsiva(numero);
    printf("%d\n", ri);

}