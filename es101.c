/*
  Sia data una matrice di interi di dimensione 4x5.

  Un elemento della matrice M[i][j] è detto "Centro di Croce" se soddisfa
  entrambe queste condizioni:
  1. NON si trova su nessuno dei bordi della matrice (deve avere spazio 
     sopra, sotto, a destra e a sinistra).
  2. Il suo valore è esattamente uguale alla somma dei suoi 4 elementi 
     ortogonalmente adiacenti (l'elemento sopra, quello sotto, quello 
     a destra e quello a sinistra).

  Completare il programma implementando:
  1. La funzione `int is_croce(int M[NR][NC], int r, int c)` che restituisce 1 
     se l'elemento alle coordinate (r, c) è un Centro di Croce, 0 altrimenti.
  2. Il codice nel `main` per scansionare l'intera matrice, stampando le 
     coordinate e il valore di tutti i Centri di Croce trovati.
*/

#include <stdio.h>

#define NR 4
#define NC 5

/* Prototipo */
int is_croce(int M[NR][NC], int r, int c);

int main() {
    int matrice[NR][NC];
    int i, j;
    int trovati = 0;

    printf("Inserisci i valori della matrice 4x5:\n");
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("Centri di Croce trovati:\n");
    
    /* ========================================================
       SCANSIONARE LA MATRICE E RICHIAMARE 'is_croce'
       ======================================================== */
    
    for(i = 0; i < NR; i++) {
        for(j = 0; j < NC; j++) {
            int croce = is_croce(matrice, i, j);

            if(croce == 1){
                printf("Coordinate: [%d][%d] Valore: %d\n", i, j, matrice[i][j]);
                trovati++;
            }
        }
    }

    if (trovati == 0) {
        printf("Nessun Centro di Croce presente nella matrice.\n");
    }

    return 0;
}

/* ==============================================
   IMPLEMENTARE IL SEGUENTE SOTTOPROGRAMMA
   ============================================== */

int is_croce(int M[NR][NC], int r, int c) {
    int somma;

    if(r > 0 && r < NR){
        if(c > 0 && c < NC - 1){
            somma = M[r-1][c] + M[r-1][c+1] + M[r][c+1] + M[r][c-1];

            if(M[r][c] == somma){
                return 1;
            }
        }
    }

    return 0;
}