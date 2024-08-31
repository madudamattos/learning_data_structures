/*

PROVA 2 DA DISCIPLINA DE ESTRUTURA DE DADOS I
ALUNA: MARIA EDUARDA NOIA MATTOS DE AZEVEDO
DATA: 29/07/2024

*/


#ifndef PAIS_H
#define PAIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadpais.h"

typedef struct pais Pais;

char* retornaNome(Pais* p);

int retornaOuro(Pais* p);

int retornaPrata(Pais* p);

int retornaBronze(Pais* p);

int retornaTotal(Pais* p);

Pais* criaPais(char* nome, int ouro, int prata, int bronze, int total);

void atualizaMedalhas(Pais* p, int ouro, int prata, int bronze, int total);

void imprimePais(Pais* p);

void imprimePaisArquivo(Pais* p, FILE* arquivo);

void imprimePaises(Pais** p, int total);

void imprimePaisesArquivo(Pais** p, int total, FILE* arquivo);

void liberaPais(Pais* p);

void liberaPaises(Pais** p, int total);

int comparaPaises(const void* a, const void* b);

#endif