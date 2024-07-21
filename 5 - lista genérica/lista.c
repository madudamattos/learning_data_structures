#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct listagen{
    void* conteudo;
    ListaGen* prox;
};

// cria lista vazia
ListaGen* criaLista(){
    return NULL;
}

// insere no inicio
ListaGen* insereLista(ListaGen* lista, void* item){
    ListaGen* novo = malloc(sizeof(ListaGen));

    novo->conteudo = item;
    novo->prox = lista;

    return novo;
}

// a funcao de callback tem que retornar 0 quanto forem iguais
ListaGen* retiraLista(ListaGen* lista, int (*cb)(void *, void *), void* chave){
    ListaGen* p = lista;
    ListaGen* ant = NULL;

    while(p && cb(p->conteudo, chave)){
        ant = p;
        p = p->prox;
    }

    // lista vazia ou nao encontrou o aluno
    if(!p){
        return lista;
    }

    // se for a primeira celula
    if(!ant){
        lista = lista->prox;
    } else {
        ant->prox = p->prox;
    }

    // libera a celula
    free(p);

    return lista;
}

// funcao percorre que vai servir para fazer varias coisas na lista (quem define é a funcao de callback)
int percorreLista(ListaGen* lista, int (*cb)(void *, void *), void* dado){
    ListaGen* p;

    for(p=lista; p!=NULL; p=p->prox){
        int r = cb(p->conteudo, dado);
        if(r == 0) return r;
    }

    return 1;
}

void liberaLista(ListaGen* lista){
    ListaGen* p = lista;
    ListaGen* aux;

    while(p){
        aux = p->prox;
        free(p);
        p = aux;
    }
}