#include <stdio.h>
#include <stdlib.h>

//struct No
struct No{
    int Chave;
    struct No *pEsq, *pDir;
    int FatBal;
};
//renomeando estrutura de dados
typedef struct No Arv;

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
            raiz->FatBal = altura(raiz)-1;
            return raiz;
        }else{
            printf("Direita\n");
            raiz->pDir = gerar(raiz->pDir, valor);
            raiz->FatBal = altura(raiz)-1;
            printf("%d\n",raiz->FatBal);
            return raiz;
        }
    }
}



int fatorBalanceamento(Arv *no){
    return labs(altura(no->pEsq) - altura(no->pDir));
}

int maior(int x, int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}

void RotacaoLL(Arv *raiz){
    struct No *no;
    no = raiz->pEsq;
    raiz->pEsq = no->pDir;
    raiz->FatBal = maior(altura(raiz->pEsq), altura(raiz->pDir))+1;
    no->FatBal = maior(altura(no->pEsq),raiz->FatBal)+1;
    raiz = no;
}

void RotacaoRR(Arv *raiz){
    struct No *no;
    no = raiz->pDir;
    raiz->pDir = no->pEsq;
    raiz->FatBal = maior(altura(raiz->pEsq), altura(raiz->pDir))+1;
    no->FatBal = maior(altura(no->pDir),raiz->FatBal)+1;
    raiz = no;
}
void RotacaoLR(Arv *raiz){
    RotacaoRR(raiz->pEsq);
    RotacaoLL(raiz);
}
void RotacaoRL(Arv *raiz){
    RotacaoLL(raiz->pDir);
    RotacaoLL(raiz);
}

int main(){
    
    char linha[10];
    FILE *AR =NULL;
    AR = fopen("testeA.txt", "rt");
    int num=0;
    Arv *raiz=NULL;

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