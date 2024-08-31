/*

PROVA 2 DA DISCIPLINA DE ESTRUTURA DE DADOS I
ALUNA: MARIA EDUARDA NOIA MATTOS DE AZEVEDO
DATA: 29/07/2024

*/


#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadpais.h"
#include "tadlista.h"

typedef struct hash Hash;
typedef struct lista Lista;

// aloca memoria pra tabela e inicia todas as posicoes com NULL
Hash* criaHash(int tam);

Pais* buscaHash(Hash* h, char* nomePais);

Pais* insereHash(Hash* h, Pais* p);
// funcao de hash que soma os valor ASCII dos caracteres e retorna um indice correspondente
int hashPais(Hash* h, char* nomePais);

void imprimeHash(Hash* h);

void liberaHash(Hash* h);

void organizaPaises(Hash* thash, Pais** paises, int total);

#endif 