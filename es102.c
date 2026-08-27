/*
  Sia data una lista concatenata che rappresenta la classifica di un campionato.
  Ogni nodo (Squadra) contiene il nome della squadra (stringa allocata 
  dinamicamente) e il punteggio ottenuto.

  Si completi il programma implementando i seguenti sottoprogrammi:

  1. Lista estrai_promosse(Lista l, int soglia)
     Sottoprogramma RICORSIVO che riceve in input la testa della lista originale e 
     un intero "soglia". La funzione deve creare e restituire una NUOVA lista 
     contenente solo le squadre con un punteggio STRETTAMENTE MAGGIORE della soglia.
     Attenzione: i nodi e le stringhe della nuova lista devono essere 
     allocati dinamicamente ex novo (copiando i dati dall'originale). 
     L'ordine degli elementi deve essere mantenuto.

  2. void free_lista(Lista l)
     Sottoprogramma RICORSIVO che dealloca l'intera lista passata come parametro, 
     assicurandosi di deallocare sia la struttura del nodo che la stringa al suo interno.

  Il main e le funzioni di utilità sono già forniti.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct squadra {
    char *nome;
    int punti;
    struct squadra *next;
} Squadra;

typedef Squadra* Lista;

// Prototipi
Lista estrai_promosse(Lista l, int soglia);
void free_lista(Lista l);

// Funzioni di utilità (già fornite)
Lista inserisci_coda(Lista l, char *nome, int punti) {
    Squadra *n = malloc(sizeof(Squadra));
    n->nome = malloc(strlen(nome) + 1);
    strcpy(n->nome, nome);
    n->punti = punti;
    n->next = NULL;
    
    if (l == NULL) return n;
    
    Squadra *tmp = l;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = n;
    return l;
}

void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("[%s: %d punti] -> ", l->nome, l->punti);
        l = l->next;
    }
    printf("NULL\n");
}

int main() {
    Lista campionato = NULL;
    Lista promosse = NULL;
    int soglia = 40;

    campionato = inserisci_coda(campionato, "Leoni", 45);
    campionato = inserisci_coda(campionato, "Tigri", 38);
    campionato = inserisci_coda(campionato, "Aquile", 52);
    campionato = inserisci_coda(campionato, "Lupi", 40); // Uguale alla soglia, non passa
    campionato = inserisci_coda(campionato, "Orsi", 41);

    printf("Classifica completa:\n");
    stampa_lista(campionato);

    promosse = estrai_promosse(campionato, soglia);

    printf("\nSquadre promosse (Punti > %d):\n", soglia);
    stampa_lista(promosse);

    free_lista(campionato);
    free_lista(promosse);

    return 0;
}

/* ==============================================
   IMPLEMENTARE I SEGUENTI SOTTOPROGRAMMI
   ============================================== */

Lista estrai_promosse(Lista l, int soglia) {
    if(l == NULL){
        return NULL;
    }

    if(l->punti > soglia){
        Squadra *nuova_lista = (Squadra *) malloc(sizeof(Squadra));

        nuova_lista->nome = (Squadra *) malloc(strlen(l->nome) + 1);

        strcpy(nuova_lista->nome, l->nome);
        nuova_lista->punti = l->punti;

        nuova_lista->next = estrai_promosse(l->next, soglia);

        return nuova_lista;
    }

    return estrai_promosse(l->next, soglia);
}

void free_lista(Lista l) {
    if(l == NULL){
        return 0;
    }

    free_lista(l->next);
    
    free(l->nome);
    free(l);
}