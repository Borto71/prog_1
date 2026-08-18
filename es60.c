#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Inserire il numero di dimensione dell'array: ");
    scanf("%d", &n);

    int *array = (int *) calloc(n ,sizeof(int));

    if(array == NULL){
        printf("ERRORE: la memoria non è sufficiente\n");
    } else {
        printf("SUCCESSO: la memoria è sufficiente\n");
    }

    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    printf("\nInserire %d numeri interi: ", n);
    for(int i = 0; i < n; i++){
        printf("\nNumero %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nStampa array aggiornato: ");
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    free(array);
}