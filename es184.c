#include <stdio.h>

int higherdigit(int, int);

int main(){
	int a, b, r;
	
	do{
		scanf("%d",&a);
	}while(a<0);
	do{
		scanf("%d",&b);
	}while(b<0);
	
	r=higherdigit(a,b);
	
	printf("%d", r);
	
	return 0;
}

int higherdigit(int n1, int n2){
    if(n1 == 0 && n2 == 0){
        return 0;
    }

    if((n1 != 0 && n2 == 0) || (n1 == 0 && n2 != 0)){
        return -1;
    }

    int massimo = 0;

    while (n1 > 0 && n2 > 0)
    {
        int cifra_n1 = n1 % 10;
        int cifra_n2 = n2  % 10;

        if(cifra_n1 > massimo){
            massimo = cifra_n1;
        }

        if(cifra_n2 > massimo){
            massimo = cifra_n2;
        }

        n1 = n1 / 10;
        n2 = n2 / 10;
    }
    
    if(n1 == 0 && n2 == 0){
        return massimo;
    } else {
        return -1;
    }
}