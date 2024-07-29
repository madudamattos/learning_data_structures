#include "hash.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash {
  int tam;
  Lista **vetor;
};

Hash *cria(int tam) {
  Hash *h = (Hash *) malloc(sizeof(Hash));

  h->tam = tam;
  h->vetor = (Lista **) malloc(sizeof(Lista*) * tam);

  for (int i = 0; i < tam; i++) {
    h->vetor[i] = NULL;
  }

  return h;
}

void *busca(Hash *hash, void* key, int (*fhash)(void *),
            int (*comp)(void *, void *)) {
  // usa a funcao de hash para gerar o indice da tabela correspondente a chave
  int indice = fhash(key);
  Lista *l = hash->vetor[indice];

  // se nao existir, retorna NULL
  if (!l)
    return NULL;

  // se existir, varre a lista e compara ve se é igual
  l = buscaNaLista(l, comp, key);

  return l;
}

void *hash_insere(Hash *thash, void* key, void *objeto, int (*hash)(void *), int (*comp)(void *, void *)) {

  // usa a funcao de hash para gerar o indice da tabela correspondente a chave
  int indice = hash(key);
  
  // acessa a posicao da tabela hash e insere na lista
  thash->vetor[indice] = insereLista(thash->vetor[indice], objeto);
}

void libera(Hash *table) {
  for (int i = 0; i < table->tam; i++) {
    liberaLista(table->vetor[i]);
  }
  free(table->vetor);
  free(table);
}

void imprime(Hash *thash, void (*cb)(void *)) {
  for (int i = 0; i < thash->tam; i++) {
    printf("\nHash [%d]", i);
    imprimeLista(thash->vetor[i], cb);
    printf("\n");
  }
}