#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("Inserire un numero che sarà la grandezza dell'array salvato in memoria: ");
    scanf("%d", &n);

    int *array = (int *) malloc(n * sizeof(int));

    if(array == NULL){
        printf("ERRORE: memoria insufficiente\n");
        return 1;
    } else {
        printf("SUCCESSO: memoria sufficiente\n");
    }

    free(array);
}