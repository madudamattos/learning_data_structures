#include "lista.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula {
  tProduto *produto;
  struct celula *prox;
};

struct lista {
  tCelula *prim;
  tCelula *ult;
  int tam;
};

tLista *criaLista() {
  tLista *lista = calloc(1, sizeof(struct lista));

  lista->prim = NULL;
  lista->ult = NULL;
  lista->tam = 0;

  return lista;
}

tCelula *criaCelula() {
  tCelula *cel = calloc(1, sizeof(tCelula));

  cel->produto = NULL;
  cel->prox = NULL;

  return cel;
}

void adicionaProdutoCelula(tCelula *celula, tProduto *prod) {
  celula->produto = prod;
}

void adicionaProxCelula(tCelula *celula, tCelula *proxCelula) {
  celula->prox = proxCelula;
}

void liberaCelula(tCelula *celula) { free(celula); }

int insereLista(tProduto *prod, tLista *lista) {
  tCelula *cel = criaCelula();
  adicionaProdutoCelula(cel, prod);

  // verifica se é o primeiro;
  if (ehVaziaLista(lista)) {
    lista->prim = cel;
    lista->ult = cel;
  }
  // se nao for o primeiro
  else {
    adicionaProxCelula(lista->ult, cel);
    lista->ult = cel;
  }

  lista->tam++;

  return 1;
}

int retiraListaPorID(int id, tLista *lista) {
  tCelula *ant = NULL;
  tCelula *atual = NULL;
  tCelula *prox = NULL;
  int found = 0;

  for (int i = 0; i < lista->tam; i++) {
    if (i == 0) {
      atual = lista->prim;
      prox = lista->prim->prox;
    } else {
      ant = atual;
      atual = prox;
      prox = prox->prox;
    }

    if (id == retornaCodigoProduto(atual->produto)) {
      found = 1;
      break;
    }
  }

  if (found) {
    // se for o primeiro da lista
    if (ant == NULL) {
      lista->prim = atual->prox;
    }
    // se for o ultimo da lista
    else if (prox == NULL) {
      ant->prox = NULL;
      lista->ult = ant;
    }
    // se estiver na metade da lista
    else {
      ant->prox = prox;
    }

    free(atual);
    lista->tam--;
  }

  return found;
}

int retiraListaPorNome(char nome[], tLista *lista) {
  tCelula *ant = NULL;
  tCelula *atual = NULL;
  tCelula *prox = NULL;
  int found = 0;
  char nomeAtual[100];

  for (int i = 0; i < lista->tam; i++) {
    if (i == 0) {
      atual = lista->prim;
      prox = lista->prim->prox;
    } else {
      ant = atual;
      atual = prox;
      prox = prox->prox;
    }

    strcpy(nomeAtual, retornaNomeProduto(atual->produto));

    if (strcmp(nomeAtual, nome) == 0) {
      found = 1;
      break;
    }
  }

  if (found) {
    // se for o primeiro da lista
    if (ant == NULL) {
      lista->prim = atual->prox;
    }
    // se for o ultimo da lista
    else if (prox == NULL) {
      ant->prox = NULL;
      lista->ult = ant;
    }
    // se estiver na metade da lista
    else {
      ant->prox = prox;
    }

    free(atual);
    lista->tam--;
  }

  return found;
}

void imprimeLista(tLista *lista) {
  tProduto *prod = NULL;
  tCelula *prox = NULL;

  printf("\n");

  for (int i = 0; i < lista->tam; i++) {
    if (i == 0) {
      prod = lista->prim->produto;
      prox = lista->prim->prox;
    } else {
      prod = prox->produto;
      prox = prox->prox;
    }
    imprimeProduto(prod, i);
  }

  printf("\n");
}

void liberaLista(tLista *l) {
  tCelula *atual = NULL;
  tCelula *prox = NULL;

  for (int i = 0; i < l->tam; i++) {
    if (i == 0) {
      atual = l->prim;
      prox = l->prim->prox;

    } else {
      atual = prox;
      prox = prox->prox;
    }
    free(atual);
  }

  free(l);
}

int ehVaziaLista(tLista *lista) {
  if (lista->prim == NULL) {
    return 1;
  }
  return 0;
}
