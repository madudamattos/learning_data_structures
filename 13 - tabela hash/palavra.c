#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palavra.h"

// Define o tipo opaco palavra, que tambem é uma lista
struct palavra{
    char* string;
    int ocorrencias;
    Palavra* prox;
};

Palavra* inicPalavra(char* str){
    Palavra* pal = (Palavra*) calloc(1, sizeof(Palavra));
    pal->string = strdup(str);
    pal->ocorrencias = 1;
    pal->prox = NULL;

    return pal;
}

char* retornaString(Palavra* pal){
    return pal->string;
}

void atualizaOcorrencias(Palavra* pal){
    pal->ocorrencias++;
}

int retornaOcorrencias(Palavra* pal){
    return pal->ocorrencias;
}

// Busca palavra na lista de colisoes
Palavra* buscaPalavra(Palavra* pal, char* string){
    Palavra* p = pal;

    while(p){
        if(strcmp(p->string, string) == 0){
            return p;
        }
        p = p->prox;
    }

    return NULL;
}

// Insere palavra na lista de colisoes na primeira posicao
Palavra* inserePalavrasLista(Palavra* lista, Palavra* p){
    p->prox = lista;
    return p;
}

int contaPalavrasLista(Palavra* p){
    int total=0;

    Palavra* pal = p;
    while(pal){
        total++;
        pal = pal->prox;
    }

    return total;
}

void imprimeLista(Palavra* p){
    Palavra* pal = p;
    
    while(pal){
        printf("Palavra:%s  Ocorrencias:%d\n", pal->string, pal->ocorrencias);
        pal = pal->prox;
    }
}

void liberaListaPalavras(Palavra* p){
    Palavra* pal = p;
    Palavra* aux;

    while(pal){
        aux = pal;
        free(pal->string);
        free(pal);
        pal = aux->prox;
    }
}