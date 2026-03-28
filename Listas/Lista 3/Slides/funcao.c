#include <stdlib.h>
#include <stdio.h>
#include "funcao.h"


void gerarrandom(int n){
    int n, aux;
    FILE *arq;

    arq = fopen("saida.txt", "w");
    if(arq==NULL){
        printf("Erro ao abrir ou gerar arquivo\n\n");
    }else{
        while(n>0){
            aux = rand()%100;
            printf("%d\n", aux);
            fprintf(arq, "%d\n", aux);
            n--;
        }
        
        fclose(arq);
        printf("arquivo gerado com sucesso");
    }
    
}