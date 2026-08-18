#include <stdio.h>
#include <stdlib.h>

int calcolaSomma(int *, int );

int calcolaSomma(int *array, int dimensione){
    int somma = 0;
    for(int i = 0; i < dimensione; i++){
        somma = somma + array[i];
    }

    return somma;
}

int main(){
    int n;

    printf("Inserire una dimension per l'array: ");
    scanf("%d", &n);

    int *array = (int *) malloc(n * sizeof(int));

    if(array == NULL){
        printf("\nERRORE: la memoria non è stata allocata");
    } else {
        printf("\nSUCCESSO: la memoria è stata allocata");
    }

    printf("\nInserire i valori dell'array");
    for(int i = 0; i < n; i++){
        printf("\nInserire il valore %d: ", i+1);
        scanf("%d", &array[i]);
    }

    int risultato = calcolaSomma(array, n);
    printf("\nLa somma di tutti i valori dell'array è: %d", risultato);

    free(array);
}