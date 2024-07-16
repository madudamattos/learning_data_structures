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
    int matricula;
};

Aluno* retornaAlunoNo(Abb* a){
    return a->aluno;
}

Aluno* criaAluno(char* nome, int matricula){
    Aluno* aluno = calloc(1, sizeof(Aluno));
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;

    return aluno;
}

void imprimeAluno(Aluno* aluno){
    printf("%s\n", aluno->nome);
}

void liberaAluno(Aluno* aluno){
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
    if(!a){
        a = calloc(1, sizeof(Abb));
        a->aluno = s;
        a->dir = a->esq = NULL;
    }

    if(s->matricula > a->aluno->matricula){
        a->dir = insere_arv(a->dir, s);
    } else if (s->matricula < a->aluno->matricula){
        a->esq = insere_arv(a->esq, s);
    }

    return a;
}

Abb* busca_arv(Abb* a, int chave){
    if(!a) return NULL;
    else if(a->aluno->matricula > chave)
        return busca_arv(a->esq, chave);
    else if(a->aluno->matricula < chave)
        return busca_arv(a->dir, chave);
    else
        return a;
}

Abb* retira_arv(Abb* a, int chave){
    if(!a) return NULL;
    else if(a->aluno->matricula > chave)
        a->esq = retira_arv(a->esq, chave);
    else if(a->aluno->matricula < chave)
        a->dir = retira_arv(a->dir, chave);
    else{
        //se for no folha
        if(!a->esq && !a->dir){
            free(a);
            a = NULL;
        }
        
        //no so tem filho a direita
        else if(!a->esq && a->dir){
            Abb* aux = a;
            a = a->dir;
            free(aux);
        }

        //no so tem filho a esquerda
        else if(a->esq && !a->dir){
            Abb* aux = a;
            a = a->esq;
            free(aux);
        }

        //no tem os dois filhos 
        else {
            //acha o antecessor do no
            Abb* ant = a->esq;
            while(ant->dir)
                ant = ant->dir;
            //faz as trocas das informações
            Aluno* aux = a->aluno;
            a->aluno = ant->aluno;
            ant->aluno = aux;
            //chama recursivamente para o nó agora em alguma das situações anteriores
            a->esq = retira_arv(a->esq, chave);
        }
    }

    return a;
}

void libera_arv(Abb* a){
    if(!a) return;

    libera_arv(a->esq);
    libera_arv(a->dir);
    free(a);
}
