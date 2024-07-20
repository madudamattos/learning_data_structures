#include <stdio.h>
#include "palavra.h"
#include "hash.h"

struct hash{
    Palavra** vet;
    int tamanho;
};

static int hash(char* s, int tamanho){
    int i;
    int total = 0;

    for(int i=0; s[i]!='\0'; i++){
        total += s[i];
    }

    return total%tamanho;
}


Hash* inicHash(int tamanho){
    Hash* h = (Hash*) malloc(sizeof(Hash));
    h->vet = (Palavra**) malloc(tamanho*sizeof(Palavra*));
    h->tamanho = tamanho;

    for(int i=0; i<tamanho; i++){
        h->vet[i] = NULL;
    }

    return h;
}

/*Faz acesso à hash em duas possíveis operações:
1)inserção, caso a palavra não esteja na hash
2)incremento de ocorrência, caso a palavra já esteja na hash*/
Palavra* acessa(Hash* h, char* string){
    int indice = hash(string, h->tamanho);

    Palavra* p = buscaPalavra(h->vet[indice], string);

    if(p){
        atualizaOcorrencias(p);
        return p;
    }

    // Caso nao esteja na tabela, insere a nova palavra

    p = inicPalavra(string);

    h->vet[indice] = inserePalavrasLista(h->vet[indice], p);

    return p;
}

void imprimeHash(Hash* h){
    for(int i=0; i< h->tamanho; i++){
        printf("\nPosicao vet[%d]: \n", i);
        imprimeLista(h->vet[i]);
    }
}

void liberaHash(Hash* h){
    for(int i=0; i< h->tamanho; i++){
        liberaListaPalavras(h->vet[i]);
    }

    free(h->vet);
    free(h);
}
