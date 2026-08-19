/*
  Completare il programma definendo i seguenti sottoprogrammi:

  1. Il sottoprogramma RICORSIVO "conta_maggiori(int num, int soglia)" che 
     riceve un numero intero positivo e una cifra "soglia" (da 0 a 9). 
     La funzione deve restituire quante cifre del numero "num" sono 
     strettamente maggiori della "soglia".
     (Suggerimento: usa % 10 per l'ultima cifra e / 10 per il passo ricorsivo).

  2. Il sottoprogramma "elabora_array(int *array, int dim, int soglia)" che riceve 
     un array dinamico, la sua dimensione, e la cifra soglia. 
     Il sottoprogramma deve scorrere l'array e restituire il CONTEGGIO TOTALE dei 
     numeri che contengono ALMENO DUE cifre maggiori della soglia, richiamando 
     obbligatoriamente la funzione ricorsiva "conta_maggiori".

  Esempio:
  Se l'array è [125, 80, 492, 11] e la soglia è 4:
  - 125 ha una cifra maggiore di 4 (il 5). Non va bene.
  - 80 ha una cifra maggiore di 4 (l'8). Non va bene.
  - 492 ha una cifra maggiore di 4? (il 9). Aspetta, 4 non è MAGGIORE di 4. Quindi ha solo il 9. Non va bene.
  Se l'array fosse [982, 15, 76] e la soglia è 5:
  - 982 ha due cifre > 5 (9 e 8). VA BENE (+1).
  - 15 ha zero cifre > 5 (il 5 è uguale, non maggiore). Non va bene.
  - 76 ha due cifre > 5 (7 e 6). VA BENE (+1).
  Risultato = 2.
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipi delle funzioni
int elabora_array(int *array, int dim, int soglia);
int conta_maggiori(int num, int soglia);

// IL MAIN NON DEVE ESSERE MODIFICATO
int main() {
    int N, soglia, risultato;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &N);

    // Allocazione dinamica (che ormai padroneggi!)
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Errore allocazione.\n");
        return -1;
    }

    printf("Inserisci i %d numeri:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Inserisci la cifra soglia (0-9): ");
    scanf("%d", &soglia);

    // Chiamata alla funzione da implementare
    risultato = elabora_array(arr, N, soglia);
    
    printf("Numeri validi trovati: %d\n", risultato);

    free(arr);
    return 0;
}

// =========================================================
// IMPLEMENTA QUI SOTTO LE DUE FUNZIONI 
// =========================================================

int elabora_array(int *array, int dim, int soglia) {
    int cont = 0;

    for(int i = 0; i < dim; i++){
        int res = conta_maggiori(array[i], soglia);
        if(res >= 2)
            cont++;
    }

    return cont;
}


int conta_maggiori(int num, int soglia) {

    if(num == 0)
        return 0;
        
    int cifra = num % 10;
    if(cifra > soglia)
        return 1 + conta_maggiori(num/10, soglia);

    return 0 + conta_maggiori(num/10, soglia);
}