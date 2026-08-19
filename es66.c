/*
  Completare il programma definendo i seguenti sottoprogrammi:

  1. La funzione RICORSIVA "ha_cifra_dispari" che prende in input un singolo numero
     intero positivo (es. 124) e restituisce 1 se contiene ALMENO una cifra dispari, 
     e 0 altrimenti.
     
     (Suggerimento per la ricorsione: usa l'operatore modulo % 10 per estrarre 
     l'ultima cifra e controllare se è dispari. Se lo è, hai finito! Se non lo è, 
     chiama la funzione stessa passandole il numero diviso per 10 per controllare 
     le cifre rimanenti. Qual è il caso base che fa fermare la ricorsione?)

  2. La funzione "conta_numeri_validi" che prende in input un array di interi e la sua
     lunghezza. La funzione deve scorrere l'array tramite un ciclo e, richiamando la funzione
     "ha_cifra_dispari" per ogni cella, restituire il conteggio totale dei numeri 
     che hanno superato il test (cioè che hanno almeno una cifra dispari).

  Ad esempio, se l'utente inserisce la dimensione 4 e i numeri: 
  24 12 886 70
  Il programma deve stampare 2.
  (Infatti 12 contiene l'1 e 70 contiene il 7, che sono dispari, 
  mentre 24 e 886 contengono solo cifre pari).
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipi delle funzioni da implementare
int conta_numeri_validi(int arr[], int dim);
int ha_cifra_dispari(int num);

// Il main è già completo, non va modificato
int main() {
    int n;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);

    // Allocazione dinamica dell'array
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return -1;
    }

    printf("Inserisci i %d numeri:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Invocazione della funzione principale che andrai a scrivere
    int risultato = conta_numeri_validi(array, n);
    
    printf("Numeri che contengono almeno una cifra dispari: %d\n", risultato);

    // Deallocazione
    free(array);
    
    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI (Scrivi tu il codice)
// =========================================================

int conta_numeri_validi(int arr[], int dim) {
    int res = 0;
    for(int i = 0; i < dim; i++){
        res = res + ha_cifra_dispari(arr[i]);
    }

    return res;
}

// Funzione ricorsiva!
int ha_cifra_dispari(int num) {
    if(num == 0)
        return 0;
    int cifra = num % 10;
    if(cifra % 2 != 0)
        return 1;

    return ha_cifra_dispari(num / 10);
}