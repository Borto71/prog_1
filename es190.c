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
        node *nuovo = malloc(sizeof(node));
        nuovo->num = num;
        nuovo->next = NULL;
        
        return nuovo;
    }

    lista->next = inserisciincoda(lista->next, num);
    return lista;
}

node* unione(node *l1, node *l2){
    node *nuovo = NULL;
    int ultimo_inserito = 0;
    int candidato;
    
    while(l1 != NULL || l2 != NULL){
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

        int scartare = 0;

        if(candidato % 2 != 0 && nuovo != NULL && candidato == ultimo_inserito){
            scartare = 1;
        }

        if(scartare == 0){
            nuovo = inserisciincoda(nuovo, candidato);
            ultimo_inserito = candidato;
        }
    }

    return nuovo;
}


