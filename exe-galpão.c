#include <stdio.h>
#include <string.h>

typedef struct {
    int cod;
    float preco;
    int qtd;
} tproduto;


/*Função para ler a matriz/galpão */
void lergalpao(int lin, int col, tproduto mat[][3]) {
    int i, i2;
    for (i = 0; i < lin; i++) {
        for (i2 = 0; i2 < col; i2++) {
            printf("Digite os dados no quadrante %d,%d: ", i, i2);
            scanf("%d %f %d", &mat[i][i2].cod, &mat[i][i2].preco, &mat[i][i2].qtd);
        }
    }
}

/*
recebe por parametro o vetor da lista de produtos, com n produtos e busca por um codigo especifico
devolve a posicao do produto na lista, caso nao encontre devolve -1
*/
int buscaproduto(int codigo, int taml, tproduto lista[taml]){
    int posx=-1;
    int i;

    for(i=0; i<taml; i++){
        if(lista[i].cod == codigo){
            posx = i;
            i=taml;
        }
    }
    return posx;
}


int listaproduto (int taml, int lin, int col, tproduto mat[lin][col], tproduto lista[taml]){
    int i, i2, qtddif, posi;
    qtddif = 0;

    for(i=0; i<lin;i++){
        for(i2=0; i2<col;i2++){

            posi= buscaproduto(mat[i][i2].cod, taml, lista);
        
            if(posi>=0){
                lista[posi].qtd = lista[posi].qtd + mat[i][i2].qtd;
            }else{
                lista[qtddif].cod = mat[i][i2].cod;
                lista[qtddif].preco = mat[i][i2].preco;
                lista[qtddif].qtd = mat[i][i2].qtd;
                qtddif++;
            }
            
        }
    }
    return qtddif;
}


/*
void mostralista(int produtodiferente, tproduto lista[]){
    int i;
    printf("Lista de produtos:\n");
    for(i=0; i<produtodiferente; i++){
            printf("Produto")
    }
}*/


/* *************************************************************************************************************
                                               MAIN DO CODIGO
************************************************************************************************************* */
int main(){
    tproduto galpao[3][3]= {
        {{10,10.0,5}, {20,20.0,3}, {30,30.0,2}},
        {{40,40.0,1}, {10,10.0,6}, {20,20.0,2}},
        {{20,20.0,1}, {10,10.0,2}, {30,30.0,2}}
    };

    tproduto lista[9];
    int pdif;


    /*lergalpao(3, 3, galpao);*/
    pdif = listaproduto(9, 3, 3, galpao, lista);


    return 0;

}