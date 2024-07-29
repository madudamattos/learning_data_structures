#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore{
    char* nome;
    int peso;
    int presenca;
    Arv* esq;
    Arv* dir;
};

char* retornaNome(Arv* a){
    return a->nome;
}

int retornaPeso(Arv* a){
    return a->peso;
}

int retornaPresenca(Arv* a){
    return a->presenca;
}

void incrementaPresenca(Arv* a){
    a->presenca++;
}

Arv* cria_arv(){
    return NULL;
}

Arv* insere_arv(Arv* a, char* nome) {
    if (!a) {
        a = calloc(1, sizeof(Arv));
        a->nome = strdup(nome);
        a->presenca = 0;
        a->esq = a->dir = NULL;
    } else if (comparaNomes(nome, a->nome) < 0) {
        a->esq = insere_arv(a->esq, nome);
    } else if (comparaNomes(nome, a->nome) > 0) {
        a->dir = insere_arv(a->dir, nome);
    }
    return a;
}

Arv* busca_arv(Arv* a, char* nome) {
    if (!a) {
        return NULL;
    } else if (comparaNomes(nome, a->nome) < 0) {
        return busca_arv(a->esq, nome);
    } else if (comparaNomes(nome, a->nome) > 0) {
        return busca_arv(a->dir, nome);
    } else {
        return a;
    }
}

void imprime_arv(Arv* a, int nAula){
    if(!a) return;

    imprime_arv(a->esq, nAula);
    printf("%s %dP %dF\n", a->nome, a->presenca, nAula - a->presenca);
    imprime_arv(a->dir, nAula);
}

void imprime_arv_arquivo(Arv* a, int nAula, FILE* arquivo){
    if(!a) return;

    imprime_arv_arquivo(a->esq, nAula, arquivo);
    fprintf(arquivo,"%s %dP %dF\n", a->nome, a->presenca, nAula - a->presenca);
    imprime_arv_arquivo(a->dir, nAula, arquivo);
}

int tamanhoPalavra(char* p){
    int tam = 0;
    int i = 0;
    
    while(p[i] != '\0'){
        tam += (int)p[i];
        i++;
    }

    return tam;
}

int comparaNomes(char* nome1, char* nome2) {
    return strcmp(nome1, nome2);
}