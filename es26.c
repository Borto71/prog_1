#include <stdio.h>

int chiedi_numero();

int main() {
    int res1 = chiedi_numero();
    int res2 = chiedi_numero();
    printf("Il primo numero inserito è: %d\nIl secondo numero inserito è: %d\n", res1, res2);
    return 0; 
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
