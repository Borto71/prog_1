#include <stdio.h>
#include <stdlib.h>

int valore_assoluto(int);
int inserisci_numero();
void maggiore(int, int);

int valore_assoluto(int numero){
    return abs(numero);
}

int inserisci_numero(){
    int numero;
    printf("\nInserisci un numero: ");
    scanf("%d", &numero);

    return numero;
}

void maggiore(int num1, int num2){
    int abs1 = valore_assoluto(num1);
    int abs2 = valore_assoluto(num2);

    if(abs1 > abs2){
        printf("\nIl numero 1 (%d) è MAGGIORE", abs1);
    }else{
        printf("\nIl numero 2 (%d) è MAGGIORE: ", abs2);
    }
}

int main(){
    int num1 = inserisci_numero();
    int num2 = inserisci_numero();

    maggiore(num1, num2);
    return 0;
}