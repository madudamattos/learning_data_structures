#include <stdio.h>
#include <stdlib.h>
#include "hashGen.h"
#include "aluno.h"

#define TAM 100

int main(){
    FILE* arquivo = fopen("arquivos_texto/entrada.txt", "r");

    if(!arquivo){
        printf("falha ao abrir arquivo entrada\n");
        return 0;
    }

    int qtdAulas;

    fscanf(arquivo, "N %d%*c", &qtdAulas);

    Hash* h = cria_hash(TAM);

    char alunoNome[TAM];

    while(fscanf(arquivo, "%s%*c", alunoNome) == 1){
        Aluno* a = criaAluno(alunoNome);
        insere_hash(h, retornaNomeAluno(a), (void*)a, hashAluno, ehIgualAluno);
    }

    fclose(arquivo);

    for(int i=1; i<=qtdAulas; i++){

        char* caminhoArquivo = calloc(100, sizeof(char));

        sprintf(caminhoArquivo, "arquivos_texto/entrada%d.txt", i);

        FILE* arquivo = fopen(caminhoArquivo, "r");
        char presenca = '\0';

        if(!arquivo) printf("nao foi possivel abrir o arquivo %s\n", caminhoArquivo);
        
        while(fscanf(arquivo, "%s %c%*c", alunoNome, &presenca) == 2){
            void * chamada = busca_hash(h, (void*)alunoNome, hashAluno, ehIgualAluno);

            if(presenca == 'P'){
                incrementaPresenca(chamada);
            } else if(presenca == 'F'){
                incrementaFalta(chamada);
            }
        }

        free(caminhoArquivo);

        fclose(arquivo);
    }

    arquivo = fopen("arquivos_texto/saida.txt", "w");
    
    imprime_hash(h, imprimeAluno);
    imprime_hash_arquivo(h, imprimeAlunoArquivo, arquivo);

    fclose(arquivo);

    libera_hash(h, liberaAluno);

    return 0;
}

