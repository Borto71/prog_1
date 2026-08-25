/*
  Sia data una lista concatenata di parole pre-costruita nel main.
  
  Una parola si definisce "strettamente crescente" se ogni carattere 
  è successivo al precedente in ordine alfabetico stretto 
  (es. "abc", "aef", "bkm"). Le lettere maiuscole e minuscole 
  hanno codici ASCII diversi, ma per questo esercizio assumiamo 
  che tutte le parole siano in minuscolo.
  
  Completare il programma implementando:

  1. int is_crescente(char *s)
     Funzione RICORSIVA che restituisce 1 se la stringa 's' ha i 
     caratteri in ordine strettamente crescente, 0 altrimenti. 
     Una stringa di 0 o 1 carattere è considerata crescente.

  2. Lista rimuovi_non_crescenti(Lista l)
     Funzione RICORSIVA che prende in input la testa di una lista 
     e rimuove (deallocando nodo e stringa) tutti i nodi che 
     NON contengono una parola strettamente crescente, 
     restituendo la testa della lista modificata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char *parola;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Prototipi
int is_crescente(char *s);
Lista rimuovi_non_crescenti(Lista l);

// Funzioni di utilità (già fornite)
Lista inserisci_coda(Lista l, char *s) {
    Nodo *n = malloc(sizeof(Nodo));
    n->parola = malloc(strlen(s) + 1);
    strcpy(n->parola, s);
    n->next = NULL;
    if (l == NULL) return n;
    Nodo *tmp = l;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = n;
    return l;
}

void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("%s -> ", l->parola);
        l = l->next;
    }
    printf("NULL\n");
}

int main() {
    Lista l = NULL;
    l = inserisci_coda(l, "abc");   // Crescente
    l = inserisci_coda(l, "cane");  // Non crescente (c -> a non va bene)
    l = inserisci_coda(l, "a");     // Crescente
    l = inserisci_coda(l, "bdf");   // Crescente
    l = inserisci_coda(l, "zoo");   // Non crescente (o -> o uguale, non strettamente)
    
    printf("Lista originale: ");
    stampa_lista(l);
    
    l = rimuovi_non_crescenti(l);
    
    printf("Lista filtrata: ");
    stampa_lista(l);
    
    return 0;
}

/* ==============================================
   IMPLEMENTARE I SEGUENTI SOTTOPROGRAMMI
   ============================================== */

int is_crescente(char *s) {
    if(s[0] == '\0' || s[1] == '\0'){
        return 1;
    }

    if(s[0] > s[1]){
        return 0;
    }

    return is_crescente(s + 1);
}

Lista rimuovi_non_crescenti(Lista l) {
    if(l = NULL){
        return NULL;
    }

    l->next = rimuovi_non_crescenti(l->next);

    if(is_crescente(l->parola) == 0){
        Nodo *temp = l->next;
        free(l->parola);
        free(l);

        return temp;
    }

    return l;
}