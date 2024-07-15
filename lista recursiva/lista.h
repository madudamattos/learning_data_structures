#ifndef lista_h
#define lista_h

#include <stdio.h>

typedef struct lista tLista;

tLista *criaLista();

tLista *insereLista(tLista *lista, int item);

tLista *retiraLista(tLista *lista, int item);

void imprimeLista(tLista *lista);

void liberaLista(tLista *lista);

#endif