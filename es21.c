#include <stdio.h>
# define DIM 10
int main() {
    int valori [DIM];
    int max;
    int val1;
    int val2;

    // Inserimento dei valori
    printf("Inserire 10 valori interi\n");
    for(int i = 0; i < DIM; i++){
        printf("Inserire il %d valore: ", i + 1);
        scanf("%d", &valori[i]);
    }

    /*max = valori[0] + valori[1];
    val1 = valori[0];
    val2 = valori[1];*/

    // calcolo della coppia di valori che sommati è il massimo
    for(int i = 0; i < DIM; i++){
        for(int j = i; j < DIM; j++){
            int somma = valori[i] + valori[j];
            if(somma > max){
                max = somma;
                val1 = valori[i];
                val2 = valori[j];
            }
        }
    }
    
    printf("La somma maggiore è: %d\nEd è composta da questi valori: \nVAL1: %d \nVAL2: %d\n", max, val1, val2);
    return 0;
}