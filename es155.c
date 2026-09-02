#include<stdio.h>
#include<string.h>
#define DIM 25

/* prototipi delle funzioni */
int estrai(char *, char *, char *);
int conta(int);

int main(){
	char nome[20];
	char p,u;
	int num;
	FILE *fid;
	char str2[DIM+1];


	scanf("%s",nome);
	fid=fopen(nome,"r");
	if(fid==NULL)
		printf("Errore apertura file");
	else{
		fscanf(fid,"%s",str2);
		while(!feof(fid)){
			num=estrai(str2,&p,&u);
			printf("%d %c %c %d\n",num,p,u,conta(num));

			fscanf(fid,"%s",str2);
		}
		fclose(fid);
	}
	return 0;

}

//funzione che estrae un numero da una stringa, salva nel parametro prima la prima lettera minuscola trovata e in ultima l'ultima
int estrai(char *s1, char *prima, char *ultima){
    int prima_trovata = 0;

    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] >= 'a' && s1[i] <= 'z'){
            if(prima_trovata == 0){
                prima_trovata = 1;
                *prima = s1[i];
            }
            *ultima = s1[i];
        }
    }

    int risultato = *prima - *ultima;

    if(risultato < 0){
        return risultato * -1;
    } else {
        return risultato;
    }
}


// FUNZIONE RICORSIVA che conta le cifre pari
int conta(int n){
    if(n == 0){
        return 1;
    }

    if(n <= 9){
        if(n % 2 == 0){
            return 1;
        } else {
            return 0;
        }
    }
    
    int cifra = n % 10;
    if(cifra % 2 == 0){
        return 1 + conta(n / 10);
    }

    return 0 + conta(n / 10);
}
