#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int chave;
    struct cel *prox;
} cel;



void buscamin(int x, cel *lst){

    cel *p, *q;
    cel *min;/*Armazena no campo chave o dado contido, e no prox o endereço da cel menor*/
    p = lst;
    min = lst;
    while(p!=NULL){
        if(p->chave < min->chave)
            min=p;
        p = p->prox;
    }
}


  
cel *buscaminrec(cel *lst){
    cel *min;
    if(lst->prox==NULL)
        return lst;
    min=buscaminrec(lst->prox);
    if(lst->chave<min->chave){
        return lst;
    }else{
        return min;
    }
}


int main (){

    cel *celula;

    









    return 0;
}