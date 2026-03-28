/*
Nome: Gabriel Richard
RGA:  2025.0743.013-0
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>/*Para a função de pausa*/

#define MAX 5

typedef struct {
    int cod; /*Código do produto*/
    char nome[30];
    char cat[30];
    int qtd;
    float preco;
    struct reg_produto *prox;
}reg_produto;
/*INSERE LISTA DINAMICA*/
void inserelista(reg_produto **produtos, reg_produto temp){

    reg_produto *p, *q, *novo;
    p=NULL; q=*produtos;

    while(q!=NULL && q->cod != temp.cod){
        p=q;
        q=q->prox;
    }

    if(q==NULL){
        novo = (reg_produto *) malloc(sizeof(reg_produto));
        if(novo==NULL){
        printf("\nErro na alocação dos produtos.\n");
        return;
    }
        novo->cod=temp.cod;
        strcpy(novo->nome, temp.nome);
        strcpy(novo->cat, temp.cat);
        novo->qtd=temp.qtd;
        novo->preco=temp.preco;
        novo->prox=NULL;

        if(p!=NULL){
            p->prox = novo;
        }else{
            *produtos=novo;
        }
    }else{
        printf("O produto %d ja esta cadastrado na lista", temp.cod);
    }  

}


void inserefila(int lst[MAX], int *f){
    int temp;

    if(*f==MAX-1){
        printf("Fila cheia !\n");
    }else{
        printf("Digite o numero a ser inserido: ");
        scanf("%d", &temp);
        lst[*f%5]=temp;
        (*f)++;
    }
}

int removefila(int lst[MAX], int *i, int f){
    if(f==*i){
        printf("Fila Vazia !\n");

    }
}

int main(){
    int fila[MAX];
    int i=0, f=0;



    return 0;
}