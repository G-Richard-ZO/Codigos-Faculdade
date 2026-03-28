#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"


int main (){
    int n;

    cel *lista=NULL;

    printf("Insira a qtd de numeros aleatorios: \n");
    scanf("%d", &n);

    gerarrandom(n);

    lerbin(n, &lista);

    imprimeLista(lista);
     












    printf("programa finalizado\n\n");
    
    liberaLista(&lista);


    return 0;
}