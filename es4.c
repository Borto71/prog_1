# include <stdio.h>
# define N 15

int main() {
    int array[N];
    int media = 0;
    int totale = 0; // la somma di tutti i valori dentro l'array

    // ciclo per inserire i dati
    for(int i = 1; i <= 15; i++){
        printf("Inseririre il valore numero %d della temperatura \n", i);
        scanf("%d", &array[i-1]);
        totale += array[i-1];
    }

    media = totale / N; // la media è il totale diviso il numero di campioni
    printf("La media è: %d\n", media);
}