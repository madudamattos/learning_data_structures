/*

PROVA 2 DA DISCIPLINA DE ESTRUTURA DE DADOS I
ALUNA: MARIA EDUARDA NOIA MATTOS DE AZEVEDO
DATA: 29/07/2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadpais.h"
#include "tadlista.h"

struct lista{
    Pais* pais;
    Lista* prox; 
};

Pais* retornaPais(Lista* l){
    return l->pais;
}

Lista* retornaProx(Lista* l){
    return l->prox;
}

Lista* criaLista(){
    return NULL;
}

// insere no inicio da lista
Lista* insereLista(Lista* l, Pais* p){
    Lista* nova = malloc(sizeof(Lista));

    nova->pais = p;
    nova->prox = l;

    return nova;
}


Lista* buscaLista(Lista* l, char* nomePais){
    Lista* p = l;

    while(p!= NULL){
        if(strcmp(retornaNome(p->pais), nomePais) == 0) return p;
        p = p->prox;
    }

    return NULL; 
}

void imprimeLista(Lista* l){
    Lista* p = l;

    while(p!= NULL){
        imprimePais(p->pais);    
        p = p->prox; 
    }
}

void liberaLista(Lista* l){
    Lista* p = l;
    Lista* temp = NULL;

    while(p!= NULL){
        temp = p->prox;
        liberaPais(p->pais);
        free(p);
        p = temp;
    }
}