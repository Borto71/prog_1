/*
  Sia data una lista concatenata di numeri interi positivi.

  Si completi il programma implementando i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "somma_cifre_pari(int n)" che riceve 
     un intero positivo e restituisce la SOMMA delle sue cifre che sono PARI.
     Ad esempio:
     - 2548 -> restituisce 14 (2 + 4 + 8)
     - 135  -> restituisce 0 (nessuna cifra pari)
     - 8    -> restituisce 8

  2. Il sottoprogramma "filtra_lista(Nodo *testa, int soglia)" che riceve 
     il puntatore alla testa di una lista concatenata e un intero "soglia".
     Il sottoprogramma deve creare e restituire una NUOVA lista concatenata 
     contenente SOLO i numeri della lista originale la cui somma delle 
     cifre pari è STRETTAMENTE MAGGIORE della soglia.
     I nodi nella nuova lista possono essere inseriti in qualsiasi ordine.

  Nota: La funzione "inserisci_in_testa" è GIA' FORNITA. Ti basterà 
  richiamarla dentro "filtra_lista" per aggiungere un elemento alla 
  tua nuova lista. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

// Prototipi delle funzioni da implementare
int somma_cifre_pari(int n);
Nodo* filtra_lista(Nodo *testa, int soglia);

// =========================================================
// FUNZIONI GIA' FORNITE (NON MODIFICARE)
// =========================================================

// Alloca un nuovo nodo e lo inserisce in testa alla lista
Nodo* inserisci_in_testa(Nodo *testa, int val) {
    Nodo *nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo == NULL) return testa; // sicurezza
    nuovo->valore = val;
    nuovo->next = testa;
    return nuovo;
}

// Stampa la lista
void stampa_lista(Nodo *testa) {
    while (testa != NULL) {
        printf("%d -> ", testa->valore);
        testa = testa->next;
    }
    printf("NULL\n");
}

// Dealloca la lista ricorsivamente
void libera_lista(Nodo *testa) {
    if (testa == NULL) return;
    libera_lista(testa->next);
    free(testa);
}

// Main
int main() {
    Nodo *lista_originale = NULL;
    int n, val, soglia;

    printf("Quanti numeri vuoi inserire nella lista? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserisci numero %d: ", i + 1);
        scanf("%d", &val);
        lista_originale = inserisci_in_testa(lista_originale, val);
    }

    printf("Inserisci la soglia: ");
    scanf("%d", &soglia);

    printf("\nLista originale: ");
    stampa_lista(lista_originale);

    // Chiamata alla tua funzione
    Nodo *lista_filtrata = filtra_lista(lista_originale, soglia);

    printf("Lista filtrata:  ");
    stampa_lista(lista_filtrata);

    libera_lista(lista_originale);
    libera_lista(lista_filtrata);

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int somma_cifre_pari(int n) {
    int cont = 0;

    if(n == 0){
        return 0;
    }

    int cifra = n % 10;
    if(cifra % 2 == 0){
        cont = cont + cifra;
    }

    return cont + somma_cifre_pari(n / 10);
}

Nodo* filtra_lista(Nodo *testa, int soglia) {
    Nodo *nuova_lista = NULL;
    while (testa != NULL)
    {
        int cp = somma_cifre_pari(testa->valore);
        if(cp > soglia){
            nuova_lista = inserisci_in_testa(nuova_lista, testa->valore);
        }
        testa = testa->next;
    }
    return nuova_lista;
}