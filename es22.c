#include <stdio.h>
# define LEN 10
int main() {
    char s1[LEN];
    char s2[LEN * 2];

    // inserimento da tastiera
    printf("Inserire 10 caratteri");
    for(int i = 0; i < LEN; i++){
        printf("\nInserire il carattere numero %d: ", i+1);
        scanf(" %c", &s1[i]);
    }

    int j = 0;
    // costruisco il nuovo array
    for(int i = 0; i < LEN; i++){
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'){
            s2[j] = s1[i];
            s2[j+1] = s1[i];
            j+=2;
        }
        else{
            s2[j] = s1[i]; 
            j++;
        }
    }

    // ciclo di stampa output
    printf("Stringa con vocali duplicate: ");
    for(int i = 0; i < j;  i++){
        printf("%c", s2[i]);
    }
    return 0;
}