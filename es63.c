#include <stdio.h>
#include <stdlib.h>

int memoriaAllocata; 

int *richiediMemoria(int numeroElementi){
    
    int byteNecessari = numeroElementi * sizeof(int);

    int *memoria = (int *) malloc(byteNecessari);

    if(memoria == NULL){
        printf("\nERRORE: errore nell'allocazione della memoria\n");
        return NULL;
    } else {
        printf("\nSUCCESSO: la memoria è stata allocata correttamente\n");
    }
    
    memoriaAllocata = memoriaAllocata + byteNecessari;

    printf("Ho allocato %d byte di memoria.\nOra la memoria totale in uso è %d byte.\n", byteNecessari, memoriaAllocata);

    return memoria;
}

int main(){
    int *memoria1 = richiediMemoria(22);
    int *memoria2 = richiediMemoria(15);
    
    printf("\nRiepilogo: il programma ha allocato un totale di %d byte.\n", memoriaAllocata);
    
    free(memoria1);
    free(memoria2);
    
    return 0;
}