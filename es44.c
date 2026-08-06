#include <stdio.h>

// Dichiarazione dei sottoprogrammi
int potenza(int, int);
int calcola_radice(int, int, int *);

int potenza(int base, int esponente) {
    int risultato = 1;
    for(int i = 0; i < esponente; i++) {
        risultato = risultato * base;
    }
    return risultato;
}

int calcola_radice(int numero, int grado, int *radice_intera) {
    int tentativo = 1;
    
    while (potenza(tentativo, grado) < numero) {
        tentativo++;
    }
    
    if (potenza(tentativo, grado) == numero) {
        *radice_intera = tentativo;
        return 1; // Radice precisa
    } else {
        *radice_intera = tentativo - 1;
        return 0; // Radice approssimata (con resto)
    }
}

int main() {
    int num, grado;
    int res_radice; // Modificato in int
    int esatta;     // Per salvare il risultato della funzione radice (1 o 0)

    printf("Inserire il numero di cui calcolare la radice: ");
    scanf("%d", &num);

    printf("Inserire il grado della radice: ");
    scanf("%d", &grado);

    // Chiamiamo la funzione. Ci restituirà 1 (esatta) o 0 (non esatta), 
    // e salverà la radice in res_radice
    esatta = calcola_radice(num, grado, &res_radice);

    // Gestione dell'output
    if (esatta == 1) {
        printf("\nLa radice e' INTERA e PRECISA. Il risultato e': %d\n", res_radice);
    } else {
        printf("\nLa radice NON e' precisa. La radice intera approssimata per difetto e': %d\n", res_radice);
    }

    return 0;
}