#include <stdio.h>
#include <stdlib.h>

int main (){

    int i, n, *vet, *p;

    printf("Quantos elementos deseja alocar?\n");
    scanf("%d", &n);

    vet=(int*) malloc(n*sizeof(int));
    if(vet==NULL){
        printf("\nErro na alocação\n");
        return 0;
    }

    for(i=0;i<n;i++)
        scanf("%d", (vet+i));/*Mesma coisa q o scanf &vet[i]*/
    
    for(i=0;i<n;i++)
        printf("%d", *(vet+i));/*Mesma coisa q o printf vet[i]*/
    printf("\n");

    p=vet;/*p recebe o valor onde vet esta alocado*/
    

    for(i=0;i<n;i++)
        printf("%d", *(p+i));/*Mesma coisa q o printf vet[i]*/
    printf("\n");

    for(p=vet;p<(vet+n);p++)
        printf("%d", *p);/*Mesma coisa q o printf vet[i]*/
    printf("\n");

    free(vet);
}