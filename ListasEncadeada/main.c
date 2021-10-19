#include <stdio.h>
#include <stdlib.h>

struct Tno{
    int numero;
    struct Tno *Prox;
};

typedef struct Tno celula;
typedef enum {true, false} bool;

bool Vazia(celula *plista){
    if(plista==NULL){
        return true;
    }else{
        return false;
    }
}
celula *inclueCabeca(celula *pLista, int pValor){
    celula *novaCelula;
    novaCelula = (celula *)malloc(sizeof(celula));
    novaCelula->numero = pValor;
    novaCelula->Prox = pLista;
    pLista = novaCelula;
    return pLista;
}

celula *inclueCalda(celula *pLista, int pValor){
    celula *novaCelula;
    celula *aux;
    aux = pLista;
    novaCelula = (celula *)malloc(sizeof(celula));
    novaCelula->numero = pValor;
    novaCelula->Prox=NULL;
    while(aux->Prox != NULL){
        aux = aux->Prox;
    }
    aux->Prox = novaCelula;
    return pLista;
}

celula *inclueAntes(celula *pLista,int chave,int pValor){
    celula *novaCelula, *aux;
    novaCelula = (celula *)malloc(sizeof(celula));
    novaCelula->numero = pValor;
    aux = pLista;
    while(aux->Prox->pValor != chave){
        aux = aux->Prox;
    }
    novaCelula->Prox = aux->Prox;
    aux->Prox=novaCelula;
    return pLista;
}

void imprime(celula *pLista){
    if(pLista!=NULL){
        printf("%d\n", pLista->numero);
        imprime(pLista->Prox);
    }
}


int main(){

    celula *node1;
    node1 = (celula *)malloc(sizeof(celula));
    celula *node2;
    
    node1->Prox = NULL;
    node1->numero = 1;

    

    node1 = inclueCabeca(node1, 2);
    node1 = inclueCabeca(node1, 3);
    node1 = inclueCalda(node1, 4);
    node1 = inclueCalda(node1, 5);
    imprime(node1)node1 = inclueCalda(node1, 4);;
    
    return 0;
}