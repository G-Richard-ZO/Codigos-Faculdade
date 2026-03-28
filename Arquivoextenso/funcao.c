#include <stdlib.h>
#include <stdio.h>
#include "funcao.h"


void gerarrandom(int n){
    int aux;
    FILE *arq;

    arq = fopen("saida.bin", "wb");
    if(arq==NULL){
        printf("Erro ao abrir ou gerar arquivo\n\n");
    }else{
        while(n>0){
            aux = rand()%100;
            printf("%d\n", aux);
            /*fprintf(arq, "%d\n", aux);*/
            fwrite(&aux, sizeof(int), 1, arq);
            n--;
        }
        
        fclose(arq);
        printf("arquivo gerado com sucesso\n");
    }
    
}


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
printf("\nnum:%d  inserido na lista.", novo->num);
}

void ordenapar(cel **L, cel **Lpar, cel **Limpar){
    cel *p, *par, *impar;

    p=L;
    par=Lpar;
    impar=Limpar;

    if(L==NULL){
        printf("Lista Vazia !");
    }else{
        while(p->prox!=NULL){
            if(p->num % 2 == 0){ /*Verifica se é par*/
                if(par==NULL){
                    
                }
            }

            p = p->prox;
        }
    }
    
}

void imprimeLista(cel *L){
	cel *p;

	printf("\nElementos da lista:\n");
	
	for(p = L; p!=NULL; p = p->prox){
		printf("\n%d", p->num);
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

void lerbin(int n, cel **L){

    char namearq[500];
    int buffer[500], nlidos, i;
    FILE *arq;

    printf("insira o nome do arquivo a ser lido:\n");
    scanf("%s", namearq);

    arq = fopen(namearq, "rb");

    if(arq==NULL){
        printf("erro ao abrir o arquivo\n\n");
    }else{
        printf("arquivo aberto com sucesso\n\n");

        nlidos = fread(buffer, sizeof(int), n, arq);

        printf("Foram lidos %d numeros\n\n", nlidos);
        for(i = 0; i<nlidos; i++){
            insereFim(L, buffer[i]);
            /*printf("%d\n", buffer[i]);*/
        }

        fclose(arq);
    }
}



