#include <stdio.h>

int fattoriale(int);

int main() {
    int n1, n2;
    int binomiale;

    // Inserimento del numero da tastiera 
    printf("Inserire il primo numero di cui si vuole calcolare il coeff. binomiale: ");
    scanf("%d", &n1);
    printf("Inserire il secondo numero di cui si vuole calcolare il coeff. binomiale: ");
    scanf("%d", &n2);

    binomiale = fattoriale(n1) / (fattoriale(n2) * (fattoriale(n1 - n2)));

    printf("\nIl risultato del coeff. binomiale è: %d\n", binomiale);
}

int fattoriale(int num){
    int risultato = 1;
    for(int i = 1; i <= num; i++){
        risultato = risultato * i;
    }

    return risultato;
}