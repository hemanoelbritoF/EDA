#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bib.h"

int main(){
    FILE *CSV=NULL;
    char nome[30];
    

    //----------- ler arquivo

    printf("Informe o nome do arquivo CSV: ");
    scanf("%s", nome);
    CSV = Arquivo_AbreLeitura(nome);
    if (CSV == NULL){
        printf("Erro ao abrir arquivo\n");
    } else {
        printf("Arquivo aberto: %s\n",nome);
    }
    int N=0;
    char Linha[100];
    while (!feof(CSV)){
        printf("%d\n",N);
        fgets(Linha,100,CSV);
        N++;
    }


    return 0;
}