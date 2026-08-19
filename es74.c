/*
  Un numero intero positivo si dice "alternante" se le sue cifre
  si alternano strettamente tra pari e dispari.
  
  Ad esempio:
  - 2583 è alternante (2 pari, 5 dispari, 8 pari, 3 dispari).
  - 14 è alternante (1 dispari, 4 pari).
  - 7 è alternante (ha una sola cifra, quindi è valido di default).
  - 352 NON è alternante (3 e 5 sono entrambi dispari).
  - 24 NON è alternante (2 e 4 sono entrambi pari).

  Si completi il programma definendo i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "is_alternante(int n)" che riceve
     un intero positivo e restituisce 1 se il numero è alternante,
     0 altrimenti.
     (Suggerimento: usa % 10 per estrarre l'ultima cifra, (n / 10) % 10 
     per la penultima. Qual è il caso base?)

  2. Il sottoprogramma "estrai_alternanti(int *arr, int dim, int *nuova_dim)"
     che riceve l'array dinamico originale, la sua dimensione, e un puntatore
     a un intero ("nuova_dim") in cui salvare la dimensione finale.
     Il sottoprogramma deve:
     - Contare quanti numeri alternanti ci sono in "arr".
     - Salvare questo conteggio nella variabile puntata da "nuova_dim".
     - Se il conteggio è 0, ritornare NULL.
     - Altrimenti, allocare dinamicamente un NUOVO array della dimensione esatta 
       per contenere solo i numeri validi, copiarceli dentro e restituire il 
       puntatore al nuovo array.

  Il main non deve essere modificato.
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipi
int is_alternante(int n);
int* estrai_alternanti(int *arr, int dim, int *nuova_dim);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    int N;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &N);

    if (N <= 0) return 0;

    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione iniziale.\n");
        return -1;
    }

    printf("Inserisci i %d numeri:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int dim_risultato = 0;
    // Chiamata alla funzione. Nota come passiamo l'indirizzo di dim_risultato
    int *risultato = estrai_alternanti(array, N, &dim_risultato);

    printf("\nTrovati %d numeri alternanti:\n", dim_risultato);
    for (int i = 0; i < dim_risultato; i++) {
        printf("%d ", risultato[i]);
    }
    printf("\n");

    free(array);
    if (risultato != NULL) {
        free(risultato);
    }

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int is_alternante(int n) {
    if(n < 10){
        return 1;
    }

    int ultima = n % 10;
    int penultima = (n / 10) % 10;
    if(ultima % 2 == penultima % 2){
        return 0;
    }

    return is_alternante(n / 10);
}

int* estrai_alternanti(int *arr, int dim, int *nuova_dim) {
    // 1. Conta quanti numeri alternanti ci sono
    int cont = 0;
    for(int i = 0; i < dim; i++){
        cont = cont + is_alternante(arr[i]);
    }
    // 2. Salva il conto in *nuova_dim
    *nuova_dim = cont;
    // 3. Se 0, restituisci NULL

    if(cont == 0)
        return NULL;
    // 4. Alloca il nuovo array
    int *array = (int *) malloc(cont * sizeof(int));
    // 5. Ricopia i numeri validi nel nuovo array (occhio agli indici!)
    int j = 0;
    for(int i = 0; i < dim; i++){
        if(is_alternante(arr[i])){
            array[j] = arr[i];
            j++;
        }
    }
    // 6. Ritorna il nuovo array

    return array;
}