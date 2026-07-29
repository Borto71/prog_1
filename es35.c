#include <stdio.h>
#define MAX 50

int main(){
    char s1[MAX];
    char s2[MAX];
    int j = 0;

    printf("Inserire la stringa: ");
    scanf("%s", s1);

    // copio s1 dentro s2 e se è una vocale non la copio
    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'){
            
        }else{
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = '\0';

    printf("La nuova stringa è: %s\n", s2);
    return 0;
}