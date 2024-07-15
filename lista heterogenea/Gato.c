#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"

struct gato{
    char* nomeGato;
    int agressividade;
};

Gato* inicGato(char* nome, int agressividade){
    Gato* cat = (Gato*)malloc(sizeof(Gato));
    cat->nomeGato = strdup(nome);
    cat->agressividade = agressividade;
    return cat;
}

void liberaGato(Gato* cat){
    free(cat->nomeGato);
    free(cat);
}

int retornaNivelAgressividadeGato(Gato* cat){
    return cat->agressividade;
}

char* retornaNomeGato(Gato* cat){
    return cat->nomeGato;
}

void imprimeGato(Gato* cat){
    if(cat == NULL){
        printf("GATO NULO\n");
        return;
    }
    printf("%s, ", cat->nomeGato);
    if(cat->agressividade == BRAVO) printf("BRAVO\n");
    else if(cat->agressividade == MANSO) printf("MANSO\n");
}

void atribuiNivelAgressividadeGato(Gato* cat, int agressividadeAtt){
    cat->agressividade = agressividadeAtt;
}