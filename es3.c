# include <stdio.h>

int main() {
    int base;
    int lato1;
    int lato2;

    // Inserimento della base del triangolo
    printf("Inserire la base del triangolo: ");
    scanf("%d", &base);

    // Inserimento del primo lato del triangolo
    printf("Inserire il primo lato del triangolo: ");
    scanf("%d", &lato1);

    // Inserimento del secondo lato del triangolo
    printf("Inserire il secondo lato del triangolo: ");
    scanf("%d", &lato2);

    if(base == lato1 && lato1 == lato2){
        printf("Il triangolo è un triangolo equilatero\n");
    }
    if(lato1 == lato2 && base != lato1 || base == lato1 && lato1 != lato2){
        printf("Il triangolo è un triangolo isoscele\n");
    }
    if(base != lato1 && lato1 != lato2){
        printf("Il triangolo è un triangolo scaleno\n");
    }
}