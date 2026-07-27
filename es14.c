# include <stdio.h>
# define N 10
int main() {
    int n[N];

    // inserimento da tastiera
    for(int i = 0; i < N; i++){
        printf("Inserire il %d valore: ", i+1);
        scanf("%d", &n[i]);
    }

    // calcolo la somma con il precedente
    for(int i = 0; i< N; i++){
        if(i == 0){
            printf("Saltato da consegna\n");
        }else{
        int somma = n[i] + n[i - 1];
        printf("La somma con il precedente dell'iterazione %d è: %d \n", i, somma);
        }
    }
}
