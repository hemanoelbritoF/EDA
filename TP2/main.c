#include <stdio.h>
#include <stdlib.h>

//struct No
struct No{
    int Chave;
    struct No *pEsq, *pDir;
    int FatBal;
};
//renomeando estrutura de dados
typedef struct No celula;


celula *CriarRaiz(){
    celula *novo;
    novo = (celula *)malloc(sizeof(celula));

    if(novo != NULL){
        novo = NULL;
    }
    return novo;
}

celula *gerar(celula *raiz, int valor){
    celula *novo;
    novo = (celula *)malloc(sizeof(celula));
    novo->Chave = valor;
    novo->pDir=NULL;
    novo->pEsq=NULL;

    if(raiz == NULL){
        raiz = novo;    
        printf("recebeu\n");
        return raiz;
    }else{
        //esquerda
        if(valor < raiz->Chave){
            printf("Esquerda\n");
            raiz->pEsq = gerar(raiz->pEsq, valor);
            return raiz;
        }else{
            printf("Direita\n");
            raiz->pDir = gerar(raiz->pDir, valor);
            return raiz;
        }
    }

}

int main(){

    char linha[10];
    FILE *AR =NULL;
    AR = fopen("testeA.txt", "rt");
    int num=0;
    celula *raiz;
    
    
    fgets(linha, 10, AR);
    num = atoi(linha);
    raiz = gerar(raiz,num);
    
    fgets(linha, 10, AR);
    raiz = gerar(raiz,num);
    fgets(linha, 10, AR);
    raiz = gerar(raiz,num);
    int a =0 ;
    for (int i=0; i<=10; i++){
      a = i;
    }
    printf("%d",a);
    /*
    int i=0;
    while(i<5){
        fgets(linha, 10, AR);
        
        num = atoi(linha);
        //printf("%d",num);
        
        raiz = gerar(raiz,num);
        i++;
    }
    /*

    /*
    celula *raiz;
    raiz = gerar(raiz,40);
    raiz = gerar(raiz,54);
    raiz = gerar(raiz,34);
    raiz = gerar(raiz,41);
    
    printf("%d\n", raiz->Chave);
    
    printf("%p\n", *&raiz->pDir);
    printf("%p\n", *&raiz->pEsq);
    printf("%p\n", *&raiz);
    printf("%d\n", raiz->pDir->Chave);
    printf("%d\n", raiz->pEsq->Chave);

    */
    return 0;
}