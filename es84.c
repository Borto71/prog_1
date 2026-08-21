/*
  Si consideri una matrice di interi di dimensione 5x5 che rappresenta
  una mappa di altitudini.
  
  Si scriva un programma che individui tutti i "picchi locali" della matrice.
  Un elemento A[i][j] è considerato un picco locale se il suo valore è 
  strettamente maggiore di tutti gli elementi adiacenti a croce (ovvero 
  l'elemento sopra, sotto, a destra e a sinistra). 
  
  Attenzione: per gli elementi che si trovano sui bordi, l'intorno a croce 
  sarà ridotto alle sole celle effettivamente presenti nella matrice.
  
  Il programma deve creare e stampare una nuova matrice (o modificare 
  quella esistente) in cui ogni cella contiene:
  - 1 se la cella corrispondente era un picco locale
  - 0 in caso contrario.
*/

#include <stdio.h>

#define N 5

int main() {
    int altitudini[N][N];
    int picchi[N][N];
    int i, j;

    /* lettura della matrice */
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &altitudini[i][j]);
        }
    }

    /* INIZIO CODICE DA COMPLETARE: 
       calcolo dei picchi locali */
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            int picco = 1;

            if(i > 0 && altitudini[i][j] <= altitudini[i-1][j]){
                picco = 0;
            } 

            if(j > 0 && altitudini[i][j] <= altitudini[i][j-1]){
                picco = 0;
            }

            if(i < N-1 && altitudini[i][j] <= altitudini[i+1][j]){
                picco = 0;
            }

            if(j < N-1 && altitudini[i][j] <= altitudini[i][j+1]){
                picco = 0;
            }

            picchi[i][j] = picco;
        }
    }
       


    /* FINE CODICE DA COMPLETARE */
	
    printf("Mappa dei picchi locali:\n");
    
    /* stampa della matrice risultato */
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            printf("%d ", picchi[i][j]);
        }
        printf("\n");
    }

    return 0;
}