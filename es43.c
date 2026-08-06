#include <stdio.h>
void divisione(int, int, int *, int *);

void divisione(int num, int i, int *risultato, int *resto){
    *risultato = num / i;
    *resto = num % i;
}

int main(){
    int num;
    int risultato, resto;

    printf("Inserire un numero per la divisione: ");
    scanf("%d", &num);

    for(int i = 2; i <= num; i++){
        divisione(num, i, &risultato, &resto);
        if(resto == 0){
            printf("\nIl numero %d è un divisiore!\n", i);
            printf("\nRisultato della divisione: %d\n", risultato);
        }
    }
    return 0;
}