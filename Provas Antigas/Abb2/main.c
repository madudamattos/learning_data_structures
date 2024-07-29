/*
•Contabilizar número de palavras distintas e o número total de palavras;
•Descobrir a palavra com maior frequência.
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define TAM_NOME_CAMINHO 100

int main(int argv, char* argc[]){
    if(argv <2){
        printf("Não foi possivel localizar o arquivo de leitura\n");
        return 0;
    }

    char* caminhoArquivo = strdup(argc[1]);

    FILE* arquivo = fopen(caminhoArquivo, "r");
    
    if(!arquivo){
        printf("falha ao abrir arquivo!\n");
        return 0;
    }


    Arv* a = criaArvore();

    char palavra[TAM_NOME_CAMINHO];

    while(fscanf(arquivo, "%s", palavra) == 1){
        // ve se a palavra ja existe na arvore, se nao estiver monta 
        Arv* no = buscaArv(a, palavra);
        
        if(!no){
            insereArv(a, palavra);
        } else {
            incrementaArv(a);
        }
    }

    int distintas = contaPalavrasDistintas(a); 
    
    int total = contaPalavrasTotal(a);

    Arv* freq =  maiorFrequenciaArv(a);

    printf("%d palavras distintas encontradas\n%d palavras no total\n%s é a palavra de maior frequência (%d)\n", distintas, total, retornaPalavra(freq), retornaFreq(freq));

    fclose(arquivo);

    return 0;
}