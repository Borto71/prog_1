# include <stdio.h>

int main() {
    int n;

    // inserimento da tastiera
    printf("Inserisci un intero positivo: ");
    scanf("%d", &n);

    while (n < 0)
    {
       printf("ERRORE: Inserisci un intero positivo: ");
       scanf("%d", &n);
    }

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            printf("%d \t", r * c);
        }
        printf("\n");
    }

}
