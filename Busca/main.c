//
//  main.c
//  EDABuscaSeqBin
//
//  Created by Nilton Correia da Silva on 22/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "BibBuscas.h"

int main(int argc, const char * argv[]) {
    int pind, Valor;
    int *Aleatorio = NULL, pTamAleatorio=0;
    int *Ordenado = NULL, pTamOrdenado=0;

    char popc = '0';

    while(popc != 'S'){
        printf("\n################## BUSCA SEQUENCIAL E BINÁRIA ##################");
        printf("\n");
        printf("\nA - Gerar Valores Aleatórios");
        printf("\nB - Busca Sequencial");
        printf("\nC - Gerar Valores Ordenados");
        printf("\nD - Busca Binária");

        printf("\nS - Sair");
        printf("\nOpção: ");
        scanf("\n%c", &popc);
        switch (popc) {
            case 'A':
                if(pTamAleatorio > 0)
                    free(Aleatorio);
                printf("Tamanho do Vetor: ");
                scanf("%d", &pTamAleatorio);
                Aleatorio = (int *)malloc(pTamAleatorio*sizeof(int));
                if(Aleatorio != NULL){
                    GeraAleatorioInt(Aleatorio, pTamAleatorio);
                    for(pind = 0;pind<pTamAleatorio;pind++)
                        printf("\nValor %d: %d", pind, Aleatorio[pind]);
                }
                else
                    printf("\nErro 1: Não foi possível alocar o vetor!!!\n");
                break;

            case 'B':
                if(pTamAleatorio > 0){
                    printf("Valor a Ser Encontrado: ");
                    scanf("%d", &Valor);
                    pind = BuscaAleatoriaInt(Aleatorio, pTamAleatorio, Valor);
                    if(pind > -1){
                        printf("\nValor %d encontrado na posição %d.\n", Valor, pind);
                    }
                    else{
                        printf("\nValor %d não encontrado!!!\n", Valor);
                    }
                }
                else
                    printf("\nValores aleatórios não foram gerados!!!\n");
                break;
                
            case 'C':
                if(pTamOrdenado > 0)
                    free(Ordenado);
                printf("Tamanho do Vetor: ");
                scanf("%d", &pTamOrdenado);
                Ordenado = (int *)malloc(pTamOrdenado*sizeof(int));
                if(Ordenado != NULL){
                    GeraOrdenadoInt(Ordenado, pTamOrdenado);
                    for(pind = 0;pind<pTamOrdenado;pind++)
                        printf("\nValor %d: %d", pind, Ordenado[pind]);
                }
                else
                    printf("\nErro 1: Não foi possível alocar o vetor!!!\n");
                break;
                
            case 'D':
                if(pTamOrdenado > 0){
                    printf("Valor a Ser Encontrado: ");
                    scanf("%d", &Valor);
                    pind = BuscaBinariaInt(Ordenado, pTamOrdenado, Valor);
                    if(pind > -1){
                        printf("\nValor %d encontrado na posição %d.\n", Valor, pind);
                    }
                    else{
                        printf("\nValor %d não encontrado!!!\n", Valor);
                    }
                }
                else
                    printf("\nValores ordenados não foram gerados!!!\n");
                break;

                
            case 'S':
                break;
        }
        if(popc == 'S')
            break;
    }

//Liberar memória
    if(pTamAleatorio > 0)
        free(Aleatorio);

    printf("\n\n ----- Sistema Encerrado ----- \n\n");

    return 0;
}