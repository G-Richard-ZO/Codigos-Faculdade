/*
Nome: Gabriel Richard
RGA:  2025.0743.013-0
*/


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

typedef struct {
    char cat[30];
    int qtd;
} reg_cat;



/*                    FUNÇÕES UTILIZADAS                         */
int menu();
int menualtera();
void pausa();
int buscacod(reg_produto produtos[], int n, int cod);                                   /* FUNÇÃO RECURSIVA    */
int buscacat(reg_cat categorias[], int ncat, reg_produto produtos[], int pos);          /* FUNÇÃO RECURSIVA    */
void ordenaNome(reg_produto produtos[], int n);
void ordenaqtd(reg_produto produtos[], int n);
int ordenacat(reg_produto produtos[], int n, reg_cat categorias[]);

int cadastrarproduto(reg_produto produtos[], int max, int n);
int removerprodutos(reg_produto produtos[], int n);
void atualizarprodutos(reg_produto produtos[], int n);
void mostrarprodutos(reg_produto produtos[], int n);                                    /*  FUNÇÃO RECURSIVA    */
void mostrarcat(reg_cat categorias[], int n);                                           /*  FUNÇÃO RECURSIVA    */


/**************************************************************************************************
 *                                           MAIN DO CODIGO
 *************************************************************************************************/

int main (){

    reg_produto *produtos;
    reg_cat *categorias;/*tipo de variavel para monitorar o total de qtd por categoria*/
    int n=0, max; /*Qntd de produtos cadastrados*/
    int ncat; /*Qntd de categorias cadastradas*/
    int opcao;

    printf("Quantos produtos serão cadastrados ?");
    scanf("%d", &max);
    

    produtos=(reg_produto*) malloc(max*sizeof(reg_produto));
    if(produtos==NULL){
        printf("\nErro na alocação dos produtos.\n");
        return 0;
    }

    categorias=(reg_cat*) malloc(max*sizeof(reg_cat));
    if(categorias==NULL){
        printf("\nErro na alocação das categorias.\n");
        return 0;
    }


    do{
        opcao = menu();
        switch(opcao){
            case 1: /*Cadastra um novo aluno*/
                n=cadastrarproduto(produtos, max, n);
            break;


            case 2: /*Remover produtos*/
                n=removerprodutos(produtos, n);
            break;

            case 3: /*Atualizar produto*/
                atualizarprodutos(produtos, n);
            break;

            case 4: /*Listar por nome*/
                ordenaNome(produtos, n);
                printf("\nCodigo\t\tProduto \t\t\tCategoria \t\t\tQuantidade \tPreco\n");
                mostrarprodutos(produtos, n);
                pausa();
            break;

            case 5: /*Listar por quantidade*/
                ordenaqtd(produtos, n);
                printf("\nCodigo\t\tProduto \t\t\tCategoria \t\t\tQuantidade \tPreco\n");
                mostrarprodutos(produtos, n);
                pausa();
            break;
            case 6: /*Listar por categoria*/
                printf("\nCategoria \t\t\tQuantidade\n");
                ncat=ordenacat(produtos, n, categorias);
                mostrarcat(categorias, ncat);
                ncat=0; /*Zera o contador de categorias para não duplicar na próxima exibição*/
                pausa();
            break;
            case 7: /*Exibir todos os produtos cadastrados*/
                printf("\nCodigo\t\tProduto \t\t\tCategoria \t\t\tQuantidade \tPreco\n");
                mostrarprodutos(produtos, n);
                pausa();
            break;
        }
    }while(opcao != 0);
    
    free(produtos);
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
int menualtera() {
    int opcao;

    printf("\n\n\nO que voce deseja alterar no produto ?\n\n");
    printf("1. Alterar quantidade.\n");
    printf("2. Alterar preco\n\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}
void pausa(){
    printf("\nAperte qualquer tecla para continuar...\n");
    getch();
}

/*              FUNÇÃO BUSCA CODIGO                          */
int buscacod(reg_produto produtos[], int n, int cod){
    if(n==0)
        return -1;
    if(produtos[n-1].cod == cod)/*é possivel colocar dentro do if um OU n==0 para executar e devolver o -1 mas não compensa*/
        return n-1;             /*o codigo fica mais complicado de emtender*/
    return buscacod(produtos, n-1, cod);
}

/*              FUNÇÃO BUSCA CATEGORIA                       */
int buscacat(reg_cat categorias[], int ncat, reg_produto produtos[], int pos){
    if(ncat==0)
        return -1;
    if(strcmp(categorias[ncat-1].cat, produtos[pos].cat)==0)
        return ncat-1;
    return buscacat(categorias, ncat-1, produtos, pos);
}

/*              FUNÇÃO ORDENA NOME                           */
void ordenaNome(reg_produto produtos[], int n){
    int i, i2, mov;
    reg_produto aux;
    for(i=0;i<n;i++){
        for (i2=0;i2<n-1-i;i2++){
            mov=strcmp(produtos[i2].nome, produtos[i2+1].nome);
            if(mov<0){
                aux = produtos[i2];
                produtos[i2] = produtos[i2+1];
                produtos[i2+1] = aux;
            }
        }
    }
}

/*              FUNÇÃO ORDENA QUANTIDADE                     */
void ordenaqtd(reg_produto produtos[], int n){
    int i, i2;
    reg_produto aux;
    for(i=0;i<n;i++){
        for (i2=0;i2<n-1-i;i2++){
            if(produtos[i2].qtd < produtos[i2+1].qtd){
                aux = produtos[i2];
                produtos[i2] = produtos[i2+1];
                produtos[i2+1] = aux;
            }
        }
    }
}

/*              FUNÇÃO ORDENA CATEGORIA                     */
int ordenacat(reg_produto produtos[], int n, reg_cat categorias[]){
    int i, pos_cat, ncat=0;
    for(i=0;i<n;i++){
        pos_cat=buscacat(categorias, ncat, produtos, i);
        if(pos_cat == -1){ /*Se não encontrar a categoria no vetor de categorias, insere uma nova categoria*/
            strcpy(categorias[ncat].cat, produtos[i].cat);
            categorias[ncat].qtd = produtos[i].qtd;
            ncat++;
        }else{ /*Se encontrar a categoria no vetor de categorias, apenas atualiza a quantidade*/
            categorias[pos_cat].qtd = categorias[pos_cat].qtd + produtos[i].qtd;
        }
    }
    return ncat;
}

/***********************************************************************************
 *                          FUNÇÕES PRINCIPAIS DO CODIGO                           *
 ***********************************************************************************/

/*              FUNÇÃO CADASTRAR PRODUTO                     */
int cadastrarproduto(reg_produto produtos[], int max, int n){
    int cod, pos_busca;
    if(n == max){
        printf("\n\nMaximo de produtos cadastrados, exclua algum produto antes de tentar novamente.\n");
    }else{
        printf("\n\nBem vindo ao cadastro de produtos!\n");
        do{
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
            
        }
        }while(pos_busca != -1);
        printf("\nProduto cadastrado com sucesso!\n");
    }
    return n;
}

/*              FUNÇÃO REMOVE PRODUTO                        */
int removerprodutos(reg_produto produtos[], int n){
    int cod, pos_busca, i;
    
    printf("\nPor favor insira o codigo do produto que será removido:\n");
    scanf("%d", &cod);
    pos_busca=buscacod(produtos, n, cod);
    if(pos_busca == -1){
        printf("\nO codigo de produto inserido nao esta cadastrado!\nPor favor insira outro codigo.\n");
    }else{
        for(i=pos_busca; i<n-1; i++){
            produtos[i+1] = produtos[i+2]; /*Desloca os elementos para a esquerda*/
        }
        n--; /*Diminui o total de alunos cadastrados*/
        printf("\nProduto com codigo %d removido com sucesso!\n", cod);
        pausa();
        
    }
    return n;
}

/*              FUNÇÃO ATUALIZA PRODUTO                      */
void atualizarprodutos(reg_produto produtos[], int n){
    int pos_busca, cod, opcao;
    do{
        printf("\nPor favor insira o codigo do produto que sera atualizado:\n");
        scanf("%d", &cod);
        pos_busca=buscacod(produtos, n, cod);
        if(pos_busca == -1){
            printf("\nO codigo inserido nao pertence a um produto cadastrado!\nPor favor insira outro codigo de produto.\n");
        }else{
            opcao=menualtera();
            switch(opcao){
                case 1: /*Altera a quantidade*/
                    printf("Insira a nova quantidade do produto:");
                    scanf("%d", &produtos[pos_busca].qtd);
                    printf("\n\nQuantidade atualizada com sucesso!\n");
                    pausa();
                break;
                case 2: /*Altera o preco*/
                    printf("Insira o novo preco do produto:");
                    scanf("%f", &produtos[pos_busca].preco);
                    printf("\n\nPreco atualizado com sucesso!\n");
                    pausa();
                break;
            }
        }
    }while(pos_busca == -1);

}

/*              FUNÇÃO MOSTRAR PRODUTOS (RECURSIVA)          */
void mostrarprodutos(reg_produto produtos[], int n){
    if(n>0){
        /*printf("\nCodigo: %d\t\tNome:%s \t\t\tCategoria: %s\t\tQuantidade: %d\tPreco: %.2f", 
            produtos[n-1].cod,
            produtos[n-1].nome,
            produtos[n-1].cat,
            produtos[n-1].qtd,
            produtos[n-1].preco);*/
        printf("\n%d\t\t%s \t\t\t%s\t\t%d\t%.2f", 
            produtos[n-1].cod,
            produtos[n-1].nome,
            produtos[n-1].cat,
            produtos[n-1].qtd,
            produtos[n-1].preco);

        mostrarprodutos(produtos, n-1);
    }
}

/*              FUNÇÃO MOSTRAR CATEGORIAS (RECURSIVA)          */
void mostrarcat(reg_cat categorias[], int n){
    if(n>0){
        printf("\n%s\t\t%d", 
            categorias[n-1].cat,
            categorias[n-1].qtd);

        mostrarcat(categorias, n-1);
    }
}