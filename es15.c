# include <stdio.h>
# define MAX_GRADO 8

int main(){
    int grado1, grado2, grado_ris;
    double p1[MAX_GRADO + 1] = {0};
    double p2[MAX_GRADO + 1] = {0};
    double result[MAX_GRADO * 2 + 1] = {0};

    // Inserimento del grado del primo polinomio
    printf("Inserire il grado del primo polinomio: ");
    scanf("%d", &grado1);
    if(grado1 < 0 || grado1 > MAX_GRADO){
        printf("ERRORE: Il grado deve essere maggiore di 0 e minore di %d", MAX_GRADO);
        return 1;
    }

    // Inserimento dei coefficienti del primo polinomio
    printf("Inserire i coefficienti del primo polinomio\n");
    for(int i = 0; i <= grado1; i++){
        printf("Inserire il coefficiente di x^%d: ", i);
        scanf("%lf", &p1[i]);
    }

    // Inserimento del grado del secondo polinomio
    printf("Inserire il grado del secondo polinomio: ");
    scanf("%d", &grado2);
    if(grado2 < 0 || grado2 > MAX_GRADO){
        printf("ERRORE: Il grado deve essere maggiore di 0 e minore di %d", MAX_GRADO);
        return 1;
    }

    // Inserimento dei coefficienti del secondo polinomio
    printf("Inserire i coefficienti del primo polinomio\n");
    for(int i = 0; i <= grado2; i++){
        printf("Inserire il coefficiente di x^%d: ", i);
        scanf("%lf", &p2[i]);
    }

    grado_ris = grado1 + grado2; // calcolo il grado del risultato

    for(int i = 0; i <= grado1; i++){
        for (int j = 0; j <= grado2; j++){
            result[i + j] += p1[i] * p2[j];

        }
    }

    printf("-- Risultato -- \n");
    printf("Il polinomio prodotto ha grado: %d \n", grado_ris);
    for(int i = 0; i <= grado_ris; i++){
        printf("Coefficiente di x^%d: %lf\n", i, result[i]);
    }

    return 0;
}