#include <stdio.h>

int main (){

    int h1, m1, h2, m2, h3, m3, h4, m4, chegada, ida;
    int t1, t2, t3, t4, vi, vv, duracao, fuso;


    scanf("%d:%d %d:%d %d:%d %d:%d", &h1, &m1, &h2, &m2, &h3, &m3, &h4, &m4);
    t1 = h1*60 + m1;
    t2 = h2*60 + m2;
    t3 = h3*60 + m3;
    t4 = h4*60 + m4;

    vi = (t2 - t1 + 1440)%1440;
    vv = (t4 - t3 + 1440)%1440;

    duracao = vi + vv;
    fuso = t3 - t1;

    printf("%d\n", duracao);
    printf("%d\n", fuso);

    return 0;


}

