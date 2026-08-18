#include <stdio.h>

int main(){
    FILE* fin;
    FILE* fout;
    int n;

    fin = fopen("ciao.txt", "r");
    fout = fopen("copia.txt", "w");

    if(fin && fout){
        fscanf(fin, "%d", &n);
        while (!feof(fin))
        {
            fprintf(fout, "%d ", n * 10);
            fscanf(fin, "%d ", &n);
        }
        fclose(fin);
        fclose(fout);

    }else{
        printf("Errore nell'apertura dei file\n");
    }
}