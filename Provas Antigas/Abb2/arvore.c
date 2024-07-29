#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore{
    char* palavra;
    int frequencia;
    Arv* dir;
    Arv* esq;
};

char* retornaPalavra(Arv* a){
    return a->palavra;
}

int retornaFrequencia(Arv* a){
    return a->frequencia;
}

Arv* criaArvore(){
    return NULL;
}

Arv* insereArv(Arv* a, char* palavra){
    
}

Arv* buscaArv(Arv* a, char* palavra){

}

void liberaArv(Arv* a){

}

int contaPalavrasDistintas(Arv* a){

}

int contaPalavrasTotal(Arv* a){

}

Arv* maiorFrequenciaArv(Arv* a){

}