/*
  Sia data una matrice statica di interi di dimensione NR x NC.

  Si completi il programma implementando i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "somma_dispari(int *arr, int dim)" che riceve 
     in input un array monodimensionale e la sua dimensione. La funzione deve 
     restituire la SOMMA di tutti i numeri DISPARI presenti nell'array.
     (Suggerimento: il caso base è quando dim arriva a 0. Per il passo ricorsivo, 
     puoi usare arr[0] e poi chiamare la funzione passando (arr + 1, dim - 1) 
     come hai fatto nell'esercizio delle date!).

  2. Il sottoprogramma "indici_righe_valide(int matrice[NR][NC], int *nuova_dim)" 
     che riceve la matrice e un puntatore a intero.
     Il sottoprogramma deve:
     - Calcolare la somma dei numeri dispari per OGNI RIGA della matrice, 
       richiamando obbligatoriamente la funzione ricorsiva. 
       (Ricorda: in C, "matrice[i]" rappresenta l'intero array della riga "i").
     - Contare quante righe hanno una somma dei numeri dispari STRETTAMENTE MAGGIORE di 0.
     - Salvare questo conteggio in "*nuova_dim".
     - Se il conteggio è 0, restituire NULL.
     - Altrimenti, allocare dinamicamente un array di interi grande quanto il conteggio,
       salvarci dentro gli INDICI delle righe valide, e restituire l'array.

  Esempio: 
  Se la riga 1 ha somma dispari = 9 e la riga 3 ha somma dispari = 18, 
  il nuovo array conterrà [1, 3] e *nuova_dim sarà 2.
*/

#include <stdio.h>
#include <stdlib.h>

#define NR 4
#define NC 5

// Prototipi
int somma_dispari(int *arr, int dim);
int* indici_righe_valide(int matrice[NR][NC], int *nuova_dim);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    // Inizializziamo una matrice di prova direttamente nel codice
    int mat[NR][NC] = {
        {2, 4, 6, 8, 10},  // Somma dispari = 0 (nessun dispari)
        {1, 2, 3, 4, 5},   // Somma dispari = 1+3+5 = 9 (> 0, riga valida. Indice: 1)
        {0, 0, 0, 0, 0},   // Somma dispari = 0
        {7, 10, 12, 11, 2} // Somma dispari = 7+11 = 18 (> 0, riga valida. Indice: 3)
    };

    int dim_risultato = 0;
    
    // Chiamata alla tua funzione
    int *righe = indici_righe_valide(mat, &dim_risultato);

    if (righe == NULL) {
        printf("Nessuna riga valida trovata.\n");
    } else {
        printf("Trovate %d righe valide. Indici delle righe: ", dim_risultato);
        for(int i = 0; i < dim_risultato; i++) {
            printf("%d ", righe[i]);
        }
        printf("\n");
        free(righe); // Deallocazione
    }

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int somma_dispari(int *arr, int dim) {
    int disp = 0;

    if(dim == 0){
        return 0;
    }

    if(arr[0] % 2 == 0){
        return 0 + somma_dispari(arr + 1, dim);
    } else {
        disp = disp + arr[0];
    }
    
    dim--;
    return disp + somma_dispari(arr + 1, dim);
}

int* indici_righe_valide(int matrice[NR][NC], int *nuova_dim) {
    int cont = 0;
    int j = 0;
    for(int i = 0; i < NR; i++){
        if(somma_dispari(matrice[i], NR) > 0){
            cont++;
        }
    }

    *nuova_dim = cont;

    if(*nuova_dim == 0){
        return NULL;
    }

    int *nuovo_array = (int *) malloc(*nuova_dim * sizeof(int));

    for(int i = 0; i < NC; i++){
        if(somma_dispari(matrice[i], NC) > 0){
            nuovo_array[j] = i;
            j++;
        }
    }
    return nuovo_array;
}