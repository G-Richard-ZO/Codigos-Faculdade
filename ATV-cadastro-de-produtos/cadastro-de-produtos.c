#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>/*Para a função de pausa*/

typedef struct {
    int cod; /*Código do produto*/
    char nome[30];
    char cat[30];
    int qtd;
    float preco;
} reg_produto;



/*                    FUNÇÕES UTILIZADAS                         */
int menu();
void pausa();
int buscacod(reg_produto produtos[], int n, int cod);


int cadastrarproduto(reg_produto produtos[], int n);

void mostrarprodutos(reg_produto produtos[], int n);


/**************************************************************************************************
 *                                           MAIN DO CODIGO
 *************************************************************************************************/

int main (){

    reg_produto produtos[50];
    int n=0; /*Qntd de produtos*/
    int opcao;

    /*printf("Quantos produtos serão cadastrados ?\n\n\n");
    scanf("%d", &n);
    

    produtos=(reg_produto*) malloc(n*sizeof(reg_produto));
    if(produtos==NULL){
        printf("\nErro na alocação\n");
        return 0;
    }*/


    do{
        opcao = menu();
        switch(opcao){
            case 1: /*Cadastra um novo aluno*/
                n=cadastrarproduto(produtos, n);
            break;


            case 2: /*Remover produtos*/
                /*n=removerprodutos(produtos, n);*/
            break;

            case 3: /*Remover um aluno*/
                /*atualizarproduto(produtos, n);*/
            break;

            case 4: /*Atualizar notas*/
                /*listanome(produtos, n);*/
            break;

            case 5: /*Exibir alunos aprovados*/
                /*listaqtd(produtos, n);*/
            break;
            case 6: /*Exibir alunos aprovados*/
                /*listacategoria(produtos, n);*/
            break;
            case 7: /*Exibir alunos aprovados*/
                printf("\nCodigo\t\tProduto \t\t\tCategoria \t\t\tQuantidade \tPreco\n");
                mostrarprodutos(produtos, n);
                pausa();
            break;
        }
    }while(opcao != 0);
    
    /*free(produtos);*/
    return 0;

}



/*
                            FUNÇÃO MENU

    -Exibe o menu de opções para o usuario.
    -le a opção escolhida, valida ela e a retorna;
    -caso contrario exibe opção inválida e chama a função novamente.
*/
int menu() {
    int opcao;

    printf("\n\n\nMenu de Opcoes:\n");
    printf("1. Cadastrar um novo produto.\n");
    printf("2. Remover um produto.\n");
    printf("3. Atualizar dados do produto.\n");
    printf("4. Listar produtos por nome.\n");
    printf("5. Listar produtos por quantidade.\n");
    printf("6. Listar produtos por categoria.\n");
    printf("7. Mostrar todos produtos cadastrados.\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void pausa(){
    printf("\nAperte qualquer tecla para continuar...\n");
    getch();
}

/* FUNÇÃO BUSCA CODIGO */
int buscacod(reg_produto produtos[], int n, int cod){
    if(n==0)
        return -1;
    if(produtos[n-1].cod == cod)/*é possivel colocar dentro do if um OU n==0 para executar e devolver o -1 mas não compensa*/
        return n-1;             /*o codigo fica mais complicado de emtender*/
    return buscacod(produtos, n-1, cod);
}




/***********************************************************************************
 *                          FUNÇÕES PRINCIPAIS DO CODIGO                           *
 ***********************************************************************************/

 /*
                        FUNÇÃO CADASTRAR PRODUTO

    -Recebe a lista de alunos e o total de alunos cadastrados.
    -le primeiro o RGA, e verifica se já existe um cadastro com esse RGA;
        -se já existir um cadastro, notifica o usuário e pede outro RGA;
        -se não, inclui o RGA no vetor de alunos e continua o cadastro.
    -Lê o nome do aluno;
    -Lê as 3 notas do aluno e já calcula a média;
    -Por último define pela media se o aluno está aprovado ou reprovado.
    -Adiciona +1 ao total de alunos cadastrados.
*/

int cadastrarproduto(reg_produto produtos[], int n){
    int cod, pos_busca;
    if(n == 50){
        printf("\n\nMaximo de produtos cadastrados, exclua algum produto antes de tentar novamente.\n");
    }else{
        printf("\n\nBem vindo ao cadastro de produtos!\n");
        
        printf("\nPor favor insira o codigo do produto a ser cadastrado:\n");
        scanf("%d", &cod);
        pos_busca=buscacod(produtos, n, cod);
        if(pos_busca != -1){
            printf("\nO codigo do produto inserido ja esta cadastrado!\nPor favor insira outro codigo de produto.\n");
        }else{
            produtos[n].cod = cod;
            printf("Insira o nome do produto:");
            scanf(" %[^\n]", produtos[n].nome);
            printf("Insira a categoria do produto:");
            scanf(" %[^\n]", produtos[n].cat);
            printf("Insira a quantidade desse produto:");
            scanf("%d", &produtos[n].qtd);
            printf("Insira o valor do produto:");
            scanf("%f", &produtos[n].preco);
            
            n++;
            return n;
        }
    }
}

/*              FUNÇÃO REMOVE PRODUTO                        */
void removealuno(reg_produto alunos[], int n){
    int cod, pos_busca, i;
    do{
        printf("\nPor favor insira o RGA do aluno que será removido:\n");
        scanf("%d", &cod
        pos_busca=buscacod(alunos, n, cod);
        if(pos_busca == -1){
            printf("\nO RGA inserido nao esta cadastrado!\nPor favor insira outro RGA.\n");
        }else{
            for(i=pos_busca; i<n-1; i++){
                produtos[i] = alunos[i+1]; /*Desloca os elementos para a esquerda*/
            }
            (*n)--; /*Diminui o total de alunos cadastrados*/
            printf("\nAluno com RGA %d removido com sucesso!\n", cod);
        
        }
    }while(pos_busca != -1);
}






void mostrarprodutos(reg_produto produtos[], int n){
    if(n>0){
        printf("\n%d\t\t%s \t\t\t%s\t\t\t%d\t%.2f", 
            produtos[n-1].cod,
            produtos[n-1].nome,
            produtos[n-1].cat,
            produtos[n-1].qtd,
            produtos[n-1].preco);

        mostrarprodutos(produtos, n-1);
    }
        
    
    
    
    
}