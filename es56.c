#include <stdio.h>

int main(){
    FILE* fp;
    int n;
    int somma = 0;
    fp = fopen("ciao.txt", "r");

    if(fp){
        fscanf(fp, "%d", &n);
        while (!feof(fp))
        {
            somma += n;
            printf("%d ", n + somma);
            fscanf(fp, "%d ", &n);
        }

        fclose(fp);

    }else{
        printf("Errore nell'apertura del file!");
    }
}