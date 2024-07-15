#ifndef lista_h
#define lista_h

#include "produto.h"
#include <stdio.h>

typedef struct lista tLista;

typedef struct celula tCelula;

tLista *criaLista();

tCelula *criaCelula();

void adicionaProdutoCelula(tCelula *celula, tProduto *prod);

void adicionaProxCelula(tCelula *celula, tCelula *proxCelula);

void liberaCelula(tCelula *celula);

int insereLista(tProduto *prod, tLista *lista);

int retiraListaPorID(int id, tLista *lista);

int retiraListaPorNome(char nome[], tLista *lista);

void imprimeLista(tLista *lista);

void liberaLista(tLista *);

int ehVaziaLista(tLista *lista);

#endif