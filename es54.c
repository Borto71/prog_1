#include <stdio.h>

int iterativa(int, int);
int ricorsiva(int, int);

int iteratativa(int a, int b){
    int temp;
    while (b != 0)
    {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int ricorsiva(int a, int b){
    if(b == 0)
        return a;
    
    return ricorsiva(b, a % b);
}


int main(){
    int n1 = 9;
    int n2 = 21;

    int i = iteratativa(n1, n2);
    int r = ricorsiva(n1, n2);

    printf("Iterativa: %d\n", i);
    printf("Ricorsiva: %d\n", r);

}