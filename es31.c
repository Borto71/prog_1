#include <stdio.h>
# define N 2

float media(int, int);

float media(int num1, int num2){
    float media = (num1 + num2) / 2.0;

    return media;
}

int main(){
    int coppia1[N];
    int coppia2[N];
    float media1;
    float media2;

    // Inserimento della prima coppia
    for(int i = 0; i < N; i++){
        printf("Inserire il %d numero della prima coppia: ", i);
        scanf("%d", &coppia1[i]);
    }

    // Inserimento della seconda coppia 
    for(int i = 0; i < N; i++){
        printf("Inserire il %d numero della seconda coppia: ", i);
        scanf("%d", &coppia2[i]);
    }

    // calcolo delle media
    media1 = media(coppia1[0], coppia1[1]);
    media2 = media(coppia2[0], coppia2[1]);
    printf("La prima coppia ha media: %f\nLa seconda coppia ha media: %f", media1, media2);
}