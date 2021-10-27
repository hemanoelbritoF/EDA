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


int aux=0;
celula *gerar(celula *raiz, int valor){

    if(raiz == NULL){
        celula *novo;
        novo = (celula *)malloc(sizeof(celula));
        novo->Chave = valor;
        novo->FatBal = 0;
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
            return raiz;
        }else{
            printf("Direita\n");
            raiz->pDir = gerar(raiz->pDir, valor);
            return raiz;
        }
    }
}

int altura(celula *no){
    if(no==NULL){
        return -1;
    }else{
         return no->FatBal;
    }
}

int fatorBalanceamento(celula *no){
    return labs(altura(no->pEsq) - altura(no->pDir));
}

int maior(int x, int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}

void RotacaoLL(celula *raiz){
    struct No *no;
    no = raiz->pEsq;
    raiz->pEsq = no->pDir;
    raiz->FatBal = maior(altura(raiz->pEsq), altura(raiz->pDir))+1;
    no->FatBal = maior(altura(no->pEsq),raiz->FatBal)+1;
    raiz = no;
}

void RotacaoRR(celula *raiz){
    struct No *no;
    no = raiz->pDir;
    raiz->pDir = no->pEsq;
    raiz->FatBal = maior(altura(raiz->pEsq), altura(raiz->pDir))+1;
    no->FatBal = maior(altura(no->pDir),raiz->FatBal)+1;
    raiz = no;
}
void RotacaoLR(celula *raiz){
    RotacaoRR(raiz->pEsq);
    RotacaoLL(raiz);
}
void RotacaoRL(celula *raiz){
    RotacaoLL(raiz->pDir);
    RotacaoLL(raiz);
}

int main(){
    
    char linha[10];
    FILE *AR =NULL;
    AR = fopen("testeA.txt", "rt");
    int num=0;
    celula *raiz=NULL;

    while(!feof(AR)){
        
        fgets(linha, 10, AR);
        num = atoi(linha);
        printf("\n%d %s\n",num, linha);
        raiz = gerar(raiz,num);

    }

    printf("%d\n", raiz->Chave);
    
    printf("%d\n", raiz->pDir->Chave);
    printf("%d\n", raiz->pDir->pDir->Chave);
    printf("%d\n", raiz->pDir->pDir->pEsq->Chave);
    printf("%d\n", raiz->pEsq->Chave);
    //printf("%d\n", raiz->pEsq->pEsq->Chave);
    //printf("%p\n", *&raiz);
    //printf("%d\n", *&raiz->pDir->Chave);
    //printf("%d\n", *&raiz->pEsq->Chave);
    
    
    return 0;
}