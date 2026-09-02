#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
	int num;
	struct nodo *next;
}node;


//prototipi, è possibile aggiungere funzioni
void visualizza(node *);
node* unione(node *, node*);
node* inserisciincoda(node*, int);

int main(){
	node *l1=NULL;
	node *l2=NULL;
	node *l;
	int val;
	
	scanf("%d",&val);
	while(val!=-99){
		l1=inserisciincoda(l1,val);
		scanf("%d",&val);
	}
	visualizza(l1);	
	scanf("%d",&val);
	while(val!=-99){
		l2=inserisciincoda(l2,val);
		scanf("%d",&val);
	}
	visualizza(l2);
	
	l=unione(l1,l2);
	visualizza(l);
	
	return 0;
}


void visualizza(node* lista){
  while(lista != NULL){
    if(lista->next!= NULL)
		printf("%d -> ", lista->num);
	else 
		printf("%d", lista->num);
    lista = lista->next;
  }
  printf("\n");  
}


node* inserisciincoda(node* lista, int num){
    if(lista == NULL){
        node *nuovo_nodo = malloc(sizeof(node));
        nuovo_nodo->num = num;
        nuovo_nodo->next = NULL;
        return nuovo_nodo;
    }

    lista->next = inserisciincoda(lista->next, num);

    return lista;
}

node* unione(node *l1, node *l2){
    node *nuova_lista = NULL;
    int ultimo_inserito = 0;
    int candidato;

    while (l1 != NULL || l2 != NULL)
    {
        if(l1 == NULL){
            candidato = l2->num;
            l2 = l2->next;
        }

        else if(l2 == NULL){
            candidato = l1->num;
            l1 = l1->next;
        }

        else if(l1->num < l2->num){
            candidato = l1->num;
            l1 = l1->next;
        } else {
            candidato = l2->num;
            l2 = l2->next;
        }

        int da_scartare = 0;
        if(nuova_lista != NULL && candidato % 2 != 0 && candidato == ultimo_inserito){
            da_scartare = 1;
        }

        if(da_scartare == 0){
            nuova_lista = inserisciincoda(nuova_lista, candidato);
            ultimo_inserito = candidato;
        }
    } 

    return nuova_lista;
}


