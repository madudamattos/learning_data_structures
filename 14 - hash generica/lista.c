#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
  void *info;
  Lista *prox;
};

// cria lista vazia
Lista *cria_lista() {
  return NULL;
}

// insere lista no inicio
Lista *insereLista(Lista *l, void *info) {
  Lista *nova = (Lista *)malloc(sizeof(Lista));
  nova->info = info;
  nova->prox = l;

  return nova;
}

// retira lista por chave e retorna o elemento retirado
// a funcao de callback tem que retornar 0 quando os elementos forem iguais
Lista *retiraLista(Lista *l, int (*cb)(void *, void *), void *chave) {
  Lista *p = l;
  Lista *ant = NULL;

  while (p && cb(p->prox, chave)) {
    ant = p;
    p = p->prox;
  }

  // se a lista for vazia -> !p
  if (!p)
    return NULL;

  if (!ant) {
    l = NULL;
  } else {
    ant->prox = p->prox;
  }

  free(p);

  return l;
}

// retorna um ponteiro para o objeto encontrado, caso contrario retorna NULL
Lista *buscaNaLista(Lista *l, int (*cb)(void *, void *), void *chave) {

  for (Lista* lista = l; lista != NULL; lista = lista->prox) {
    int r = cb(l->info, chave);
    if (r == 0)
      return lista;
  }

  return NULL;
}

void imprimeLista(Lista *l, void (*cb)(void *)) {
  Lista *lista;

  for (lista = l; lista != NULL; lista = lista->prox) {
    cb(l->info);
  }
}

// libera lista
// nao libera os itens, responsabilidade do cliente
void liberaLista(Lista *l) {
  Lista *lista = l;
  Lista *temp;

  while(lista) {
    temp = lista->prox;
    free(lista);
    lista = temp;
  }
}

