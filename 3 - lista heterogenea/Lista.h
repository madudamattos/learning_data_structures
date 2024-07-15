#ifndef LISTA_H
#define LISTA_H


#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista* criaLista();

void insereLista(Lista* l, int tipoAnimal, void* animal);

void imprimeLista(Lista* l);

void liberaLista(Lista* l);

void* retiraLista(Lista* l, void* item);

int buscaItemLista(Lista* l, void* item);

#endif
