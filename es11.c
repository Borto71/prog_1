# include <stdio.h>

int main() {
    char carattere;
    int vocali = 0;
    printf("Inserisci un carattere (per terminare l'isnerimento usa #): ");
    scanf("%c", &carattere);

    while (carattere!= '#')
    {   
        //controllo che sia una vocale
        if(carattere == 'a' || carattere == 'e' || carattere == 'i' || carattere == 'o' || carattere== 'u'){
            vocali++;
        } 
        scanf("%c", &carattere);
    }
    
    printf("Le vocali inserite sono: %d \n", vocali);
}
