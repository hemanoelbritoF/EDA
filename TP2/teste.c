#include <stdlib.h>
#include <stdio.h>

void troca(int *a, int *b){
    int tem=0;

    tem = *a;
    *a = *b;
    *b = tem;
}

void aponta(int *a, int *t){
    printf("\nentrou\n");
    *a =12;
}

int  main(){
    int *ptr = NULL;
    int a=2;
    int b=3;
    ptr = &a;

    troca(&a,&b);
    printf("%d %d\n", a,b);

    printf("%p %p", &a, ptr);
    aponta(ptr, &a);
    printf("%p %p", &a, ptr);
    printf("\n%d\n",a);

    return 0;
}