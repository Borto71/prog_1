/*
  Si scriva un programma per l'analisi di un file di log generato da alcuni sensori.
  
  Il file di testo, il cui nome viene inserito da tastiera, contiene un 
  numero indefinito di righe. Ogni riga rappresenta una misurazione ed è 
  composta da due elementi:
  - Una stringa (lunga al massimo 20 caratteri) che rappresenta l'ID del sensore.
  - Un numero intero positivo che rappresenta il valore rilevato.

  Una misurazione si dice "valida" se la lunghezza della stringa ID è 
  ESATTAMENTE UGUALE al numero di cifre dispari presenti nel valore rilevato.

  Esempi di misurazioni:
  * "Temp 17345" -> VALIDA: "Temp" è lunga 4 caratteri, e 17345 ha 4 cifre dispari (1, 7, 3, 5).
  * "SensoreA 246" -> NON VALIDA: "SensoreA" è lunga 8 caratteri, ma 246 ha 0 cifre dispari.
  
  Si completino le seguenti funzioni:

  1. int processa_file(char *nome), che riceve il nome del file da processare,
     lo legge riga per riga, richiama la funzione conta_dispari e restituisce 
     il numero totale di misurazioni valide. Ritorna -1 in caso di errore 
     nell'apertura del file.

  2. int conta_dispari(int num), che conta e restituisce quante cifre dispari 
     sono presenti nel numero 'num'. Questa funzione DEVE essere ricorsiva.
*/

#include <stdio.h>
#include <string.h>

int processa_file(char *nome);
int conta_dispari(int num);

int main() {
    char nomefile[50];
    int risultato;

    printf("Inserisci il nome del file: ");
    scanf("%s", nomefile);
    
    risultato = processa_file(nomefile);

    if (risultato == -1) {
        printf("Errore nell'apertura del file.\n");
    } else {
        printf("Numero misurazioni valide: %d\n", risultato);
    }

    return 0;
}

int processa_file(char *nome) {
    FILE *fp;
    fp = fopen(nome, "r");
    char buffer[21];
    int k;
    int valide = 0;

    if(fp == NULL){
        return -1;
    }

    while (fscanf(fp, "%s %d", buffer, &k) == 2)
    {
        int caratteri = strlen(buffer);
        int dispari = conta_dispari(k);

        if(caratteri == dispari){
            valide++;
        }
    }

    fclose(fp);
    return valide;
}

// Funzione ricorsiva
int conta_dispari(int num) {
    if(num == 0){
        return 0;
    }

    int cifra = num % 10;

    if(cifra % 2 == 0){
        return 0 + conta_dispari(num/10);
    }

    return 1 + conta_dispari(num/10);
}