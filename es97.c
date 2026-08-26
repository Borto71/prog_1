/*
  Un ospedale gestisce la coda dei pazienti in attesa tramite una lista concatenata.
  Ogni nodo rappresenta un paziente e contiene il suo numero di ticket (id) 
  e un codice di gravità (1 = Bianco, 2 = Verde, 3 = Rosso).
  
  La lista funziona come una CODA (FIFO): 
  - I nuovi pazienti vengono inseriti alla fine (in coda).
  - I pazienti vengono visitati (estratti) dall'inizio (in testa).

  Completare il programma implementando i seguenti sottoprogrammi:

  1. Paziente* push_coda(Paziente *testa, int id, int gravita)
     Inserisce un nuovo paziente in FONDO alla lista (in coda). 
     Restituisce la testa della lista aggiornata.

  2. Paziente* pop_coda(Paziente *testa, int *id_estratto)
     Estrae il paziente in TESTA alla lista (il primo della fila).
     Salva il suo 'id' nella variabile puntata da "id_estratto".
     Dealloca il nodo estratto e restituisce la nuova testa della lista.
     Se la coda è già vuota, restituisce NULL e imposta *id_estratto a -1.

  3. int conta_rossi(Paziente *testa)
     Funzione RICORSIVA che conta e restituisce quanti pazienti nella coda 
     hanno gravità pari a 3 (Codice Rosso).
*/

#include <stdio.h>
#include <stdlib.h>

// Definizione del nodo Paziente
typedef struct paziente {
    int id;
    int gravita;
    struct paziente *next;
} Paziente;

// Prototipi
Paziente* push_coda(Paziente *testa, int id, int gravita);
Paziente* pop_coda(Paziente *testa, int *id_estratto);
int conta_rossi(Paziente *testa);
void stampa_coda(Paziente *testa);

/* =========================================================
   MAIN (NON MODIFICARE)
   ========================================================= */
int main() {
    Paziente *coda_ps = NULL;
    int servito = 0;

    // Arrivano 4 pazienti al Pronto Soccorso
    coda_ps = push_coda(coda_ps, 101, 2); // Verde
    coda_ps = push_coda(coda_ps, 102, 3); // Rosso
    coda_ps = push_coda(coda_ps, 103, 1); // Bianco
    coda_ps = push_coda(coda_ps, 104, 3); // Rosso

    printf("Stato attuale della coda:\n");
    stampa_coda(coda_ps);

    printf("\nPazienti in Codice Rosso in attesa: %d\n", conta_rossi(coda_ps));

    // Il medico chiama i primi due pazienti
    printf("\n--- Il medico chiama 2 pazienti ---\n");
    
    coda_ps = pop_coda(coda_ps, &servito);
    printf("Paziente servito: Ticket %d\n", servito);
    
    coda_ps = pop_coda(coda_ps, &servito);
    printf("Paziente servito: Ticket %d\n", servito);

    printf("\nStato attuale della coda dopo le visite:\n");
    stampa_coda(coda_ps);
    printf("Pazienti in Codice Rosso rimasti: %d\n", conta_rossi(coda_ps));

    // Svuotiamo il resto della coda per pulire la memoria
    while(coda_ps != NULL) {
        coda_ps = pop_coda(coda_ps, &servito);
    }

    return 0;
}

// Funzione di stampa (Già fornita)
void stampa_coda(Paziente *testa) {
    if (testa == NULL) {
        printf("La coda e' vuota.\n");
        return;
    }
    while (testa != NULL) {
        printf("[Ticket: %d | Gravita': %d] -> ", testa->id, testa->gravita);
        testa = testa->next;
    }
    printf("NULL\n");
}

/* ==============================================
   IMPLEMENTARE I SEGUENTI SOTTOPROGRAMMI
   ============================================== */

Paziente* push_coda(Paziente *testa, int id, int gravita) {
    // Il tuo codice qui
}

Paziente* pop_coda(Paziente *testa, int *id_estratto) {
    // Il tuo codice qui
}

int conta_rossi(Paziente *testa) {
    // Il tuo codice qui (RICORSIVA)
}