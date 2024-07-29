
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char* nome; 
    int p; 
    int f;
};

void* retornaNomeAluno(void* a){
    Aluno* aluno = (Aluno*) a;

    return (void*)aluno->nome;
}

Aluno* criaAluno(char* nome){
    Aluno* a = malloc(sizeof(Aluno));
    a->nome = strdup(nome);
    a->p = 0;
    a->f = 0;

    return a;
}

int ehIgualAluno(void* aluno1, void* nome) {
    Aluno* a1 = (Aluno*) aluno1;
    char* nome2 = (char*) nome;

    return strcmp(a1->nome, nome2) == 0;
}


void imprimeAluno(void* aluno){
    Aluno* a = (Aluno*) aluno;
    printf("%s %dP %dF\n", a->nome, a->p, a->f);
}

void imprimeAlunoArquivo(void* aluno, FILE* arquivo){
    Aluno* a = (Aluno*) aluno;
    fprintf(arquivo,"%s %dP %dF\n", a->nome, a->p, a->f);
}

int hashAluno(void* key, int tamanhoTabela) {
    char* nome = (void*) key;
    int soma = 0;
    int i = 0;

    while (nome[i] != '\0') {
        soma += (int) nome[i];
        i++;
    }
    
    return soma % tamanhoTabela;
}

void incrementaPresenca(void* aluno){
    if(!aluno) return;
    
    Aluno* a = (Aluno*) aluno;

    a->p++;
}

void incrementaFalta(void* aluno){
    if(!aluno) return;
    
    Aluno* a = (Aluno*) aluno;
    a->f++;
}

void liberaAluno(void* aluno){
    if(!aluno) return;

    Aluno* a = (void*) aluno;

    free(a->nome);
    free(a);
}