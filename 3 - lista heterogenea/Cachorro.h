#ifndef CACHORRO_H
#define CACHORRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAVO 0
#define MANSO 1

typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char*, int);

void liberaCachorro(Cachorro*);

int retornaNivelAgressividadeCachorro(Cachorro*);

char* retornaNomeCachorro(Cachorro*);

void imprimeCachorro(Cachorro*);

void atribuiNivelAgressividadeCachorro(Cachorro*, int);

#endif 