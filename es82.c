/*
  Un file di testo contiene una serie di parole (massimo 50 caratteri ciascuna), 
  una per riga.

  Completare il programma implementando i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "is_palindroma(char *parola, int inizio, int fine)" 
     che verifica se la porzione di stringa compresa tra gli indici "inizio" e "fine" 
     si legge allo stesso modo da sinistra a destra e viceversa. Restituisce 1 se è 
     palindroma, 0 altrimenti.
     (Suggerimento: il caso base si ha quando inizio >= fine. Nel passo ricorsivo, 
     se parola[inizio] != parola[fine] hai finito e ritorni 0. Altrimenti, richiama 
     la funzione avanzando 'inizio' e arretrando 'fine').

  2. Il sottoprogramma "estrai_palindrome(char *nomefile)" che apre il file in lettura.
     Il sottoprogramma deve:
     - Leggere le parole una per una.
     - Se una parola è palindroma, creare un NUOVO NODO da inserire IN TESTA a una 
       lista concatenata.
     - Il nodo deve contenere un puntatore a carattere (char *) per la stringa.
     - ATTENZIONE: devi ALLOCARE DINAMICAMENTE lo spazio per la stringa nel nodo 
       e copiarci dentro la parola trovata (ricorda il terminatore '\0'!).
     - Restituire il puntatore alla testa della lista. Se il file non esiste, restituire NULL.
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
int is_palindroma(char *parola, int inizio, int fine);
Nodo* estrai_palindrome(char *nomefile);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    char nomefile[100];
    
    printf("Inserisci il nome del file: ");
    scanf("%s", nomefile);

    Nodo *lista = estrai_palindrome(nomefile);

    if (lista == NULL) {
        printf("Nessuna parola trovata o file inesistente.\n");
    } else {
        printf("Parole palindrome trovate:\n");
        Nodo *temp = lista;
        while (temp != NULL) {
            printf("- %s\n", temp->parola);
            temp = temp->next;
        }
    }

    // Deallocazione sicura (dealloco prima la stringa, poi il nodo)
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

int is_palindroma(char *parola, int inizio, int fine) {
    if(inizio >= fine){
        return 1;
    }

    if(parola[inizio] != parola[fine]){
        return 0;
    }

    return is_palindroma(parola, inizio + 1, fine - 1);
} 

Nodo* estrai_palindrome(char *nomefile) {
    // 1. Apri il file. Se errore -> return NULL
    FILE *fp;

    fp = fopen(nomefile, "r");

    if(fp == NULL){
        return NULL;
    }

    char buffer[51];
    Nodo *testa = NULL;
    // 2. Prepara la testa della lista (NULL) e un buffer (es. char buffer[51])

    while (fscanf(fp, "%s", buffer) == 1)
    {
        int lunghezza = strlen(buffer);
        int palindorma = is_palindroma(buffer, 0 ,lunghezza - 1);

        if(palindorma == 1){
            Nodo *nuovo_nodo = (Nodo *) malloc(sizeof(Nodo));
            nuovo_nodo->parola = (char *) malloc((lunghezza + 1) * sizeof(char));

            strcpy(nuovo_nodo->parola, buffer);

            nuovo_nodo->next = testa;
            testa = nuovo_nodo;
        }
    }

    fclose(fp);
    return testa;
}