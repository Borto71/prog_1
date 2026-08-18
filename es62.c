#include <stdio.h>
#include <stdlib.h>

int* allocaETraccia(int dimensione){
    static int contatore;
    contatore++;

    int *array = (int *) malloc(dimensione * sizeof(int));

    if(array == NULL){
        printf("ERRORE!\n");
    } else {
        printf("Allocazione numero %d effettuata con successo (dimensione %d)\n", contatore, dimensione);
    }

    return array;
}

int main(){
    int *p1 = allocaETraccia(3);
    int *p2 = allocaETraccia(17);
    int *p3 = allocaETraccia(71);

    free(p1);
    free(p2);
    free(p3);
}