#include <stdio.h>
#include <string.h>
#define LEN 30

int main(){
    char s1[LEN];
    char s2[LEN];
    char s3[LEN + LEN];


    printf("Inserire la prima stringa: ");
    scanf("%s", s1);

    printf("\nInserire la seconda stringa: ");
    scanf("%s", s2);

    strcat(s1, s2);
    strcpy(s3, s1);
    printf("Le stringhe concatenate sono: %s\n", s3);

}