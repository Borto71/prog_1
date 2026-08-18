#include <stdio.h>
#include <stdlib.h>

int* arraypari(int n){
    int *array = (int *) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        array[i] = i * 2;
    }

    return array;
}

int main(){
    int n;

    printf("Inserire la grandezza dell'array: ");
    scanf("%d", &n);

    int *a1 = arraypari(n);

    if(a1 != NULL){
        for(int i = 0; i < n; i++){
            printf("%d ", a1[i]);
        }
    }

    free(a1);
}