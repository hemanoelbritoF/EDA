#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *Arquivo_AbreLeitura(char *PNomeArquivo){
    return fopen(PNomeArquivo,"r");
}