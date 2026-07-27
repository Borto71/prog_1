# include <stdio.h>

int main() {
    int n;
    // Inserimento del valore
    printf("Inserire un numero postivo: ");
    scanf("%d", &n);

    // Controllo del valore
    if(n < 0){
        printf("ERRORE: Inserire un numero positivo: ");
        scanf("%d", &n);
    }

    printf("I numeri pari compresi tra 0 e %d sono: \n", n);
    for(int i = 0; i <= n; i++){
        if(i % 2 == 0){
            printf("%d", i);
        }
        else{
            printf("\n");
        }
    }

}
