/*
  Sia dato un array bidimensionale di caratteri (che possiamo immaginare 
  come un array di stringhe, dove ogni stringa è lunga al massimo 50 caratteri).

  Completare il programma implementando i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "conta_vocali(char *s)" che riceve una 
     stringa e restituisce il numero totale di vocali (a, e, i, o, u, sia 
     minuscole che maiuscole) presenti.
     (Suggerimento: caso base su '\0'. Nel passo ricorsivo verifica se s[0] 
     è una vocale, somma 1 o 0, e avanza con s + 1).

  2. Il sottoprogramma RICORSIVO "filtra_in_lista(char array[][50], int dim, int indice)"
     che riceve l'array di stringhe, la sua dimensione totale ("dim"), e un 
     "indice" di partenza (chiamato dal main con 0).
     
     Il sottoprogramma deve scorrere l'array RICORSIVAMENTE (vietato usare 
     for o while) e costruire una lista concatenata contenente SOLO le 
     stringhe che hanno STRETTAMENTE PIU' di 2 vocali.
     
     Regole della ricorsione sulle liste:
     - Caso base: se indice == dim, l'array è finito, restituisci NULL.
     - Passo ricorsivo: controlla la stringa in array[indice].
     - Se supera il test (> 2 vocali): 
         a) Alloca un nuovo Nodo.
         b) Alloca dinamicamente il campo "parola" (strlen + 1) e usa strcpy.
         c) Il campo "next" del nodo sarà il risultato della CHIAMATA RICORSIVA 
            su (indice + 1).
         d) Restituisci il nodo.
     - Se NON supera il test: 
         a) NON allocare nulla.
         b) Restituisci semplicemente il risultato della CHIAMATA RICORSIVA 
            su (indice + 1) (che farà da ponte saltando questa parola).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione del Nodo
typedef struct nodo {
    char *parola;
    struct nodo *next;
} Nodo;

// Prototipi
int conta_vocali(char *s);
Nodo* filtra_in_lista(char array[][50], int dim, int indice);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    int N = 5;
    char parole[5][50] = {
        "Cane",         // 2 vocali (falso)
        "Elefante",     // 4 vocali (VERO)
        "Muro",         // 2 vocali (falso)
        "Aiuola",       // 5 vocali (VERO)
        "Bici"          // 2 vocali (falso)
    };

    // Chiamata alla tua funzione (l'indice parte da 0)
    Nodo *lista = filtra_in_lista(parole, N, 0);

    if (lista == NULL) {
        printf("Nessuna parola valida trovata.\n");
    } else {
        printf("Parole valide (piu' di 2 vocali):\n");
        Nodo *temp = lista;
        while (temp != NULL) {
            printf("- %s\n", temp->parola);
            temp = temp->next;
        }
    }

    // Deallocazione sicura
    while (lista != NULL) {
        Nodo *da_cancellare = lista;
        lista = lista->next;
        free(da_cancellare->parola); 
        free(da_cancellare);         
    }

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int conta_vocali(char *s) {
    if(s[0] == '\0'){
        return 0;
    }

    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'){
        return 1 + conta_vocali(s + 1);
    }

    return 0 + conta_vocali(s + 1); 
}

Nodo* filtra_in_lista(char array[][50], int dim, int indice) {
    if(indice == dim){
        return NULL;
    }

    if(conta_vocali(array[indice]) > 2){
        Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));

        int len = strlen(array[indice]);
        nuovo_nodo->parola = (char *) malloc((len + 1) * sizeof(char));
        strcpy(nuovo_nodo->parola, array[indice]);

        nuovo_nodo->next = filtra_in_lista(array, dim, indice + 1);

        return nuovo_nodo;
    }

    return filtra_in_lista(array, dim, indice + 1);
}