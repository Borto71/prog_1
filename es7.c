# include <stdio.h>

int main() {
    int num;
    int pari = 0;
    int dispari = 0;

    for(int i = 0; i < 10; i++){
        do{
            printf("Inserisci il %d numero: ", i + 1);
            scanf("%d", &num);

            if(num <= 0){
                printf("ERRORE: Devi inserire un numero postivo \n");
            }

        }while (num <= 0);
        

        if(num % 2 == 0){
            pari++;
        }
        else{
            dispari++;
        }
    }

    printf("Abbiamo ottenuto: \n -- %d numero pari --\n -- %d numeri dispari -- \n", pari, dispari);
    return 0;
}
