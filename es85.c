/*
   Completare il programma definendo i seguenti sottoprogrammi:

   1. La funzione RICORSIVA `conta_maiuscole` che, presa in input una stringa,
      restituisce il numero di caratteri alfabetici maiuscoli presenti in essa.
      (Esempio: "AmeRiCa" -> restituisce 3).

   2. La funzione `analizza_file` che riceve come parametro il nome di un file
      di testo e un intero `K`. La funzione deve aprire il file, leggere 
      tutte le parole in esso contenute (una per riga, massimo 30 caratteri 
      ciascuna) e restituire quante di queste parole contengono ESATTAMENTE 
      `K` lettere maiuscole, invocando il sottoprogramma `conta_maiuscole`.
      In caso di errore nell'apertura del file, la funzione deve restituire -1.

*/
  
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 31

/* Prototipi */
int analizza_file(char *nome_file, int k);
int conta_maiuscole(char *s);

int main() {
    char nome[100];
    int k, risultato;

    printf("Inserisci nome file e valore K: ");
    scanf("%s %d", nome, &k);
    
    risultato = analizza_file(nome, k);

    if (risultato == -1) {
        printf("Errore di accesso al file.\n");
    } else {
        printf("Parole con esattamente %d maiuscole: %d\n", k, risultato);
    }

    return 0;
}

// Implementare la funzione (che legge il file)
int analizza_file(char *nome_file, int k) {
    FILE *fp;
    char buffer[31];
    int cont = 0;

    fp = fopen(nome_file, "r");

    if(fp == NULL){
        return -1;
    }

    while (fscanf(fp, "%s", buffer) == 1)
    {
        int maiuscole = conta_maiuscole(buffer);
        if(maiuscole == k){
            cont++;
        }
    }

    fclose(fp);
    return cont;
}

// Implementare la funzione RICORSIVA
int conta_maiuscole(char *s) {
    if(s[0] == '\0'){ // caso base
        return 0;
    }

    if(s[0] >= 'A' && s[0] <= 'Z'){
        return 1 + conta_maiuscole(s+1);
    }

    return 0 + conta_maiuscole(s+1);
}