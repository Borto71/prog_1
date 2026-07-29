#include <stdio.h>

int chiedi_numero();
int fattoriale(int);

int fattoriale(int num){
    int risultato = 1;
    for(int i = 1; i <= num; i++){
        risultato = risultato * i;
    }

    return risultato;
}

int chiedi_numero(){
    int numero;
    printf("Inserire un numero: ");
    scanf("%d", &numero);

    // controllo che non sia negativo
    while(numero < 0){
        printf("ERRORE: Il numero è negativo");
        scanf("%d", &numero);
    }
    
    return numero;
}

int main(){
    int binomiale;
    int n = chiedi_numero();
    int k = chiedi_numero();

    binomiale = fattoriale(n) / (fattoriale(k) * fattoriale(n - k)); // calcolo del binomiale
    printf("Il binomiale (n=%d | k=%d) è: %d\n", n, k, binomiale);
}