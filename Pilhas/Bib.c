#include <stdio.h>
#include <stdlib.h>

struct Tno{
    int numero;
    struct Tno *Prox;
};

typedef struct Tno celula;


celula *Empilhar(celula *p, int num){
    celula *novo = (celula*)malloc(sizeof(celula));

    if(p==NULL){
        p = novo;
        p->numero = num;
        p->Prox = NULL;
        return p;
    } else{
        novo->numero = num;
        novo->Prox = p;
        return novo;
    }

}

celula *Desempilha(celula *p){
    if(p==NULL){
        printf("Pilha vazia!\n");
        return NULL;
    } else{
        celula *aux;
        aux = (celula*)malloc(sizeof(celula));
        aux = p;
        p = aux->Prox;

        free(aux);
        return p;
    }
    

}
void Esvaziar(celula *Pilha){
    celula *aux;
    aux = Pilha;

    while(aux !=0){
        Pilha = aux->Prox;
        free(aux);
        aux = Pilha;
    }
}

void imprimir(celula *Pilha){
    if(Pilha != NULL){
        printf("%d\n", Pilha->numero);
        imprimir(Pilha->Prox);
    }
}
int main(){

    celula *node0 = NULL;
    node0 = Empilhar(node0, 1);
    node0 = Empilhar(node0, 2);
    node0 = Empilhar(node0, 3);

    imprimir(node0);
    node0 = Desempilha(node0);
    imprimir(node0);
    node0 = Desempilha(node0);
    imprimir(node0);
    node0 = Desempilha(node0);
    //Esvaziar(node0);
    printf("\n");
    imprimir(node0);

    return 0;
}