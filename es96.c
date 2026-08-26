/*
  Sia dato un file di testo contenente il libretto universitario di uno studente.
  Ogni riga del file contiene le informazioni su un esame superato, nel formato:
  Nome_Materia Voto Crediti
  (es. "Analisi_1 28 9")
  
  Il "Nome_Materia" è una stringa senza spazi (massimo 50 caratteri).
  Il "Voto" è un intero (tra 18 e 30).
  I "Crediti" sono un intero positivo.

  Si implementi il sottoprogramma:
  int elabora_libretto(char *file_in, char *file_out)
  
  Il sottoprogramma deve:
  1. Aprire il file di input in lettura e il file di output in scrittura.
  2. Leggere tutti gli esami e calcolare la MEDIA PONDERATA complessiva.
     (La media ponderata si calcola come: Somma(Voto * Crediti) / Somma(Crediti)).
  3. Scrivere sul file di output SOLO le materie in cui il voto è >= 28, 
     formattate così: "Materia: Voto" (es. "Analisi_1: 28").
  4. Scrivere come ULTIMA riga del file di output la media ponderata calcolata 
     sui dati interi, formattata con due cifre decimali: "Media ponderata: X.XX"
  5. Restituire come intero il numero di esami eccellenti (voto >= 28) trovati.
     Se si verifica un errore nell'apertura di uno qualsiasi dei file, 
     il sottoprogramma deve restituire -1.

  Si assuma che il file contenga almeno un esame per evitare divisioni per zero.
*/

#include <stdio.h>
#include <stdlib.h>

/* Prototipo */
int elabora_libretto(char *file_in, char *file_out);

int main() {
    char file_in[100];
    char file_out[100];
    int eccellenti;

    printf("Inserisci nome file di input: ");
    scanf("%99s", file_in);
    printf("Inserisci nome file di output: ");
    scanf("%99s", file_out);

    eccellenti = elabora_libretto(file_in, file_out);

    if (eccellenti == -1) {
        printf("Errore nella gestione dei file.\n");
    } else {
        printf("Elaborazione completata. Trovati %d esami eccellenti.\n", eccellenti);
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

int elabora_libretto(char *file_in, char *file_out) {
    FILE *fin;
    FILE *fout;
    char materia;
    int voto, crediti;
    int cont = 0;

    int totale_prodotti = 0;
    int totale_cfu = 0;
    fin = fopen(file_in, "r");
    fout = fopen(file_out, "w");

    if(fin == NULL || fout == NULL){
        return -1;
    }
    
    while (fscanf(fin, "%s %d %d", materia, &voto, &crediti) == 3)
    {
        totale_prodotti += voto * crediti;
        totale_cfu = totale_cfu + crediti;

        if(voto >= 28){
            fprintf(fout, "%s: %d\n", materia, voto);
            cont++;
        }
    }

    float media = (float) totale_prodotti / totale_cfu;
    fprintf(fout, "Meda Ponderata: %.2f\n", media);

    fclose(fin);
    fclose(fout);

    return cont;
    
}