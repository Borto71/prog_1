#include <stdio.h>

int main() {
    int valori[5];
    int max = 0;

    // Lettura dei 5 valori
    printf("Inserisci 5 valori interi non negativi:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &valori[i]);
        
        // Trova il valore massimo per stabilire la profondità dell'istogramma
        if (valori[i] > max) {
            max = valori[i];
        }
    }

    // Stampa la riga iniziale con i numeri inseriti
    for (int i = 0; i < 5; i++) {
        printf("%d ", valori[i]);
    }
    printf("\n");

    for (int col = 0; col < 5; col++) {
        for (int riga = 1; riga <= max; riga++) {
            // Se il valore della colonna è maggiore o uguale alla riga corrente, stampo l'asterisco
            if (valori[col] <= riga) {
                printf("* ");
            } else {
                printf("  "); // Spazi vuoti per mantenere l'incolonnamento corretto
            }
        }
        printf("\n");
    }

    return 0;
}