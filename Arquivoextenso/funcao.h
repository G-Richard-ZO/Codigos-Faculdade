#ifndef FUNCAO_H
#define FUNCAO_H

typedef struct{
    int num;
    struct cel *prox;
}cel;

void gerarrandom(int n);

void insereFim(cel **L, int x);

void imprimeLista(cel *L);

void liberaLista(cel **L);

void lerbin(int n, cel **L);


#endif