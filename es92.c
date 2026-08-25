/*
  Sia data una matrice di interi di dimensione 4x5.

  Per ogni elemento della matrice, definiamo il suo "vicinato" come
  l'insieme delle celle adiacenti (orizzontalmente, verticalmente o
  diagonalmente) che sono valide all'interno della matrice. 
  Il vicinato NON include l'elemento stesso.

  Un elemento si dice "protetto" se la somma dei valori presenti nel
  suo vicinato è un numero PARI. 

  Completare il programma definendo e utilizzando:
  1. La funzione `somma_vicini` che, data la matrice e le coordinate di 
     una cella, calcoli e restituisca la somma dei suoi vicini validi.
  2. Il codice nel `main` che, per ogni cella della matrice letta in input,
     verifichi se è protetta. Se lo è, il suo valore nella matrice `risultato`
     deve essere il doppio del valore originale; altrimenti, deve essere 0.

  Nota: Attenzione ai bordi della matrice! Non accedere a indici fuori dai limiti.
*/

#include <stdio.h>

#define NR 4
#define NC 5

/* Prototipo */
int somma_vicini(int mappa[NR][NC], int riga, int colonna);

int main() {
    int mappa[NR][NC];
    int risultato[NR][NC];
    int i, j;

    /* Lettura della matrice */
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            scanf("%d", &mappa[i][j]);
        }
    }

    /* ========================================================
       AGGIORNARE LA MATRICE 'risultato' UTILIZZANDO 'somma_vicini' 
       ======================================================== */
    
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            int somma = somma_vicini(mappa, i, j);

            if(somma % 2 == 0){
                risultato[i][j] = mappa[i][j] * 2;
            } else {
                risultato[i][j] = 0;
            }
        }
    }
    
    
    /* Stampa della matrice risultato */
    printf("Matrice modificata:\n");
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            printf("%d ", risultato[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE I SEGUENTI SOTTOPROGRAMMI
   ============================================== */
int somma_vicini(int mappa[NR][NC], int riga, int colonna) {
    int somma = 0;

    for(int i = riga - 1; i <= riga + 1; i++) {
        for(int j = colonna - 1; j <= colonna + 1; j++) {
            
            // 1. Controllo se le coordinate (i, j) sono "valide" (dentro la mappa)
            if(i >= 0 && i < NR && j >= 0 && j < NC) {
                
                // 2. Controllo di non sommare la cella stessa al centro!
                if(i != riga || j != colonna) {
                    
                    // Se l'esercizio chiede SOLO I PARI, aggiungi qui l'if (% 2 == 0)
                    somma = somma + mappa[i][j];
                }
            }
        }
    }
    
    return somma;
}