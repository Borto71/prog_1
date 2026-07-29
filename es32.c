#include <stdio.h>

typedef struct
{
   int numeratore;
   int denominatore;
} frazione;


int main(){

    frazione f1, f2, somma;
    int somma_frazioni;

    // Inserimento da tastiera della prima frazione
    printf("Inserire il numeratore della prima frazione: ");
    scanf("%d", &f1.numeratore);
    printf("\nInserire il denominatore della prima frazione: ");
    scanf("%d", &f1.denominatore);

    // Inserimento da tastiera della prima frazione
    printf("\nInserire il numeratore della seconda frazione: ");
    scanf("%d", &f2.numeratore);
    printf("\nInserire il denominatore della seconda frazione: ");
    scanf("%d", &f2.denominatore);

    // calcolo il denominatore
    somma.denominatore = f1.denominatore * f2.denominatore;

    // calcolo il numeratore
    somma.numeratore = (f1.numeratore * f2.denominatore) + (f2.numeratore * f1.denominatore);

    if(somma.denominatore < 0){
        somma.numeratore = -somma.numeratore;
        somma.denominatore = -somma.denominatore;
    }


    printf("\nLa somma tra le due frazioni ((%d/%d) + (%d/%d)) è: %d / %d\n", f1.numeratore, f1.denominatore, f2.numeratore, f2.denominatore, somma.numeratore, somma.denominatore);

}