#include <stdio.h>
#define MAX 10

void assoluto(int array[], int dimensione){
    for(int i = 0; i < dimensione; i++){
        if(array[i] < 0)
            array[i] = -array[i];
    }
}


int main() {
    int num[MAX];
    int dimensione = MAX;

    // Ciclo di inserimento array
    for(int i = 0; i < MAX; i++){
        printf("\nInserire il %d numero: ", i);
        scanf("%d", &num[i]);
    }
    
    assoluto(num, dimensione);

    printf("\nEcco l'array convertito: ");
    for(int i = 0; i < MAX; i++){
        printf("%d", num[i]);
    }

    printf("\n");
}