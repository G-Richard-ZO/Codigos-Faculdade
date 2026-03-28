#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcao.h"



int main (){

    int n;

    printf("Insira a qtd de numeros aleatorios: \n");
    scanf("%d", &n);

    gerarrandom(n);
    printf("programa finalizado\n\n");
    


    return 0;
}