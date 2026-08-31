#include <stdio.h>
#include <string.h>
#define DIM 25

/*prototipi delle funzioni*/
int parola_valida(char*,int,int);
int conta_valide(int,int);

int main(){
	int num;
	int ncar, ncifre;
	scanf("%d",&ncar);
	scanf("%d",&ncifre);
	num=conta_valide(ncar,ncifre);
	printf("%d\n",num);

}


int parola_valida(char *s1, int n, int k){
    int cifre = 0;
    int caratteri = strlen(s1);

    for(int i = 0; i < caratteri; i++){
        if(s1[i] >= '0' && s1[i] <= '9'){
            cifre++;
        }
    }

    if(cifre >= k && caratteri >= n){
        return 1;
    } else {
        return 0;
    }
}

int conta_valide(int n, int k){
    FILE *fp;
    char buffer[DIM];
    int valide = 0;

    fp = fopen("origine.txt", "r");

    if(fp == NULL){
        return -1;
    }

    while (fscanf(fp, "%s", buffer) == 1)
    {
        if(parola_valida(buffer, n, k) == 1){
            valide++;
        }
    }
    
    fclose(fp);
	return valide;
}
