#include <stdlib.h>
#include <stdio.h>

struct NO{
    int Chave;
    struct NO *pDir, *pEsq;
    int FatBal;
};
typedef struct NO Arv;

int altura(Arv *r){
    if(r==NULL){
        return 0;
    }else{
        int ramoEsquerda = altura(r->pEsq);
        int ramoDireita = altura(r->pDir);
        
        if(ramoEsquerda < ramoDireita){
            return ramoDireita +1;
        }else{
            return ramoEsquerda +1;
        }
    }
}

Arv *gerar(Arv *raiz, int valor){

    if(raiz == NULL){
        Arv *novo;
        novo = (Arv *)malloc(sizeof(Arv));
        novo->Chave = valor;
        //novo->FatBal = 0;
        novo->pDir=NULL;
        novo->pEsq=NULL;

        raiz = novo;    
        printf("recebeu\n");
        return raiz;
    }else{
        //esquerda
        if(valor < raiz->Chave){
            printf("Esquerda\n");
            raiz->pEsq = gerar(raiz->pEsq, valor);
            raiz->FatBal = altura(raiz);
            return raiz;
        }else{
            printf("Direita\n");
            raiz->pDir = gerar(raiz->pDir, valor);
            raiz->FatBal = altura(raiz);
            return raiz;
        }
    }
}
/*
void rot_esq(Arv *r){
    Arv *a=*r;
    NO *b=a->pDir;
    a->pDir=b->pEsq;
    b->pEsq=a;
    a->FatBal=0;
    b->FatBal=0;
    *r=b;
}
*/

int  main(){

    Arv *raiz=NULL;
    raiz = gerar(raiz,40);
    raiz = gerar(raiz,45);
    raiz = gerar(raiz,44);
    raiz = gerar(raiz,50);
    raiz = gerar(raiz,55);

    printf("%d\n", raiz->FatBal);//40
    printf("%d\n", raiz->pDir->FatBal);//45
    printf("%d\n", raiz->pDir->pDir->FatBal);//50
    printf("%d\n", raiz->pDir->pDir->pDir->FatBal);//55
    printf("%d\n", raiz->pDir->pEsq->FatBal);//44
    //printf("%d\n", raiz->pEsq->Chave);

    return 0;
}