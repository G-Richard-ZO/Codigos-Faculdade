#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char pal[51];
    int conta;
    struct cel *prox; 
}cel;

int buscapal(cel lst[], int n, char pal[51]);

int main (){
    cel lst[100];
    char aux[51];
    FILE *arq;
    int n=0, i;

    arq = fopen("teste.txt", "r");
    if(arq==NULL){
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    while(!feof(arq)){
        fscanf(arq, "%s", aux);
        lst[n].conta=1;
        n++;
    }

    for(i=0;i<n;i++){
        printf("Palavra: %s\nQnt: %d", lst[i].pal, lst[i].conta);
    }



    return 0;
}

/*      BUSCA PALAVRA       */
int buscapal(cel lst[], int n, char pal[51]){
    if(n==-1)
        return -1;
    if(strcmp(lst[n].pal, pal)==0)
        return n;
    buscapal(lst, n-1, pal[51]);
}