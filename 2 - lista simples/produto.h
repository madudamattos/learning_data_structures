#ifndef produto_h
#define produto_h

#include <stdio.h>

typedef struct product tProduto;

void imprimeProduto(tProduto *produto, int num);

tProduto *criaProduto(int codigo, float preco, char nome[]);

void destroiProduto(tProduto *produto);

char *retornaNomeProduto(tProduto *produto);

int retornaCodigoProduto(tProduto *produto);

#endif