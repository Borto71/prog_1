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
    int len = strlen(s1);
    int car_numerici = 0;

    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] >= '0' && s1[i] <= '9'){
            car_numerici++;
        }
    }

    if(car_numerici >= k && len >= n){
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
        valide += parola_valida(buffer, n, k);
    }
    
    return valide;
}
