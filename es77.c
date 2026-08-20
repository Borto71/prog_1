/*
  Completare il programma definendo i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "conta_decrescenti(char *s)" che prende in input
     una stringa e restituisce la lunghezza della sequenza iniziale di caratteri 
     alfabeticamente consecutivi in ordine strettamente DECRESCENTE.
     
     In ordine decrescente, ogni carattere deve essere l'esatto precedente 
     nell'alfabeto rispetto a quello che lo precede (es. 'c' segue 'd', 'a' segue 'b').
     In C, questo significa che s[1] deve essere uguale a s[0] - 1.
     
     La sequenza si interrompe quando il carattere successivo NON rispetta 
     questa regola, oppure quando la stringa finisce.
     
     Ad esempio:
     - "edcba" -> restituisce 5 (tutti consecutivi decrescenti)
     - "zyxw"  -> restituisce 4
     - "xya"   -> restituisce 1 (perché 'y' non è (x - 1), la sequenza si ferma subito a 'x')
     - "gfedz" -> restituisce 4 ('g', 'f', 'e', 'd' decrescono, ma 'z' rompe la sequenza).

  2. Il sottoprogramma "conta_parole(char *nomefile, int soglia)" che apre un 
     file di testo, legge una per una le parole presenti (sapendo che ogni parola è 
     composta da al massimo 25 caratteri) e restituisce quante sono le parole nel file 
     la cui sequenza iniziale decrescente ha lunghezza MAGGIORE della soglia passata
     come parametro.
     Se il file non può essere aperto, il sottoprogramma restituisce -1.
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 26 // 25 caratteri massimi + 1 per il terminatore '\0'

// Prototipi delle funzioni
int conta_decrescenti(char *s);
int conta_parole(char *nomefile, int soglia);

// =========================================================
// MAIN (NON MODIFICARE)
// =========================================================
int main() {
    char nomefile[100];
    int soglia;
    int risultato;
    
    printf("Inserisci il nome del file: ");
    scanf("%s", nomefile);
    
    printf("Inserisci la lunghezza soglia: ");
    scanf("%d", &soglia);

    risultato = conta_parole(nomefile, soglia);

    if (risultato == -1) {
        printf("Errore: impossibile accedere al file.\n");
    } else {
        printf("Parole valide trovate: %d\n", risultato);
    }

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int conta_parole(char *nomefile, int soglia) {
    FILE* fp;
    char parola[26];
    int sequenza = 0;
    fp = fopen(nomefile, "r");

    if(fp == NULL){
        return -1;
    }

    if(fp){
        while (fscanf(fp, "%s", parola) == 1)
        {
            if(conta_decrescenti(parola) > soglia){
                sequenza++;
            }
        }
    }

    fclose(fp);
    return sequenza;
}

int conta_decrescenti(char *s) {
    int cont = 0;

    if(*s == '\0'){
        return 0;
    }

    if(s[1] == '\0'){
        return 1;
    }
    
    if(s[1] == s[0] - 1){
        return 1 + conta_decrescenti(s + 1);
    } else {
        return 1;
    }
}