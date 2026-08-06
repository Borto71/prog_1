#include <stdio.h>

int calcolo(double, double *, double *);

int calcolo(double raggio, double *area, double *perimetro){
    double calcolo_p = 2 * 3.14 * raggio;
    *perimetro = calcolo_p;

    double calcolo_a = 3.14 * (raggio*raggio);
    *area = calcolo_a;
}

int main(){
    double raggio;
    double perimetro, area;
    int scelta = 0;

    do{

        printf("Inserire il raggio del cerchio: ");
        scanf("%lf", &raggio);

        calcolo(raggio, &area, &perimetro);

        printf("\nIl perimetro vale: %lf", perimetro);
        printf("\nL'area vale: %lf", area);

        printf("\nSi vuole continuare con il programma? (0 per continuare, qualsiasi altro numero per terminare)");
        scanf("%d", &scelta);

    }while(scelta == 0);

    printf("ADDIO AMICI ADDIO\n");
    return 0;
  
}