#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tipo opaco palavra, que tambem é uma lista
typedef struct palavra Palavra;

Palavra* inicPalavra (char* str);

char* retornaString(Palavra* pal);

void atualizaOcorrencias(Palavra* pal);

int retornaOcorrencias(Palavra* pal);

// Busca palavra na lista de colisoes
Palavra* buscaPalavra(Palavra* pal, char* string);

// Insere palavra na lista de colisoes
Palavra* inserePalavrasLista(Palavra* lista, Palavra* p);

int contaPalavrasLista(Palavra* p);

void imprimeLista(Palavra* p);

void liberaListaPalavras(Palavra* p);

#endif