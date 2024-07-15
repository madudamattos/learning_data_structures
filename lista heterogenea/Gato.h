#ifndef GATO_H
#define GATO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAVO 0
#define MANSO 1

typedef struct gato Gato;

Gato* inicGato(char* nome, int agressividade);

void liberaGato(Gato* cat);

int retornaNivelAgressividadeGato(Gato*);

char* retornaNomeGato(Gato*);

void imprimeGato(Gato*);

void atribuiNivelAgressividadeGato(Gato*, int);

#endif 