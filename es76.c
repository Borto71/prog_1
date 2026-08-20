/*
  Un file di testo contiene un numero indefinito di righe. 
  Ogni riga contiene esattamente due numeri interi positivi: "num" e "k".
  
  Una coppia si dice "valida" se il numero "num" termina con ESATTAMENTE 
  "k" zeri consecutivi.

  Ad esempio:
  - 1500 2  -> VALIDA (1500 finisce con esattamente due zeri).
  - 1500 1  -> NON VALIDA (finisce con due zeri, non uno).
  - 4050 1  -> VALIDA (finisce con un solo zero).
  - 83 0    -> VALIDA (finisce con zero zeri).

  Completare il programma definendo i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "conta_zeri_finali(int n)" che riceve 
     un numero intero e restituisce il numero di zeri che si trovano 
     alla fine del numero. 
     (Suggerimento: se l'ultima cifra NON è 0, fermati. Se è 0, somma 1 e 
     fai la chiamata ricorsiva su n/10. Attento al caso base se n diventa 0!).

  2. Il sottoprogramma "processa_file(char *nomefile)" che riceve il nome
     di un file di testo, lo apre in lettura, e restituisce quante 
     coppie valide ci sono al suo interno (restituisce -1 se il file non esiste).
*/

#include <stdio.h>
#include <stdlib.h>

int conta_zeri_finali(int n);
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
        printf("Il file contiene %d coppie valide.\n", risultato);
    }

    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI
// =========================================================

int processa_file(char *nomefile) {
    // Scrivi qui il tuo codice (ricorda fscanf nel while, =0 e fclose!)
    FILE *fp;
    int valide = 0;
    int numero, k;

    fp = fopen(nomefile, "r");  

    if(fp == NULL){
        return -1;
    }

    if(fp){
        while (fscanf(fp, "%d %d", &numero, &k) == 2)
        {
            if(conta_zeri_finali(numero) == k){
                valide++;
            }
        }
        
    }

    fclose(fp);
    return valide;
}

int conta_zeri_finali(int n) {
    int cont = 0;

    if(n == 0){
        return 0;
    }

    if(n % 10 != 0){
        return 0;
    } else {
        cont++;
    }

    return cont + conta_zeri_finali(n / 10); 
}