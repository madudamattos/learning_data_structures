#ifndef HASH_H
#define HASH_H

#include "hashGen.h"
#include <stdio.h>
#include <stdlib.h>

struct hash{
    int tam;
    void** tabela; 
};

Hash* cria_hash(int tam){
    Hash* h = malloc(sizeof(Hash));
    h->tabela = malloc(tam * sizeof(void*));
    h->tam = tam;

    for(int i=0; i<tam; i++){
        h->tabela[i] = NULL;
    }

    return h;
}

void* insere_hash(Hash* h, void* key, void* objeto, int (*fhash)(void*, int htam), int (*cmp)(void*, void*)){
    int indice = fhash(key, h->tam);

    // verifica se tem alguem naquela posicao
    if(h->tabela[indice] == NULL){
        h->tabela[indice] = objeto;
        return objeto;
    } else{
        // se nao existir alguem, busca a proxima posicao livre
        int j;
        for(int i=0; i<h->tam; i++){
            
            // mudando indice para incremento circular
            j = (indice + i)% h->tam;
            
            if(h->tabela[j] == NULL){
                h->tabela[j] = objeto;
                return objeto;
            }
        }
    }

    return NULL;
}

void* busca_hash(Hash* h, void* key, int (*fhash)(void*, int htam), int (*cmp)(void*, void*)){
    int indice = fhash(key, h->tam);

    // verifica se tem alguem naquela posicao, se nao existir ja retorna null
    if(h->tabela[indice] == NULL){
        return NULL;
    } else{
        // existir alguem, compara ate achar um NULL
        int j;
        for(int i=0; i<h->tam; i++){
            // mudando indice para incremento circular
            j = (indice + i)% h->tam;
            
            if(h->tabela[j] == NULL){
                return NULL;
            } else{
                if(cmp(h->tabela[j], key)) return h->tabela[j];
            }
        }
    }


    return NULL;
}

void imprime_hash(Hash* h, void (*imprimeDado)(void*)){

    for(int i=0; i<h->tam; i++){
        if(h->tabela[i] != NULL){
            imprimeDado(h->tabela[i]);
        }
    }

}

void imprime_hash_arquivo(Hash* h, void (*imprimeDadoArquivo)(void*, FILE*), FILE* arquivo){

    for(int i=0; i<h->tam; i++){
        if(h->tabela[i] != NULL){
            imprimeDadoArquivo(h->tabela[i], arquivo);
        }
    }

}

void libera_hash(Hash* h, void (*liberaDado)(void*)){
    for(int i = 0; i < h->tam; i++){
        if(h->tabela[i] != NULL){
            liberaDado(h->tabela[i]);
        }
    }
    free(h->tabela);
    free(h);
}


#endif
