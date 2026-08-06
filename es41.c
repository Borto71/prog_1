#include <stdio.h>

int calcola(int, int, int *, int *);

int calcola(int num1, int num2, int *min, int *max){
    if(num1 > num2){
        *max = num1;
        *min = num2;
    }else{
        *max = num2;
        *min = num1;
    }
}

int main(){
    int primo, secondo;
    int min, max;
    
    // Inserimento del primo numero
    printf("Inserire il primo numero: ");
    scanf("%d", &primo);

    // Inserimento secondo numero 
    printf("\nInserire il secondo numero: ");
    scanf("%d", &secondo);

    calcola(primo, secondo, &min, &max);

    printf("\nIl valore minimo tra %d e %d è: %d\n", primo, secondo, min);
    printf("\nIl valore massimo tra %d e %d è: %d\n", primo, secondo, max);
}