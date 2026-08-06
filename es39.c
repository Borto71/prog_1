#include <stdio.h>
#include <string.h>
#define LEN 30

int main(){
    char s1[LEN];
    char s2[LEN];

    printf("Inserire la prima stringa: ");
    scanf("%s", s1);

    printf("Inserire la seconda stringa: ");
    scanf("%s", s2);

    int diverse = strcmp(s1, s2);

    if(diverse == 0)
        printf("Le stringhe sono uguali\n");
    else
        printf("Le stringhe sono diverse\n");
}