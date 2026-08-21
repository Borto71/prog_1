/*
  Completare il programma definendo i seguenti sottoprogrammi:

  1. La funzione RICORSIVA `is_palindroma` che riceve una stringa `s`, 
     un indice di `inizio` e un indice di `fine`. Restituisce 1 se la 
     sottostringa compresa tra gli indici è palindroma, 0 altrimenti.
     (Es: "radar" letta da sinistra a destra o viceversa è identica).

  2. La funzione `conta_palindrome` che riceve il nome di un file. 
     Deve leggere tutte le parole presenti (max 50 caratteri l'una) 
     e restituire il numero totale di parole palindrome trovate 
     usando la funzione `is_palindroma`. In caso di errore, restituisce -1.
*/

#include <stdio.h>
#include <string.h>

int is_palindroma(char *s, int inizio, int fine);
int conta_palindrome(char *nome_file);

int main() {
    char nome_file[100];
    scanf("%s", nome_file);
    
    int risultato = conta_palindrome(nome_file);
    if(risultato == -1) printf("Errore file.\n");
    else printf("Parole palindrome: %d\n", risultato);
    
    return 0;
}

int is_palindroma(char *s, int inizio, int fine){
    if(inizio >= fine){
        return 1;
    }

    if(s[inizio] != s[fine]){
        return 0;
    }

    return is_palindroma(s, inizio + 1, fine - 1);
}

int conta_palindrome(char *nome_file){
    char buffer[51];
    FILE *fp;
    int cont = 0;

    fp = fopen(nome_file, "r");

    if(fp == NULL){
        return -1;
    }

    while (fscanf(fp, "%s", buffer) == 1)
    {
        int len = strlen(buffer);
        cont = is_palindroma(buffer, 0, len - 1);
    }
    
    fclose(fp);
    return cont;
}