/*
  Sia dato un file di testo contenente le misurazioni giornaliere della 
  temperatura di una città. Ogni riga del file contiene:
  Giorno Mese Anno Temperatura
  (es. "15 8 2026 35.5")

  I primi tre campi sono interi, il quarto è un numero decimale (float).

  Si implementi il sottoprogramma:
  int filtra_temperature(char *file_in, char *file_out, float soglia)
  
  Il sottoprogramma deve:
  1. Aprire il file 'file_in' in LETTURA e 'file_out' in SCRITTURA.
     Se uno dei due file non può essere aperto, la funzione deve 
     restituire -1. Assicurarsi di non lasciare file aperti se uno fallisce.
  2. Leggere tutte le misurazioni presenti nel file di input.
  3. Se la temperatura letta è MAGGIORE o UGUALE alla 'soglia', 
     scrivere un avviso sul file di output nel seguente formato esatto:
     "Allarme caldo: GG/MM/AAAA registrati XX.X gradi\n"
     (es. "Allarme caldo: 15/08/2026 registrati 35.5 gradi").
     NB: Formattare Giorno e Mese in modo che abbiano sempre 2 cifre.
  4. Restituire come intero il numero totale di allarmi registrati 
     (ovvero il numero di righe scritte nel file di output).
     
  Si ricordi di chiudere correttamente entrambi i file al termine.
*/

#include <stdio.h>

// Prototipo
int filtra_temperature(char *file_in, char *file_out, float soglia);

int main() {
    char f_in[100];
    char f_out[100];
    float soglia_allarme;
    int anomalie;

    printf("Inserisci nome file di input (es. meteo.txt): ");
    scanf("%99s", f_in);
    
    printf("Inserisci nome file di output (es. allarmi.txt): ");
    scanf("%99s", f_out);
    
    printf("Inserisci la temperatura di soglia: ");
    scanf("%f", &soglia_allarme);

    anomalie = filtra_temperature(f_in, f_out, soglia_allarme);

    if (anomalie == -1) {
        printf("Errore: Impossibile aprire i file specificati.\n");
    } else {
        printf("Elaborazione completata. Generati %d allarmi.\n", anomalie);
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

int filtra_temperature(char *file_in, char *file_out, float soglia) {
    FILE *fin;
    FILE *fout;
    int giorno, mese, anno;
    float temperatura;
    int cont = 0;

    fin = fopen(file_in, "r");
    fout = fopen(file_out, "w"); 

    if(fin == NULL || fout == NULL){
        fclose(fin);
        fclose(fout);
        return -1;
    }

    while (fscanf(fin,"%d %d %d %f",&giorno, &mese, &anno, &temperatura))
    {
        if(temperatura >= soglia){
            fprintf(fout, "Allarme caldo: %02d/%02d/%d registrati %.2f gradi\n", giorno, mese, anno, temperatura);
            cont++;
        }
    }

    fclose(fin);
    fclose(fout);
    return cont;
}