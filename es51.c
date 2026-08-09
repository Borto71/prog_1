
#include <stdio.h>
int iterativo(int, int);
int ricorsiva(int, int);

int iterativo(int b, int e){
    int res = 1;
    for(int i = 0; i < e; i++){
        res *= b;
    }

    return res;
}

int ricorsiva(int b, int e){
    if(e == 0)
        return 1;
    return b * ricorsiva(b, e-1);
}

int main(){
    int base, esp;

    printf("Inserire la base: ");
    scanf("%d", &base);

    printf("Inserire l'esponente: ");
    scanf("%d", &esp);

    int it = iterativo(base, esp); 
    int ri = ricorsiva(base, esp);
    printf("Ricorsiva: %d\n", ri);
    printf("Iterativa: %d\n", it);
}