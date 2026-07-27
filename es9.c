# include <stdio.h>

int main() {
    int n;
    int totale = 0;

    printf("Inserire un numero intero positivo: ");
    scanf("%d", &n);

    while(n <  0){
        printf("ERRORE: Inserire un numero intero positivo: ");
         scanf("%d", &n);
    }

    for(int i = 0; i <= n; i++){
        totale += i;
    }

    printf("La somma di tutti i naturali da 0 a n è: %d \n", totale);
}
