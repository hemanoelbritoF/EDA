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
    int nLinhas=0;
    char Linha[100];
    while (!feof(CSV)){
        //printf("%d\n",nLinhas);
        fgets(Linha,100,CSV);
        nLinhas++;
    }

    char **Codg;
    char teste;
    fseek(CSV, 0, SEEK_SET);
    //char Linha
    Codg = malloc(nLinhas*sizeof(char*));
    fgets(Linha,100,CSV);
    for(int i=0; i<nLinhas; i++){
        Codg[i] = malloc(11*sizeof(char));
        fgets(Codg[i],11,CSV);
        fgets(Linha,100,CSV);
        //printf("%s\n",Codg[i]);
        
    }
    







    /*
    //teste matriz dinamica
    int **mat;
    int i,j;
    int a;
    //dizzendo tamanho da matriz quadrada
    scanf("%d", &a);

    //aloca um vetor de ponteiro para ponteiros(linhas)
    mat = malloc(a * sizeof(int*));

    //aloca as linhas 

    for (i=0; i<a; i++){
        mat[i] = malloc(a *sizeof(int));
    }
    
    for(i=0;i<a; i++){
        for(j=0;j<a;j++){
            mat[i][j]=i+j;
            printf("%d \n",mat[i][j]);
        }
    }
    
    for(i=0;i<3;i++){
        free(mat[i]);
    }
    */


    
    return 0;
}