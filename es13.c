# include <stdio.h>
# define N 10
int main() {
    int n[N];
    int somma = 0;
    int positivi = 0;
    int negativi = 0;
    int zero = 0;

    // Inserimento da tastiera
    for(int i = 0; i < N; i++){
        printf("Inserire il valore %d: ", i + 1);
        scanf("%d", &n[i]);
    }
    // stampa nell'ordine inserito
    printf("-- Stampa nell'ordine inserito -- \n");
    for(int i = 0; i < N; i++){
        printf("%d, ", n[i]);
    }
    //stampa ordine inverso
    printf("\n -- Stampa ordine inverso -- \n");
    for(int i = N-1; i > 0; i--){
        printf("%d, ", n[i]);
    }
    // stampa la somma e la calcola
    printf("\n -- Stampa della somma di tutti i valori inseriti -- \n");
    for(int i = 0; i < N; i++){
        somma += n[i];
    }
    printf("La somma è: %d \n", somma);

    // calcolo quanti sono i positivi, i negativi e lo 0
        printf("-- Stampa di quanti valori positivi, negativi e 0 ci sono -- \n");
    for(int i = 0; i < N; i++){
        if(n[i] > 0){
            positivi++;
        }
        if(n[i] < 0){
            negativi++;
        }
        else if(n[i] == 0){
            zero++;
        }
    }
    printf("I valori positivi sono: %d \n I valori negativi sono: %d \n Gli 0 sono: %d \n", positivi, negativi, zero);

}
