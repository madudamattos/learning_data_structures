#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct lista {
  int conteudo;
  tLista *prox;
};

tLista *criaLista() { return NULL; }

tLista *insereLista(tLista *lista, int item) {
  tLista *l = calloc(1, sizeof(tLista));

  l->conteudo = item;
  l->prox = NULL;

  if (lista != NULL) {
    l->prox = lista;
  }

  return l;
}

tLista *retiraLista(tLista *lista, int item) {
  if (!lista)
    return NULL;

  if (lista->conteudo == item) {
    tLista *prox = lista->prox;
    free(lista);
    return prox;
  }

  lista->prox = retiraLista(lista->prox, item);

  return lista;
}

void imprimeLista(tLista *lista) {
  if (lista == NULL) {
    printf("Lista vazia\n");
    return;
  }

  printf("Lista: %d\n", lista->conteudo);
  if (lista->prox) {
    imprimeLista(lista->prox);
  }
}

void liberaLista(tLista *lista) {
  tLista *prox;
  if (lista != NULL) {
    prox = lista->prox;
    free(lista);
    liberaLista(prox);
  }

  return;
}