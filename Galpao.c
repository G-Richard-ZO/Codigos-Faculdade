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

int listaproduto (int taml, int lin, int col, tproduto mat[][3], tproduto lista[]){
    int i, i2, list, produtodiferente;
    produtodiferente = 0;

    for(i=0; i<lin;i++){
        for(i2=0; i2<col;i2++){
            for(list=0; list<taml; list++){
                if(mat[i][i2].cod==lista[list].cod){
                    lista[list].qtd = lista[list].qtd + mat[i][i2].qtd;
                }else{
                    lista[list].cod = mat[i][i2].cod;
                    lista[list].preco = mat[i][i2].preco;
                    lista[list].qtd = mat[i][i2].qtd;
                    produtodiferente++;
                }
            }
        }
    }
    return produtodiferente;
}

void mostralista(int produtodiferente, tproduto lista[]){
    int i;
    printf("Lista de produtos:\n");
    for(i=0; i<produtodiferente; i++){
            printf("Produto")
    }
}

int main(){
    tproduto galpao[3][3], lista[9];
    int pdif;


    lergalpao(3, 3, galpao);
    pdif=listaproduto(9, 3, 3, galpao, lista);

}
