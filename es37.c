#include <stdio.h>
#include <string.h>
#define LEN 30


int main(){
    char s1[LEN+1];
    char s2[LEN+1];

    printf("Inserire una stringa da rovesciare: ");
    scanf("%s", s1);
    int lunghezza = strlen(s1);

    int j = 0;
    for(int i = lunghezza - 1 ; i >= 0; i--){
        s2[j] = s1[i];
        j++;
    }
    s1[j] = '\0';

    printf("La stringa inversa è: %s\n", s2);
}