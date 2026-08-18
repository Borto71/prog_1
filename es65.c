#include <stdio.h>
#include <stdlib.h>

struct Studente
{
    int matricola;
    int voto;
};


int main(){
    int n;

    printf("Inserire il numero di studenti che si vogliono registrare: ");
    scanf("%d", &n);

    struct Studente *arrayStudenti = (struct Studente*) malloc(n * sizeof(struct Studente));

    if(arrayStudenti == NULL){
        printf("\nERRORE: la memoria non è stata allocata");
    } else {
        printf("\nSUCCESSO: la memoria è stata allocata");
    }
    
    printf("\nInserire il numero di matricola e il voto degli studenti");
    for(int i = 0; i < n; i++){
        printf("\nInserire il voto dello studente %d: ", i);
        scanf("%d", &arrayStudenti[i].voto);

        printf("\nInserire la matricola dello studente %d: ", i);
        scanf("%d", &arrayStudenti[i].matricola);

    }

    printf("\nStampo la lista degli studenti (con matricola e voto)");
    for(int i = 0; i < n; i++){
        printf("\nStudente con matricola: %d \n     Ha conseguito il voto %d:\n", arrayStudenti[i].matricola, arrayStudenti[i].voto);
    }

    free(arrayStudenti);
}