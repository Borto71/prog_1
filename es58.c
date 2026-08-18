#include <stdio.h>  

int main(){
    FILE* fin;
    FILE* fout;
    int n;

    fin = fopen("files/misure.txt", "r");
    fout = fopen("files/allarmi.txt", "w");

    if(fin && fout){
        fscanf(fin, "%d", &n);
        while (!feof(fin))
        {
            if(n > 50)
                fprintf(fout, "%d ", n);

            fscanf(fin, "%d", &n);
        }
        
        fclose(fin);
        fclose(fout);

    } else{
        printf("Errore nell'apertura dei file");
    }
}