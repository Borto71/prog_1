# include <stdio.h>

int main() {
    char a;
    char b;

    // Inserimento primo carattere
    printf("Inserisci il primo carattere: \n");
    scanf("%c", &a);

    // Inserimento secondo carattere
    printf("Inserisci il secondo carattere: \n");
    scanf(" %c", &b);

    if(a - b == 1 || b - a == 1){
        printf("Il carattere %c (%d) e il carattere %c (%d) SONO SUCCESSIVI \n", a, a, b, b);
    }
    else{
        printf("Non sono successivi \n");
    }
}