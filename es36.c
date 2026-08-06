#include <stdio.h>
#include <string.h>
#define LEN 30

int calcolo_lunghezza(char stringa[]);
// implemento una seconda soluzione senza l'utilizzo della libreria string.h
int calcolo_lunghezza(char stringa[]){
    int cont = 0;
    for(int i = 0; stringa[i] != '\0'; i++){
        cont++;
    }
    return cont;
}

int main(){
    char stringa[LEN];
    printf("Inserire una stringa (lunghezza massima 30): ");
    scanf("%s", stringa);

    int lunghezza = strlen(stringa); // calcolo la lunghezza di una stringa

    printf("La lunghezza della stringa è: %d\n", lunghezza);
    int lunghezza2 = calcolo_lunghezza(stringa);
    printf("La lunghezza della stringa calcolata senza libreria è: %d\n", lunghezza2);
}
