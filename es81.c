/*
  Sia data una matrice statica di interi di dimensione NR x NC.

  Completare il programma implementando i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "is_crescente(int *arr, int dim)" che riceve 
     un array e la sua dimensione. La funzione restituisce 1 se l'array 
     è ordinato in modo STRETTAMENTE CRESCENTE, e 0 altrimenti.
     (Suggerimento: Un array di dimensione 0 o 1 è sempre ordinato (caso base). 
     Per il passo ricorsivo, confronta arr[0] con arr[1]. Se arr[0] >= arr[1], 
     la regola è infranta. Altrimenti, richiama la funzione avanzando di 1).

  2. Il sottoprogramma "estrai_righe(int matrice[NR][NC])" che riceve 
     la matrice. Il sottoprogramma deve:
     - Verificare ogni riga della matrice richiamando la funzione ricorsiva.
     - Se la riga è strettamente crescente, deve creare un NUOVO NODO per 
       una lista concatenata.
     - Il Nodo dovrà memorizzare due cose: l'INDICE della riga (0, 1, ecc.) 
       e la SOMMA TOTALE dei suoi elementi (da calcolare con un ciclo).
     - Inserire il nodo in testa alla lista.
     - Restituire il puntatore alla testa della lista costruita.
*/

#include <stdio.h>
#include <stdlib.h>

#define NR 3
#define NC 4

// Definizione del Nodo della lista
typedef struct nodo {
    int indice_riga;
    int somma_elementi;
    struct nodo *next;
} Nodo;

// Prototipi
int is_crescente(int *arr, int dim);
Nodo* estrai_righe(int matrice[NR][NC]);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    int mat[NR][NC] = {
        {1, 3, 5, 8},   // Crescente! Somma = 17. Indice = 0
        {2, 4, 4, 9},   // NON crescente (4 non è strettamente minore di 4)
        {10, 20, 30, 40} // Crescente! Somma = 100. Indice = 2
    };

    // Chiamata alla tua funzione
    Nodo *lista = estrai_righe(mat);

    if (lista == NULL) {
        printf("Nessuna riga crescente trovata.\n");
    } else {
        printf("Righe crescenti trovate:\n");
        Nodo *temp = lista;
        while (temp != NULL) {
            printf("- Riga %d (Somma elementi: %d)\n", temp->indice_riga, temp->somma_elementi);
            temp = temp->next;
        }
    }

    // Deallocazione della lista
    while (lista != NULL) {
        Nodo *da_cancellare = lista;
        lista = lista->next;
        free(da_cancellare);
    }

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int is_crescente(int *arr, int dim) {
    if(dim <= 1){
        return 1;
    }

    if(arr[0] >= arr[1]){
        return 0;
    }

    return is_crescente(arr + 1, dim - 1);
}

Nodo* estrai_righe(int matrice[NR][NC]) {
    // 1. Crea la testa della lista (inizialmente NULL)
    Nodo *testa = NULL;
    int crescenti;
    int somma = 0;
    // 2. Ciclo for per scorrere le righe della matrice (NR)
    for(int i = 0; i < NR; i++){
        crescenti = is_crescente(matrice[i], NC);

        if(crescenti == 1){ 
            int somma = 0;
            for(int j = 0; j < NC; j++){
                    somma = somma + matrice[i][j];
            }

            Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));
            nuovo_nodo->indice_riga = i;
            nuovo_nodo->somma_elementi = somma;
            nuovo_nodo->next = testa;
            testa = nuovo_nodo;
        }
    }

    return testa;
}