# include <stdio.h>

int main() {
    int num;
    int totale = 0;
    int conteggio = 0;
    int media = 0;

    printf("Inserisci un numero, 0 se vuoi terminare \n");
    printf("Inserire il prossimo numero: ");
    scanf("%d", &num);

    // controllo che la sequenza non sia vuota
    if(num == 0){
        printf("ERRORE: La sequenza è vuota \n");
    }
    else{
    // finchè non è 0 aggiungi i numeri al totale
    while (num != 0)
    {
        totale += num;
        conteggio++; // aumento il conteggio 

        // chiedo il prossimo numero
        printf("Inserire il prossimo numero: ");
        scanf("%d", &num);
    }

    media = totale / conteggio;

    printf("Il valore medio è: %d \n", media);
    }

    return 0;
}
