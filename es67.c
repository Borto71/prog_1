/*
  ESERCIZIO: Gestione di un magazzino tramite array di struct e ricorsione.

  Passaggi da completare:

  1. Definisci una struct chiamata "Prodotto" (prima del main e dei prototipi).
     Deve contenere tre campi:
     - codice (intero)
     - prezzo (float)
     - quantita (intero)

  2. Implementa la funzione: 
     struct Prodotto* alloca_e_leggi_catalogo(int dim)
     Questa funzione deve:
     - Allocare dinamicamente un array di 'dim' elementi di tipo struct Prodotto.
     - Verificare se l'allocazione ha avuto successo (se fallisce, stampa un errore e restituisci NULL).
     - Usare un ciclo per chiedere all'utente di inserire codice, prezzo e quantità 
       per ogni prodotto.
     - Restituire il puntatore all'array.

  3. Implementa la funzione RICORSIVA:
     float valore_totale_ricorsivo(struct Prodotto arr[], int dim)
     Questa funzione deve calcolare il valore totale del magazzino.
     Il valore di un singolo prodotto è (prezzo * quantita).
     
     Suggerimento per la ricorsione su array:
     - CASO BASE: Se la dimensione (dim) arriva a 0, significa che non ci sono più 
       prodotti da valutare. Restituisci 0.0.
     - PASSO RICORSIVO: Calcola il valore dell'ULTIMO prodotto nell'array (che si trova 
       all'indice dim - 1) e sommalo al risultato della chiamata ricorsiva alla funzione 
       stessa, passandole lo stesso array ma con dimensione ridotta (dim - 1).
*/

#include <stdio.h>
#include <stdlib.h>

struct Prodotto
{
    int codice;
    float prezzo;
    int quantita;
};




// Prototipi delle funzioni da implementare
struct Prodotto* alloca_e_leggi_catalogo(int dim);
float valore_totale_ricorsivo(struct Prodotto arr[], int dim);


// Il main è già completo, usalo come guida per capire come vengono chiamate le funzioni
int main() {
    int n;

    printf("Quanti prodotti vuoi inserire nel catalogo? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Inserisci un numero valido maggiore di zero.\n");
        return 1;
    }

    // 1. Invochiamo la funzione che alloca e riempie l'array
    struct Prodotto *catalogo = alloca_e_leggi_catalogo(n);

    // Se la funzione ha restituito NULL, c'è stato un errore di memoria
    if (catalogo == NULL) {
        return -1; 
    }

    // 2. Calcoliamo il valore totale usando la funzione ricorsiva
    float valore_magazzino = valore_totale_ricorsivo(catalogo, n);
    
    printf("\nIl valore totale di tutti i prodotti in magazzino e': %.2f euro\n", valore_magazzino);

    // 3. Deallocazione della memoria (come sempre, fondamentale!)
    free(catalogo);
    printf("Memoria liberata. Programma terminato.\n");

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

struct Prodotto* alloca_e_leggi_catalogo(int dim){
    struct Prodotto *arrayProdotto = (struct Prodotto*) malloc(dim * sizeof(struct Prodotto));

    if(arrayProdotto == NULL){
        printf("\nERRORE: la memoria non è stata allocata");
    } else {
        printf("\nSUCCESSO: la memoria è stata allocata con successo");
    }

    printf("\nInserire i vari campi del Prodotto");
    for(int i = 0; i < dim; i++){
        printf("\nInserire il codice del prodotto: ");
        scanf("%d", &arrayProdotto[i].codice);

        printf("\nInserire il prezzo del prodotto %d: ", arrayProdotto[i].codice);
        scanf("%f", &arrayProdotto[i].prezzo);

        printf("\nInserire la qunatità di prodotti %d: ", arrayProdotto[i].codice);
        scanf("%d", &arrayProdotto[i].quantita);
    }

    return arrayProdotto;
}

float valore_totale_ricorsivo(struct Prodotto arr[], int dim){
    int valore = 0;

    if(dim == 0)
        return 0.0;

    return valore = (arr[dim -1].prezzo * arr[dim-1].quantita) + valore_totale_ricorsivo(arr, dim-1);
}