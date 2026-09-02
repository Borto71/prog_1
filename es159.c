#include <stdio.h>
#include <stdlib.h>
#define SEP ','
#define DIM 50
/*definizione della struttura per la lista concatenata*/
typedef struct elem_{
  int num;
  struct elem_ *next;
} elem;

/*prototipi delle funzioni*/
elem* crealista(char*, char);
void visualizza(elem*);

int main(){
	char str[DIM+1];
	elem* lista;
	
	scanf("%s",str);
	lista=crealista(str,SEP);
	visualizza(lista);
}


/* visualizza i numeri contenuti nella lista */
void visualizza(elem* lista){
  while(lista != NULL){
    if(lista->next != NULL)
			printf("%d -> ", lista->num);
		else printf("%d", lista->num);
    lista = lista->next;
  }
  printf("\n");  
}

/* analizza la stringa e inserisce un nuovo numero in coda alla lista */
elem* crealista(char *str, char sep){
    elem *testa = NULL;
    elem *coda = NULL;
    int numero = 0;

    for(int i = 0; ;i++){
        if(str[i] == sep || str[i] == '\0'){
            elem *nuovo_elemento = malloc(sizeof(elem));
            nuovo_elemento->num = numero;
            nuovo_elemento->next = NULL;

            if(testa == NULL){
                testa = nuovo_elemento;
                coda = nuovo_elemento;
            } else {
                coda->next = nuovo_elemento;
                coda = nuovo_elemento;
            }

            numero = 0;

            if(str[i] == '\0'){
                break;
            }
        } else {
            numero = numero * 10 + (str[i] - '0');
        }
    }

    return testa;
}