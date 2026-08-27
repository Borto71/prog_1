/*
  Sia dato un file di testo ("magazzino.txt") che contiene l'inventario 
  di un negozio. Ogni riga del file descrive un prodotto nel seguente formato:
  Nome_Prodotto Quantita Prezzo_Unitario
  (es. "Pasta 15 1.20")

  Il "Nome_Prodotto" è una stringa senza spazi (massimo 50 caratteri).
  La "Quantita" è un numero intero.
  Il "Prezzo_Unitario" è un numero decimale (float).

  Si implementi il sottoprogramma:
  int elabora_magazzino(char *file_in, char *file_out, int soglia_scorta)
  
  Il sottoprogramma deve:
  1. Aprire il file 'file_in' in LETTURA e 'file_out' in SCRITTURA.
     Se uno dei due file non può essere aperto, restituire -1.
  2. Leggere tutti i prodotti. Per ogni prodotto letto:
     - Calcolare il valore totale del magazzino (sommando per ogni 
       prodotto il prodotto di Quantita * Prezzo_Unitario).
     - Se la quantità del prodotto in questione è MINORE della 'soglia_scorta',
       scrivere il prodotto sul file di output nel formato:
       "ORDINE: Nome_Prodotto - Mancano X pezzi" 
       (dove X è la differenza tra soglia_scorta e la Quantita attuale).
  3. Scrivere come ULTIMA riga del file di output il valore totale calcolato:
     "Valore totale magazzino: YYY.YY Euro" (formattato a 2 cifre decimali).
  4. Restituire come intero il numero totale di prodotti che devono essere riordinati 
     (cioè quelli la cui quantità era sotto la soglia).
*/

#include <stdio.h>
#include <stdlib.h>

/* Prototipo */
int elabora_magazzino(char *file_in, char *file_out, int soglia_scorta);

int main() {
    char f_in[100], f_out[100];
    int soglia;
    int riordini;

    printf("Inserisci nome file di input: ");
    scanf("%99s", f_in);
    
    printf("Inserisci nome file di output: ");
    scanf("%99s", f_out);
    
    printf("Inserisci la soglia minima di scorta: ");
    scanf("%d", &soglia);

    riordini = elabora_magazzino(f_in, f_out, soglia);

    if (riordini == -1) {
        printf("Errore: Impossibile aprire i file specificati.\n");
    } else {
        printf("Elaborazione completata. Generati %d ordini.\n", riordini);
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

int elabora_magazzino(char *file_in, char *file_out, int soglia_scorta) {
    FILE *fin;
    FILE *fout;

    char nome_prodotto[51];
    int quantita;
    float prezzo_unitario;
    float valore_magazzino = 0;
    int cont = 0;

    fin = fopen(file_in, "r");
    fout = fopen(file_out, "w");

    if(fin == NULL || fout == NULL){
        return -1;
    }

    while (fscanf(fin, "%s %d %f", nome_prodotto, &quantita, &prezzo_unitario) == 3)
    {
        valore_magazzino += (float) quantita * prezzo_unitario;

        if(quantita < soglia_scorta){
            fprintf(fout, "ORDINE: %s - Mancano %d pezzi\n", nome_prodotto, soglia_scorta - quantita);
            cont++;
        }
    } 
    
    fprintf(fout, "Valore totale magazzino: %.2f Euro", valore_magazzino);

    fclose(fin);
    fclose(fout);
    
    return cont;
}