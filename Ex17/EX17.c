/*
  Nome: Gabriel R.
	Data: 17/09/2025
  
	Programas com operaÃ§Ãµes para exemplificar operaÃ§Ãµes 
	em listas simplesmente encadeadas 
	

*/
#include "ex17func.h"
#include <stdio.h>
#include <stdlib.h>



/* Função Main */
int main() {
	/* Declaração das variÃ¡veis */

	cel *L = NULL; /* Cria uma lista vazia*/

	/* Insere os elementos do exemplo */
	insereFim(&L, 10);
	insereFim(&L, 25);
	insereFim(&L, 30);
	insereFim(&L, 40);
	insereFim(&L, 50);
	
	printf("\nLista original: ");
	imprimeLista(L);

	/* Chama a função para NOVA */
	removeNesimo(&L, 3);
	imprimeLista(L);
	removeNesimo(&L, 1);
	imprimeLista(L);
	removeNesimo(&L, 3);
	imprimeLista(L);
	removeNesimo(&L, 2);
	imprimeLista(L);
	removeNesimo(&L, 1);
	imprimeLista(L);
	removeNesimo(&L, 1);
	
	printf("\nLista apaga função: ");
	imprimeLista(L);

	/* Libera a memÃ³ria da lista */
	liberaLista(&L);

	return 0;
}