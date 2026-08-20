/*
  Un file di testo contiene un numero indefinito di parole, una per riga.
  Ogni parola è lunga al massimo 50 caratteri.
  
  Una parola si dice "bilanciata" se il numero di lettere maiuscole 
  che contiene è ESATTAMENTE uguale al numero di lettere minuscole.
  
  Ad esempio:
  - "CiaO" è bilanciata (2 maiuscole: C, O; 2 minuscole: i, a).
  - "Gatto" NON è bilanciata (1 maiuscola: G; 4 minuscole: a, t, t, o).
  - "123?!" è bilanciata (0 maiuscole, 0 minuscole).

  Completare il programma definendo i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "differenza_lettere(char *s)" che riceve 
     una stringa e restituisce la differenza tra il numero di maiuscole e 
     il numero di minuscole. Se il calcolo finale è 0, la parola è bilanciata.
     (Suggerimento: in C, puoi verificare se un carattere è maiuscolo con 
     'A' <= s[0] && s[0] <= 'Z'. Il caso base è quando incontri il terminatore '\0'.
     Per il passo ricorsivo, usa s + 1 per spostarti al carattere successivo).

  2. Il sottoprogramma "processa_file(char *nomefile)" che riceve il nome
     di un file di testo, lo apre in lettura, conta e restituisce quante 
     parole bilanciate ci sono al suo interno.
     Se il file non può essere aperto, la funzione deve restituire -1.
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipi
int differenza_lettere(char *s);
int processa_file(char *nomefile);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    char nomefile[100];
    
    printf("Inserisci il nome del file: ");
    scanf("%s", nomefile);

    int risultato = processa_file(nomefile);

    if (risultato == -1) {
        printf("Errore: impossibile aprire il file.\n");
    } else {
        printf("Il file contiene %d parole bilanciate.\n", risultato);
    }

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int processa_file(char *nomefile) {
    FILE* fp;
    char parola[51];
    int bilanciata;

    fp = fopen(nomefile, "r");

    if(fp == NULL){
        return -1;
    }

    if(fp){
        fscanf(fp, "%s", parola);
        while (!feof(fp))
        {
            fscanf(fp, "%s", parola);
            if(differenza_lettere(parola) == 0){
                bilanciata++;
            }
        }
    }

    return bilanciata;
}

int differenza_lettere(char *s) {
    int differenza;
    int minuscole = 0;
    int maiuscole = 0;

    if(*s == '\0'){
        return 0;
    }

    if('A' <= s[0] && s[0] <= 'Z'){
        maiuscole++;
    } else if('a' <= s[0] && s[0] <= 'z'){
        minuscole++;
    }
    
    differenza = maiuscole - minuscole;
    return differenza + differenza_lettere(s + 1);
}