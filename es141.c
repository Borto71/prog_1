#include <stdio.h>
int coppiei(int);


int main(){
	int a,r;
	
	do{
		scanf("%d",&a);
	}while(a<0);
	
	r=coppiei(a);
	
	printf("%d",r);
	
	return 0;
}

int coppiei(int num){
    int coppie = 0;

    if(num < 10){
        return 0;
    }

    int cifra1 = num % 10;
    int cifra2 = (num / 10) % 10;

    if(cifra1 == cifra2){
        coppie++;
    }

    return coppie + coppiei(num / 10);
}
