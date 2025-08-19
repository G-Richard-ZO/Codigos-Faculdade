/*
Nome: Gabriel Richard
RGA:  2025.0743.013-0
*/


/*
2)Escreva um programa que mantém um conjunto de alunos (no máximo 50) e forneça para o usuário as seguintes opções:
remover um aluno através do RGA
atualizar notas de um aluno através do RGA
exibir o nome, as três notas e a MA de todos os alunos aprovados na disciplina, ordenados por nome. 
exibir o nome, as três notas e a MA de todos os alunos reprovados na disciplina, ordenados decrescentemente pela MA obtida. Caso existam dois ou mais alunos com a mesma MA, esses alunos devem ser exibidos em ordem alfabética.

3)exibir as seguintes médias:
MA dos alunos aprovados
MA dos alunos reprovados
MA de todos os alunos

*/

#include <stdio.h>
#include <string.h>


typedef struct {
    int rga; /*RGA do aluno*/
    char nome[50];
    float notas[3]; /*N1, N2, N3*/
    float media; /*Media Aritmetica*/
    int aprovado; /*0 = reprovado, 1 = aprovado*/
} reg_aluno;

/*                    FUNÇÕES UTILIZADAS                         */
int menu();
int buscaRGA(reg_aluno alunos[], int n, int RGA);
void cadastraraluno(reg_aluno alunos[], int *n);
void atualizarnotas (reg_aluno alunos[], int n);
void mostrartodosalunos(reg_aluno alunos[], int n);


int buscaRGAr(reg_aluno alunos[], int n, int RGA);


/* *************************************************************************************************************
                                               MAIN DO CODIGO
************************************************************************************************************* */


int main(){
    reg_aluno alunos[50];
    int n=0; /*Qntd de alunos*/
    int opcao;

    do{
        opcao = menu();
        switch(opcao){
            case 1: /*Cadastra um novo aluno*/
                cadastraraluno(alunos, &n);
            break;

            case 2: /*mostra os alunos*/
                mostrartodosalunos(alunos, n);
            break;
        }
    }while(opcao != 0);
    

    return 0;

}


/* *************************************************************************************************************
                                            FUNÇÕES DO CODIGO
************************************************************************************************************* */




/*
                            FUNÇÃO MENU

    -Exibe o menu de opções para o usuario.
    -le a opção escolhida, valida ela e a retorna;
    -caso contrario exibe opção inválida e chama a função novamente.
*/
int menu() {
    int opcao;

    printf("Menu de Opcoes:\n");
    printf("1. Cadastrar um novo aluno\n");
    printf("2. Mostrar alunos cadastrados\n");
    printf("3. Remover um aluno. (Nao funcional)\n");
    printf("4. Atualizar notas de um aluno.\n");
    printf("5. Exibir alunos aprovados. (Nao funcional)\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

/*
                        FUNÇÃO DE BUSCA DE RGA

    -Recebe a lista de alunos cadastrados, a quantidade total de alunos
    e o RGA que será buscado.
    -Retorna a posição do aluno na lista caso o encontre,
    ou -1 se não encontrar.
*/

int buscaRGA(reg_aluno alunos[], int n, int RGA){
    int i;
    for(i=0; i<n; i++){
        if(alunos[i].rga == RGA){
            return i;
        }
    }
    return -1; /*Retorna i (posição) se encontrar, senão -1*/
}

/*              
                    FUNÇÃO BUSCA RGA RECURSIVA
    -Recebe a lista de alunos cadastrados, a quantidade total de alunos
    e o RGA que será buscado.
    -Retorna a posição do aluno na lista caso o encontre,
    ou -1 se não encontrar.
*/

int buscaRGAr(reg_aluno alunos[], int n, int RGA){
    /*if(n==0)
        return -1;*/
    if(alunos[n-1].rga == RGA || n==0)/*é possivel colocar dentro do if um OU n==0 para executar e devolver o -1*/
        return n-1;
    buscaRGAr(alunos, n-1, RGA);
}



/*
                        FUNÇÃO CADASTRAR ALUNO

    -Recebe a lista de alunos e o total de alunos cadastrados.
    -le primeiro o RGA, e verifica se já existe um cadastro com esse RGA;
        -se já existir um cadastro, notifica o usuário e pede outro RGA;
        -se não, inclui o RGA no vetor de alunos e continua o cadastro.
    -Lê o nome do aluno;
    -Lê as 3 notas do aluno e já calcula a média;
    -Por último define pela media se o aluno está aprovado ou reprovado.
    -Adiciona +1 ao total de alunos cadastrados.
*/

void cadastraraluno(reg_aluno alunos[], int *n){
    int i,RGA, pos_busca;
    if(*n == 50){
        printf("\n\nMaximo de alunos cadastrados, exclua algum aluno antes de tentar novamente.\n");
    }else{
        printf("\n\nBem vindo ao cadastro de alunos!\n");
        do{
            printf("\nPor favor insira o RGA do aluno a ser cadastrado:\n");
            scanf("%d", &RGA);/*guarda temporariamente para verificar se existe ou não o cadastro*/
            pos_busca=buscaRGAr(alunos, *n, RGA);
            if(pos_busca != -1){
                printf("\nO RGA inserido ja esta cadastrado!\nPor favor insira outro RGA.\n");
            }else{
                alunos[*n].rga = RGA;
            }
        }while(pos_busca != -1);

        printf("Insira o nome do aluno:\n");
        scanf(" %[^\n]", alunos[*n].nome);
        /*Calculo da média*/
        alunos[*n].media = 0.0;/*Inicializa para contagem*/
        for(i=0; i<3; i++){
            scanf("%f", &alunos[*n].notas[i]);
            alunos[*n].media = alunos[*n].media + alunos[*n].notas[i];
        }
        alunos[*n].media = alunos[*n].media / 3;
        if(alunos[*n].media >= 6.0){
            alunos[*n].aprovado = 1;
        }else{
            alunos[*n].aprovado = 0;
        }

        (*n)++;
    }
}

/*
                    FUNÇÃO ATUALIZAR NOTAS PELO RGA   

    -Recebe a lista de alunos e o total de alunos cadastrados.
    -Deve ser inserido o rga a ser atualizado as notas.
    -É buscado o rga pela funçao busca rga e é devolvido a posição no vetor, caso não encontre é devolvido o valor -1 e é exibido
    uma mensagem ao usuario e pede um novo rga.
*/

void atualizarnotas (reg_aluno alunos[], int n){
    int RGA, pos_busca;

    do{
        printf("\nPor favor insira o RGA do aluno que será atualizado as notas:\n");
        scanf("%d", &RGA);/*guarda temporariamente para verificar se existe ou não o cadastro*/
        pos_busca=buscaRGA(alunos, n, RGA);
        if(pos_busca != -1){
            printf("\nO RGA inserido ja esta cadastrado!\nPor favor insira outro RGA.\n");
        }else{
            alunos[n].rga = RGA;
        }
    }while(pos_busca != -1);

    /*buscaRGA*/
}


/*
                    FUNÇÃO MOSTRAR ALUNOS CADASTRADOS   

    -Recebe a lista de alunos e o total de alunos cadastrados.
    -Exibe uma tabela com os dados de todos os alunos cadastrados.
*/

void mostrartodosalunos(reg_aluno alunos[], int n){
    int i;
    char tmp;
    printf("\nRGA\t\tNome \t\t\tN1\tN2\tN3 \tMedia \tSituacao\n");
    for(i=0;i<n; i++){
        printf("\n%d\t\t%s \t\t\t%.1f\t%.1f\t%.1f \t%.1f ", 
            alunos[i].rga,
            alunos[i].nome,
            alunos[i].notas[0], 
            alunos[i].notas[1], 
            alunos[i].notas[2], 
            alunos[i].media);
        if(alunos[i].aprovado==1){
            printf("\tAprovado !\n");
        }else{
            printf("\tReprovado !\n");
        }
    }
    printf("Aperte qualquer tecla e entao ENTER para continuar...\n");
    scanf(" %[ \n]", &tmp);
}
