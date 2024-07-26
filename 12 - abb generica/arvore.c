#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore {
  void *conteudo;
  Abb *esq;
  Abb *dir;
};

Abb *cria_arv() { return NULL; }

void* retornaArvConteudo(Abb* a){
  return a->conteudo;
}

void imprime_arv(Abb *arv, void (*cb)(void *)) {
  if (!arv)
    return;

  imprime_arv(arv->esq, cb);
  imprime_arv(arv->dir, cb);
  cb(arv->conteudo);
}

// a funcao comp compara o valor de duas chaves, retorna 0 se forem iguais, 1 se
// a prmieira for maior que a segunda e -1 caso contrario
Abb *insere_arv(Abb *arv, void *conteudo, int (*comp)(void *, void *)) {
  if (!arv) {
    arv = calloc(1, sizeof(Abb));
    arv->conteudo = conteudo;
    arv->dir = arv->esq = NULL;
  }

  if (comp(arv->conteudo, conteudo) > 0) {
    arv->dir = insere_arv(arv->dir, conteudo, comp);
  } else if (comp(arv->conteudo, conteudo) < 0) {
    arv->esq = insere_arv(arv->esq, conteudo, comp);
  }

  return arv;
}

// a funcao comp anda pela arvore da forma como ela esta ordenada
Abb *busca_arv(Abb *arv, int (*comp)(void *, void *), void *conteudo) {
  if (!arv)
    return NULL;

  if (comp(arv->conteudo, conteudo) > 0) {
    return busca_arv(arv->esq, comp, conteudo);
  } else if (comp(arv->conteudo, conteudo) < 0) {
    return busca_arv(arv->dir, comp, conteudo);
  } else {
    return arv;
  }
}

Abb *retira_arv(Abb *arv, int (*comp)(void *, void *), void *conteudo) {
  if (!arv)
    return NULL;
  else if (comp(arv->conteudo, conteudo) > 0) {
    arv->esq = retira_arv(arv->esq, comp, conteudo);
  } else if (comp(arv->conteudo, conteudo) < 0) {
    arv->dir = retira_arv(arv->dir, comp, conteudo);
  } else {
    // se for folha solta, ai so desaloca
    if (!arv->esq && !arv->dir) {
      free(arv);
      arv = NULL;
    }
    // se for no com um filho
    else if (!arv->esq && arv->dir) {
      Abb *aux = arv;
      arv = aux->dir;
      free(aux);
    } else if (arv->esq && !arv->dir) {
      Abb *aux = arv;
      arv = arv->esq;
      free(aux);
    }
    // se for no com dois filhos
    else {
      // acha o antecessor do no
      Abb *ant = arv->esq;
      while (ant->dir)
        ant = ant->dir;
      // faz a troca das informacoes
      void *aux = arv->conteudo;
      arv->conteudo = ant->conteudo;
      ant->conteudo = aux;
      arv->esq = retira_arv(arv->esq, comp, ant->conteudo);
    }
  }

  return arv;
}

void libera_arv(Abb *arv) {
  if (!arv)
    return;

  libera_arv(arv->esq);
  libera_arv(arv->dir);
  free(arv);
}
