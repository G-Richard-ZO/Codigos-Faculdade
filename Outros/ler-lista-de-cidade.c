#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[59];
    char estado[3]; /*inserir a sigla do estado*/
    int populacao;
} tcidade;

void lercidade(int n, tcidade lista[n]) {
    int i;
    
    for(i=0; i<n; i++){
        printf("Digite o nome da %d° cidade: ", i+1);
        scanf(" %[^\n]", lista[i].nome);
        printf("Digite a sigla do estado da %d° cidade: ", i+1);
        scanf(" %s", lista[i].estado);
        printf("Digite a populacao da %d° cidade: ", i+1);
        scanf("%d", &lista[i].populacao);
    }
    
}

/* *************************************************************************************************************
                                               MAIN DO CODIGO
************************************************************************************************************* */
int main(){
    tcidade cidades[1000];
    int n;

    printf("Digite o numero de cidades a ser inserido: ");
    scanf("%d", &n);

    lercidade(n, cidades);

    
    return 0;
}