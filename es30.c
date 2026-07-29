#include <stdio.h>

double maggiore(double, double);
double richiesta_num();

double maggiore(double num1, double num2){
    if(num1 > num2)
        return num1;
    else
        return num2;
}

double richiesta_num(){
    double numero;
    printf("Inserire un numero con la virgola: ");
    scanf("%lf", &numero);

    return numero;
}

int main(){
    double num1 = richiesta_num();
    double num2 = richiesta_num();
    double num3 = richiesta_num();
    double max = 0.0;
    
    max = maggiore(num1, num2);
    max = maggiore(max, num3);
    printf("Il numero maggiore è: %lf\n", max);
}