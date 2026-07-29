#include <stdio.h>
#define LEN 20

char cifra(char);
char decifra(char);
int verifica_lettera(char);

char cifra(char lettera){
    if(lettera == 'z')
        return 'c';
    if(lettera == 'y')
        return 'b';
    if(lettera == 'x')
        return 'a';
    else
        return lettera + 3;
}

char decifra(char lettera){
        if(lettera == 'c')
        return 'z';
    if(lettera == 'b')
        return 'y';
    if(lettera == 'a')
        return 'x';
    else
        return lettera - 3;
}

int verifica_carattere(char lettera){
    if(lettera >= 'a' && lettera <= 'z')
        return 1;
    else
        return 0;
}

int main(){
    char stringa[LEN];
    char cifrato[LEN];
    char decifrato[LEN];

    for(int i = 0; i < LEN; i++){
        printf("\nInserire il carattere n%d di una stringa: ", i+1);
        scanf(" %c", &stringa[i]);

        // verifico che il carattere sia una lettera minuscola
        while(!verifica_carattere(stringa[i])){
            printf("\nERRORE: Inserire il carattere n%d di una stringa: ", i);
            scanf("%c", &stringa[i]);
        }

        // cifro la lettera della stringa
        cifrato[i] = cifra(stringa[i]);

        // decifro la lettera cifrata
        decifrato[i] = decifra(cifrato[i]);
    }

    // ciclo per stampare le stringhe
    printf("CIFRA IN INPUT: %s\nCIFRATA: %s\n DECIFRATA: %s\n", stringa, cifrato, decifrato);

    // controllo che la stringa sia uguale
    for(int i = 0; i < LEN; i++){
        if(decifrato[i] == stringa[i])
            printf("\nOK: Il carattere decifrato (%c) è uguale al carattere originale (%c)", decifrato[i], stringa[i]);
        else
            printf("\nERRORE: Il carattere decifrato (%c) non è uguale al carattere originale (%c)", decifrato[i], stringa[i]);
    }
}