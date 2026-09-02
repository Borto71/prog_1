#include <stdio.h>
#define N 5

void somme_prefisse(int *a, int , int *b);

int main()
{
	int a1[N];
	int b1[N] = {0};
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a1[i]);
	}
	somme_prefisse(a1, 5, b1);
	
	for (i = 0; i < N; i++)
	{
		printf("%3d", b1[i]);
	}
	return 0;
}

void somme_prefisse(int *a, int num, int *b){
    if(num == 0){
        return;
    }

    somme_prefisse(a, num - 1, b);

    int i = num - 1;

    if(i == 0){
        b[i] = a[i];
    } else {
        b[i] = b[i - 1] + a[i];
    }
}
