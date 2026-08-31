/*
  Si consideri una matrice di interi positivi di dimensione 4x5.

  Un elemento della matrice M[i][j] è definito "Avvallamento" se il suo
  valore è strettamente MINORE di tutti i valori delle celle ad esso
  adiacenti (orizzontalmente, verticalmente e diagonalmente).
  Si noti che le celle sui bordi hanno un numero inferiore di adiacenti.

  Si scriva un programma che:
  1. Legga da tastiera i valori della matrice.
  2. Individui tutti gli "Avvallamenti" presenti.
  3. Modifichi la matrice: ogni volta che si individua un "Avvallamento",
     il suo valore deve essere sostituito con la SOMMA di tutti i suoi
     elementi adiacenti. Gli altri elementi rimangono inalterati.
  4. Stampi a video la matrice risultante.

  ATTENZIONE: l'aggiornamento deve essere simultaneo! I nuovi valori calcolati 
  non devono influenzare la verifica degli altri avvallamenti adiacenti. 
  (Suggerimento: potrebbe servirti una matrice di appoggio temporanea).

  Esempio di adiacenze (come in un campo minato):
  Per la cella (1,1), gli adiacenti sono le 8 celle circostanti.
  Per la cella (0,0), gli adiacenti sono solo 3: (0,1), (1,0) e (1,1).
*/

#include <stdio.h>

#define NR 4
#define NC 5

int main() {
    int mappa[NR][NC];
    int nuova_mappa[NR][NC];
    int i, j;

    /* 1. lettura */
    printf("Inserisci i 20 valori della matrice 4x5:\n");
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            scanf("%d", &mappa[i][j]);
        }
    }

    /* 2 e 3. individuazione e aggiornamento */
    // IMPLEMENTA QUI LA TUA LOGICA

    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            nuova_mappa[i][j] == mappa[i][j];
        }
    }

    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            int avvallamento = 1;
            int somma = 0;
            for(int r = i-1; r <= i+1; r++){
                for(int c = j-1; c <= j+1; c++){
                    if(r >= 0 && r < NR && c >= 0 && c < NC){
                        if(r != i || c != j){
                            if(mappa[i][j] >= mappa[r][c]){
                                avvallamento = 0;
                            }
                            somma += mappa[r][c];
                        }
                    }
                }
            }

            if(avvallamento == 1){
                nuova_mappa[i][j] = somma;
            }

        }
    }

    
    
    
    /* 4. stampa */
    printf("\nMatrice aggiornata:\n");
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            printf("%4d ", nuova_mappa[i][j]); // Stampa incolonnata
        }
        printf("\n");
    }

    return 0;
}