/*

PROVA 2 DA DISCIPLINA DE ESTRUTURA DE DADOS I
ALUNA: MARIA EDUARDA NOIA MATTOS DE AZEVEDO
DATA: 29/07/2024

*/


#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadpais.h"

typedef struct lista Lista;

// retorna o pais contido na Lista
Pais* retornaPais(Lista* l);

// retorna proximo elemento da lista
Lista* retornaProx(Lista* l);

// cria lsita vazia
Lista* criaLista();

// insere no inicio da lista
Lista* insereLista(Lista* l, Pais* p);

// busca pais por nome na lista, se nao tiver retorna NULL
Lista* buscaLista(Lista* l, char* nomePais);

// libera lista e ja libera o pais
void liberaLista(Lista* l);

// imprime lista de paises
void imprimeLista(Lista* l);


#endif