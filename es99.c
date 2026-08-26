/*
  Sia data una lista concatenata di numeri interi.
  
  Si implementi il sottoprogramma RICORSIVO:
  Lista raddoppia_multipli(Lista l, int k)

  La funzione deve scorrere la lista e, per ogni nodo il cui valore è 
  un multiplo di k (cioè valore % k == 0), creare un NUOVO nodo con 
  lo stesso valore e inserirlo IMMEDIATAMENTE DOPO il nodo originale.
  
  Esempio:
  Lista originale: 3 -> 4 -> 7 -> 8 -> 12 -> NULL
  Se k = 4, la lista modificata deve diventare:
  3 -> 4 -> 4 -> 7 -> 8 -> 8 -> 12 -> 12 -> NULL

  La funzione deve restituire il puntatore alla testa della lista modificata.
  Non si modifichi il main né le funzioni già fornite.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Prototipi
Lista raddoppia_multipli(Lista l, int k);
void stampa_lista(Lista l);
void free_lista(Lista l);
Lista inserisci_coda(Lista l, int val);

/* =========================================================
   MAIN E FUNZIONI DI UTILITA' (NON MODIFICARE)
   ========================================================= */
int main() {
    Lista l = NULL;
    int k = 4;

    // Costruiamo la lista di test: 3 -> 4 -> 7 -> 8 -> 12
    l = inserisci_coda(l, 3);
    l = inserisci_coda(l, 4);
    l = inserisci_coda(l, 7);
    l = inserisci_coda(l, 8);
    l = inserisci_coda(l, 12);

    printf("Lista originale:\n");
    stampa_lista(l);

    // Chiamata alla funzione da implementare
    l = raddoppia_multipli(l, k);

    printf("Lista dopo il raddoppio dei multipli di %d:\n", k);
    stampa_lista(l);

    free_lista(l);
    return 0;
}

Lista inserisci_coda(Lista l, int val) {
    Nodo *n = malloc(sizeof(Nodo));
    n->valore = val;
    n->next = NULL;
    if (l == NULL) return n;
    Nodo *tmp = l;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = n;
    return l;
}

void stampa_lista(Lista l) {
    while (l != NULL) {
        printf("%d -> ", l->valore);
        l = l->next;
    }
    printf("NULL\n");
}

void free_lista(Lista l) {
    if (l == NULL) return;
    free_lista(l->next);
    free(l);
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

Lista raddoppia_multipli(Lista l, int k) {
    if(l == NULL){
        return NULL;
    }

    if(l->valore % k == 0){
        Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));
        nuovo_nodo->valore = l->valore;
        
        Nodo *resto_elaborato = raddoppia_multipli(l->next, k);
        
        nuovo_nodo->next = resto_elaborato;
        l->next = nuovo_nodo;

        return l;
    } 

    l->next = raddoppia_multipli(l->next, k);
    return l;
}