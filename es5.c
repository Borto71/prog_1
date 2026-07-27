# include <stdio.h>

int main() {
    int num;
    int is_prime = 1; // flag per decretare se è primo

    printf("Inserire un numero maggiore di 1: \n");
    scanf("%d", &num);

    // verifico che sia maggiore di 1
    while(num < 1){
        printf("ERRORE: Inserire un numero maggiore di 1: \n");
        scanf("%d", &num);
    }

    for(int i = 2; i * i <= num; i++){ // contatore per scorrere i vari numeri
        if(num % i == 0){ // ho trovato un divisore diverso da 1 e se stesso, quindi NON è primo
            is_prime = 0; // non è primo
            break;
        }
    }

    if(is_prime == 1){
        printf("Il numero %d è primo \n", num);
    }
    else{
        printf("Il numero %d non è primo \n", num);
    }

    return 0;
}
