#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

struct product {
  int codigo;
  float preco;
  char nome[TAM_NOME];
};

void imprimeProduto(tProduto *produto, int num) {
  if (!produto)
    return;

  printf("Produto %d\n", num + 1);
  printf("\tNome: %s\n", produto->nome);
  printf("\tCódigo: %d\n", produto->codigo);
  printf("\tPreço: %.2f\n\n", produto->preco);
}

tProduto *criaProduto(int codigo, float preco, char nome[]) {
  tProduto *produto = calloc(1, sizeof(tProduto));
  produto->codigo = codigo;
  produto->preco = preco;
  strcpy(produto->nome, nome);

  return produto;
}

void destroiProduto(tProduto *produto) { free(produto); }

char *retornaNomeProduto(tProduto *produto) { return produto->nome; }

int retornaCodigoProduto(tProduto *produto) {
  return produto->codigo;
}