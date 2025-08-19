#include <stdio.h>


int ackermann (int m, int n, int tab){
    int i;
    printf("\n");
    for(i=0; i<tab; i++){
        printf("\t");
    }
    printf("A(%d, %d)", m,n);

    if(m==0)
        return n+1;

    if(m>0 && n==0)
        return ackermann(m-1, 1, tab+1);
    
    if(m>0 && n>0)
        return ackermann(m-1, ackermann(m, n-1, tab+1), tab+1);
    
}

int main (){
    int A;
    A=ackermann(3,2,0);

    printf("A=%d", A);
    return 0;
}