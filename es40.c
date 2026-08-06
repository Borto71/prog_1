#include <stdio.h>
#include <string.h>
#define LEN 50

int main(){
    char s1[LEN];
    char s2[LEN];
    printf("Inserire una stringa: ");
    scanf("%s", s1);

    strcpy(s2, s1); // copio la stringa di s1 in s2

    for(int i = 0; s2[i] !=  '\0'; i++){
        if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u')
            s2[i] = '*';
    }

    printf("La stringa modificata è: %s\n", s2);
}