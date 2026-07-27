# include <stdio.h>

int main() {
    int num1;
    int num2;

    // Inserimento primo numero
    printf("inserire un primo numero: ");
    scanf("%d", &num1); 
    // Inserimento secondo numero
    printf("inserire un secondo numero: ");
    scanf("%d", &num2); 

    printf("I numeri inseriti sono: %d e %d \n", num1, num2); // linea di debug
    
    if(num1 % num2 == 0){
        printf("Il primo numero: %d è un un multiplo del secondo: %d \n", num1, num2);
    }

    if(num2 % num1 == 0){
        printf("Il secondo numero: %d è un un multiplo del primo: %d \n", num2, num1);
    }

    else{
        printf("Non sono multipli tra loro \n");
    }
}