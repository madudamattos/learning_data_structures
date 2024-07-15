#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_busca.h"

struct arvore{
  Aluno* aluno;
  Abb* esq;
  Abb* dir;   
};

struct aluno{
    char* nome;
    
};

Aluno* criaAluno(char* nome){
    Aluno* aluno = calloc(1, sizeof(Aluno));
    aluno->nome = strdup(nome);

    return aluno;
}

void imprimeAluno(Aluno* aluno){
    printf("%s\n", aluno->nome);
}

void liberaALuno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}

Abb* cria_arv(){
    return NULL;
}

void imprime_arv(Abb* a){
    if(!a) return;

    imprime_arv(a->esq);
    imprimeAluno(a->aluno);
    imprime_arv(a->dir);
}

Abb* insere_arv(Abb* a, Aluno* s){

}

Abb* busca_arv(Abb* a, int chave){

}

Abb* retira_arv(Abb* a, int v);

Abb* libera_arv(Abb* a);
