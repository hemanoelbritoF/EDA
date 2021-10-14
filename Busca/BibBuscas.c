//
//  BibBuscas.c
//  EDABuscaSeqBin
//
//  Created by Nilton Correia da Silva on 22/03/21.
//

#include "BibBuscas.h"
#include <stdlib.h>


void GeraAleatorioInt(int *pvetor, int pTAM){
    int pind, ppos, paux;
    for(pind=0;pind<pTAM;pind++){
        pvetor[pind] = pind+1;
    }
//Randomizando (Algoritmo de Fischer-Yates)
    for(pind=(pTAM-1);pind>0;pind--){
        ppos = rand() % pind;
        if(ppos != pind){
            paux = pvetor[pind];
            pvetor[pind] = pvetor[ppos];
            pvetor[ppos] = paux;
        }
    }
}

void GeraOrdenadoInt(int *pvetor, int pTAM){
    int pind;
    for(pind=0;pind<pTAM;pind++){
        pvetor[pind] = pind+1;
    }
}

//Buscas:

int BuscaAleatoriaInt(int *pvetor, int pTAM, int pvalor){
    int aux=0;
    for(int i=0; i<pTAM; i++){
        if(pvetor[i] == pvalor){
            aux++;
            return i;
        }
    }
    if(aux == 0){
        return -1;
    }
}


int BuscaBinariaInt(int *pvetor, int pTAM, int pvalor){
    int esquerda = -1;
    int direita = pTAM-1;
    int Encontrado = -1;
    int interacao =0;
    while (esquerda<=direita && Encontrado==-1){
        int meio = (esquerda+direita)/2;
        printf("meio %d\n",meio);
        if(pvetor[meio]==pvalor){
            Encontrado = 0;
            return meio;
        } else if(pvalor<pvetor[meio]){
            direita=meio+1;
        } else{
            esquerda=meio+1;
        }
        interacao++;
    }
    printf("---------%d \n",interacao);

}
