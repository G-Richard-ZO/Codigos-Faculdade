#ifndef EX17FUNC_H
#define EX17FUNC_H


/* Definição de tipo */
typedef struct cel{ 
	int num;
	struct cel *prox;
}cel;

/* Funções */
void insereFim(cel **L, int x);

void insereNesimo();

void removeNesimo(cel **L, int n);

void imprimeLista(cel *L);

void liberaLista(cel **L);






#endif