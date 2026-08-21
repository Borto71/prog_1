/*
  Sia dato un array dinamico di strutture "Sensore". Ogni sensore 
  è caratterizzato da un "codice" (intero positivo) e da una "soglia" (da 1 a 9).

  Completare il programma implementando i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "cifra_massima(int n)" che riceve un 
     numero intero positivo e restituisce la CIFRA PIÙ ALTA presente nel numero.
     Ad esempio:
     - 274 -> restituisce 7
     - 91  -> restituisce 9
     - 5   -> restituisce 5
     (Suggerimento: usa n % 10 per l'ultima cifra, calcola la cifra_massima 
     del resto del numero (n / 10), e poi restituisci il maggiore tra i due).

  2. Il sottoprogramma "estrai_critici(Sensore *arr, int dim, int *nuova_dim)" 
     che riceve l'array di sensori e la sua dimensione.
     Il sottoprogramma deve:
     - Contare quanti sensori hanno la cifra massima del proprio "codice" 
       STRETTAMENTE MAGGIORE della propria "soglia".
     - Salvare questo conteggio in "*nuova_dim".
     - Se il conteggio è 0, restituire NULL.
     - Altrimenti, allocare dinamicamente un NUOVO array di Sensori grande 
       quanto il conteggio, copiarci dentro le intere strutture dei sensori 
       validi, e restituire il nuovo array.
*/

#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura
typedef struct {
    int codice;
    int soglia;
} Sensore;

// Prototipi
int cifra_massima(int n);
Sensore* estrai_critici(Sensore *arr, int dim, int *nuova_dim);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    int N = 4;
    
    // Creiamo un array di strutture di prova
    Sensore *sensori = (Sensore*)malloc(N * sizeof(Sensore));
    sensori[0].codice = 123;  sensori[0].soglia = 4; // Max cifra: 3. (3 > 4) Falso
    sensori[1].codice = 801;  sensori[1].soglia = 5; // Max cifra: 8. (8 > 5) VERO
    sensori[2].codice = 22;   sensori[2].soglia = 2; // Max cifra: 2. (2 > 2) Falso
    sensori[3].codice = 495;  sensori[3].soglia = 7; // Max cifra: 9. (9 > 7) VERO
    
    int dim_risultato = 0;
    
    Sensore *critici = estrai_critici(sensori, N, &dim_risultato);

    if (critici == NULL) {
        printf("Nessun sensore critico trovato.\n");
    } else {
        printf("Trovati %d sensori critici:\n", dim_risultato);
        for(int i = 0; i < dim_risultato; i++) {
            printf("- Codice: %d, Soglia: %d\n", critici[i].codice, critici[i].soglia);
        }
        free(critici);
    }

    free(sensori);
    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int cifra_massima(int n) {
    if(n < 10){
        return n;
    }

    int cifra = n % 10;
    int max_resto = cifra_massima(n / 10);

    if(max_resto > cifra){
        return max_resto;
    }

    return cifra;
}

Sensore* estrai_critici(Sensore *arr, int dim, int *nuova_dim) {
    int cont = 0;
    int j = 0;

    for(int i = 0; i < dim; i++){
        if(cifra_massima(arr[i].codice) > arr[i].soglia){
            cont++;
        }
    }

    *nuova_dim = cont;

    if(*nuova_dim == 0){
        return NULL;
    }

    Sensore *nuovo_sensore = (Sensore *) malloc(*nuova_dim * sizeof(Sensore));

    for(int i = 0; i < dim; i++){
        if(cifra_massima(arr[i].codice) > arr[i].soglia){
            nuovo_sensore[j] = arr[i];  
            j++;
        }
    }

    return nuovo_sensore;
}