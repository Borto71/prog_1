#include<stdio.h>
#define DIM 10

/* prototipi */
int crea(int *,int *);
int somma(int);

int main() {
  int ar1[DIM], ar2[DIM], i,r;
	for(i=0; i<DIM; i++){
		scanf("%d",&ar1[i]);
	}

  r=crea(ar1,ar2);
  printf("%d",r);
  
  return (0);
}

int crea(int *a1, int *a2){
    int inseriti = 0;

    for(int i = 0; i < DIM; i++){
        int somma_cifre = somma(a1[i]);
        int trovato = 0;

        for(int j = 0; j < inseriti; j++){
            if(a2[j] == somma_cifre){
                trovato = 1;
                break;
            }
        }

        if(trovato == 0){
            a2[inseriti] = somma_cifre;
            inseriti++;
        }
    }

    return inseriti;
}

int somma(int num){
    if(num == 0){
        return 0;
    }

    int cifra = num % 10;
    return cifra + somma(num / 10);
}
