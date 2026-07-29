#include <stdio.h>

int fattoriale(int);

int main() {
    int numero;
    int risultato;

    // Inserimento del numero da tastiera 
    printf("Inserire il numero di cui si vuole calcolare il fattoriale: ");
    scanf("%d", &numero);

    risultato = fattoriale(numero); // chiamata alla funzione

    printf ("\nIl risultato del fattoriale è: %d\n", risultato);
}

int fattoriale(int num){
    int risultato = 1;
    for(int i = 1; i <= num; i++){
        risultato = risultato * i;
    }

    return risultato;
}