
#include <stdio.h>

void iterativo(int a[], int dim){
    for(int i = dim-1; i >= 0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int ricorsiva(int a[], int i){
    if(i < 0)
        return 0;
    
    printf("%d ", a[i]);
    return ricorsiva(a, i-1);
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int dim = 5;

    printf("RICORSIVO: \n");
    ricorsiva(arr, dim-1);

    printf("\nITERATIVO: \n");
    iterativo(arr, dim);
}