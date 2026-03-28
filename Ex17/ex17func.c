#include <stdio.h>
#include <stdlib.h>
#include "ex17func.h"


void insereFim(cel **L, int x){
	cel *p, *novo;

	novo = (cel*) malloc(sizeof(cel));
	if(novo == NULL){
		printf("\nErro ao alocar novo elemento na lista.");
		return;
	}
	novo->num = x;
	novo->prox = NULL;
	
	if(*L == NULL){
		*L = novo;
	}
	else{
		p = *L;
		while(p->prox != NULL){
			p = p->prox;
		}
		p->prox = novo;
	}
	printf("\n MEM:%p (num:%d - prox: %p) inserido na lista.",novo, novo->num, novo->prox);
}

void insereNesimo(){
    
}

void removeNesimo(cel **L, int n){
    cel *p, *q;
    int conta;
    
    p=NULL;
    q = *L;
    /*caso lista for vazia ele não executa a função*/
    if(q==NULL){
        printf("\nLista Vazia.\n\n");
    }else{
        /*Remove o primeiro elemento
            Faz o ponteiro L apontar para o proximo elemento*/
        if(n==1){
            *L=q->prox;
            printf("\n MEM:%p (num:%d - prox: %p) liberado",q, q->num, q->prox);
        }else{
            conta=1;
            while(conta!=n && q!=NULL){
                p = q;
                q = q->prox;
                conta++;
            }
            
            if(q==NULL){
                printf("\n\nA lista não possui o elemento %d\nNenhum elemento apagado.\n\n", n);
            }else{
                p->prox = q->prox;
                printf("\n\n MEM:%p (num:%d - prox: %p) liberado\n\n",q, q->num, q->prox);
                free(q);
            }
            
            
        }

    }
        
    
    
}

void imprimeLista(cel *L){
	cel *p;

	printf("\nElementos da lista:");
	
	for(p = L; p!=NULL; p = p->prox){
		printf("\n MEM:%p (num:%d - prox: %p)", p, p->num, p->prox);
	}
	printf("\n");
}

void liberaLista(cel **L){
	cel *p;

	while(*L!=NULL){
		p = *L;
		(*L) = (*L)->prox;
		printf("\n MEM:%p (num:%d - prox: %p) liberado",p, p->num, p->prox);
		free(p);
	}
	printf("\n Lista Liberada.");
}