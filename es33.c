#include <stdio.h>
#include <math.h>
#define LEN 31
#define LOC 10

typedef struct
{
    int longitudine;
    int latitudine;
    char nome[LEN];
}Localita;

int main(){
    Localita mappa[LOC];
    int max_dist_quadrata = -1;
    float max_dist_effettiva;
    int coppie_max[45][2];

    // Inserimento dei dati da tastiera
    for(int i = 0; i < LOC; i++){
        printf("-- Inserire la località numero %d --\n", i + 1);
        printf("Nome: ");
        scanf(" %c", &mappa[i].nome);

        printf("Longitudine: ");
        scanf(" %c", &mappa[i].longitudine);

        printf("Latitudine: ");
        scanf(" %c", &mappa[i].latitudine);
    } 

    // calcolo la distanza tra due punti
    for(int i = 0; i < LOC; i++){
        for(int j = i + 1; j < LOC; j++){
            int dx = mappa[i].longitudine - mappa[j].longitudine;
            int dy = mappa[i].latitudine - mappa[j].latitudine;

            int distanza_quadrata = (dx * dx)+ (dy * dy);

            if(distanza_quadrata > max_dist_quadrata){
                max_dist_quadrata = distanza_quadrata;

                max_dist_effettiva = sqrt((float)max_dist_quadrata);
            }else if(distanza_quadrata == max_dist_quadrata){
                ...
            }
        }
    }
}