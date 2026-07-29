#include <stdio.h>
#define MAX 31

typedef struct 
{
    int giorni;
    int ore;
    int minuti;
    int secondi;
}Temporale;

int main(){
    Temporale temporali[MAX];
    int intervalli = 0;
    int tot_ore = 0;
    int tot_minuti = 0;
    int tot_secondi = 0;
    int tot_giorni = 0;

    // Inserimento degli intervalli
    printf("Inserire quanti intervalli si desidera inserire (massimo 31): ");
    scanf("%d", &intervalli);

    while(intervalli <= 0 || intervalli >= 31){
        printf("ERRORE: Inserire quanti intervalli si desidera inserire (massimo 31): ");
        scanf("%d", &intervalli);
    }

    for(int i = 0; i < intervalli; i++){
        printf("Inserimento dell'intervallo n%d\n", i);
        printf("Inserire l'ora (0-23): ");
        scanf("%d", &temporali[i].ore);

        // controllo che l'ora sia inserita giusta
        while (temporali[i].ore < 0 || temporali[i].ore > 23)
        {
            printf("ERRORE: Inserire l'ora (0-23): ");
            scanf("%d", &temporali[i].ore);
        }

        printf("Inserire il minuto (0-59): ");
        scanf("%d", &temporali[i].minuti);

        // controllo che il minuto sia inserita giusta
        while (temporali[i].minuti < 0 || temporali[i].minuti > 59)
        {
            printf("ERRORE: Inserire il minuto (0-59): ");
            scanf("%d", &temporali[i].minuti);
        }

        printf("Inserire il secondo (0-59): ");
        scanf("%d", &temporali[i].secondi);

        // controllo che il secondo sia inserita giusta
        while (temporali[i].secondi < 0 || temporali[i].secondi > 59)
        {
            printf("ERRORE: Inserire il secondo (0-59): ");
            scanf("%d", &temporali[i].secondi);
        }
        
        temporali[i].giorni = 0;
    }

    // Ora sommo tutti gli intervalli
    for(int i = 0; i < intervalli; i++){
        tot_ore += temporali[i].ore;
        tot_minuti += temporali[i].minuti;
        tot_secondi += temporali[i].secondi;
    }

    // Normalizziamo il tempo, quindi calcoliamo i minuti extra dai secondiù
    tot_minuti += tot_secondi / 60;
    tot_secondi += tot_secondi % 60;

    // Ora le ore dai minuti
    tot_ore += tot_minuti / 60;
    tot_minuti += tot_minuti % 60;

    // Ora i giorni dalle ore
    tot_giorni += tot_ore / 24;
    tot_ore += tot_ore % 24;

    printf("\nRisultato totale: %d giorno/i, %d ora/e, %d minuto/i e %d secondo/i.\n", tot_giorni, tot_ore, tot_minuti, tot_secondi);
}
