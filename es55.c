#include <stdio.h>

int main(){
    FILE* fp;

    fp = fopen("ciao.txt", "w");

    if(fp){
        for(int i = 2; i <= 10; i = i+2){
            fprintf(fp, "%d\n", i);
        }

        fclose(fp);

    }else{
        printf("\nErrore nell'apertura del file!\n");
    }
}