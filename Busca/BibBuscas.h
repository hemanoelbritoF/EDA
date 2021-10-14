//
//  BibBuscas.h
//  EDABuscaSeqBin
//
//  Created by Nilton Correia da Silva on 22/03/21.
//

#ifndef BibBuscas_h
#define BibBuscas_h

#include <stdio.h>

//Geração de conjunto de dados
void GeraAleatorioInt(int *pvetor, int pTAM);
void GeraOrdenadoInt(int *pvetor, int pTAM);


//Buscas
int BuscaAleatoriaInt(int *pvetor, int pTAM, int pvalor);
int BuscaBinariaInt(int *pvetor, int pTAM, int pvalor);



#endif /* BibBuscas_h */