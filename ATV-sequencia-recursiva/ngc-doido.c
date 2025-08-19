#include <stdio.h>


int sequencia (int n){
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    if(n==2)
        return 3;

    return sequencia(n-1)+sequencia(n-2)+sequencia(n-3);
}

int main (){
    int a;

    a=sequencia(6);

    printf("\n%d", a);

    return 0;
}