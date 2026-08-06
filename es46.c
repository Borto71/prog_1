#include <stdio.h>
#define MAX 30

int conta_vocali(char stringa[]){
    int cont = 0;

    for(int i = 0; i < MAX; i++){
        if(stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u'){
            cont++;
        }
    }

    return cont;
}

int main() {
    char stringa[MAX];

    for(int i = 0; i < MAX; i++){
        printf("Inserire il carattere numero %d della stringa: ", i+1);
        scanf(" %c", &stringa[i]);
    }

    int result = conta_vocali(stringa);

    printf("Nella stringa (%s) ci sono %d vocali", stringa, result);
}