#include <stdio.h>

int somaelementos(int v[], int n){
    if(n==0)
        return 0;
    return v[n-1] + somaelementos(v, n-1);
}

int quantidadeX(int v[], int n, int x){
    if(n==0)
        return 0;
    if(v[n-1]==x)
        return 1 + quantidadeX(v, n-1, x);
    
    return quantidadeX(v, n-1, x);
    
}

int menu() {
    int opcao;

    printf("Menu de Opcoes:\n");
    printf("1. soma de elementos de um vetor. \n");
    printf("2. quantidade de vezes que X aparece no vetor\n");
    printf("3. \n");
    printf("4. \n");
    printf("5. \n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf(" %d", &opcao);

    return opcao;
}


int main() {
    int n=5;
    int v[5];
    int x=3;
    int opcao;

    do{
        opcao = menu();
        switch(opcao){
            case 1: 
                somaelementos(v, n);
            break;

            case 2: 
                quantidadeX(v, n, x);
            break;

            case 3: 
            break;

            case 4: 
            break;

            case 5: 
                
            break;
        }
    }while(opcao != 0);


    return 0;
}