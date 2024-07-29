#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define TAM_NOME 100

int tamanhoPalavra(char* p);

int main(){
    
    FILE* arquivo = fopen("arquivos_texto/entrada.txt", "r");

    int qtdAulas;

    fscanf(arquivo, "N %d%*c", &qtdAulas);

    Arv* a = cria_arv();

    char aluno[TAM_NOME];


    while(fscanf(arquivo, "%s", aluno) == 1){
        int tam = tamanhoPalavra(aluno);
        a = insere_arv(a, aluno);
    }

    fclose(arquivo);

    for(int i=1; i<=qtdAulas; i++){

        char* caminhoArquivo = calloc(100, sizeof(char));

        sprintf(caminhoArquivo, "arquivos_texto/entrada%d.txt", i);

        FILE* arquivo = fopen(caminhoArquivo, "r");
        char presenca = '\0';

        if(!arquivo) printf("nao foi possivel abrir o arquivo %s\n", caminhoArquivo);
        
        while(fscanf(arquivo, "%s %c%*c", aluno, &presenca) == 2){
            
            if(presenca == 'P'){
                Arv* arvAluno = busca_arv(a, aluno);
                incrementaPresenca(arvAluno);
            }
        }

        free(caminhoArquivo);

        fclose(arquivo);
    }

    arquivo = fopen("arquivos_texto/saida.txt", "w");
    
    imprime_arv(a, qtdAulas);
    imprime_arv_arquivo(a, qtdAulas, arquivo);

    fclose(arquivo);

    return 0;
}

