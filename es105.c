/*
  Sia data una lista concatenata di interi in cui i valori possono 
  ripetersi consecutivamente (es. 7 -> 7 -> 7 -> 4 -> 4 -> 8 -> NULL).

  Si vuole "comprimere" la lista originale creandone una NUOVA 
  (ListaCompressa). Ogni nodo della nuova lista deve contenere il valore 
  e il numero di volte in cui tale valore compare CONSECUTIVAMENTE.

  Ad esempio, la lista originale:
  7 -> 7 -> 7 -> 4 -> 4 -> 8 -> NULL
  
  Deve produrre una nuova lista compressa così formata:
  [Val: 7, Qta: 3] -> [Val: 4, Qta: 2] -> [Val: 8, Qta: 1] -> NULL

  Si implementi il sottoprogramma (che può usare funzioni ausiliarie se necessario):
  ListaCompressa comprimi_lista(Lista l)

  Nota: la lista originale NON deve essere modificata o deallocata. 
  I nodi della nuova lista devono essere allocati dinamicamente ex novo.
*/

#include <stdio.h>
#include <stdlib.h>

/* --- STRUTTURE DATI --- */

// Nodo della lista originale
typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;

// Nodo della lista compressa
typedef struct nodo_compresso {
    int valore;
    int quantita;
    struct nodo_compresso *next;
} NodoCompresso;

typedef NodoCompresso* ListaCompressa;


/* --- PROTOTIPI --- */
ListaCompressa comprimi_lista(Lista l);

Lista inserisci_coda(Lista l, int val);
void stampa_lista_originale(Lista l);
void stampa_lista_compressa(ListaCompressa l);
void free_originale(Lista l);
void free_compressa(ListaCompressa l);

/* =========================================================
   MAIN E FUNZIONI DI UTILITA' (NON MODIFICARE)
   ========================================================= */
int main() {
    Lista l = NULL;
    ListaCompressa compressa = NULL;

    // Costruiamo la lista: 7 -> 7 -> 7 -> 4 -> 4 -> 8
    l = inserisci_coda(l, 7);
    l = inserisci_coda(l, 7);
    l = inserisci_coda(l, 7);
    l = inserisci_coda(l, 4);
    l = inserisci_coda(l, 4);
    l = inserisci_coda(l, 8);

    printf("Lista Originale:\n");
    stampa_lista_originale(l);

    // Chiamata alla funzione da implementare
    compressa = comprimi_lista(l);

    printf("\nLista Compressa:\n");
    stampa_lista_compressa(compressa);

    free_originale(l);
    free_compressa(compressa);

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

void stampa_lista_originale(Lista l) {
    while (l != NULL) {
        printf("%d -> ", l->valore);
        l = l->next;
    }
    printf("NULL\n");
}

void stampa_lista_compressa(ListaCompressa l) {
    while (l != NULL) {
        printf("[Val: %d, Qta: %d] -> ", l->valore, l->quantita);
        l = l->next;
    }
    printf("NULL\n");
}

void free_originale(Lista l) {
    if (l == NULL) return;
    free_originale(l->next);
    free(l);
}

void free_compressa(ListaCompressa l) {
    if (l == NULL) return;
    free_compressa(l->next);
    free(l);
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

ListaCompressa comprimi_lista(Lista l) {
    if (l == NULL) {
        return NULL;
    }

    int contatore = 1;
    Nodo *temp = l->next;

    while (temp != NULL && temp->valore == l->valore) {
        contatore++;
        temp = temp->next;
    }

    NodoCompresso *nuovo = (NodoCompresso *) malloc(sizeof(NodoCompresso));
    nuovo->valore = l->valore;
    nuovo->quantita = contatore;

    nuovo->next = comprimi_lista(temp);
    
    return nuovo;
}
