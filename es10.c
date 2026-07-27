# include <stdio.h>

int main() {
    int n;
    int multipli_3 = 0; // contatore per contare i multipli di 3

    printf("Inserire un numero intero positivo: \n");
    scanf("%d", &n);

    // controllo che sia intero positivo
    while (n <  0)
    {
        printf("ERRORE: Inserire un numero intero positivo: \n");
        scanf("%d", &n);
    }

    for(int i = 0; i <= n; i++){
        if(i % 3 == 0){
            multipli_3++;
        }
    }
    
    printf("I valore multipli di 3 sono: %d \n", multipli_3);
}
