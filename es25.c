#include <stdio.h>

int chiedi_numero();

int main() {
    int res = chiedi_numero();
    printf("Il numero inserito è: %d\n", res);
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
