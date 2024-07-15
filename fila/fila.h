#ifndef fila_h
#define fila_h

#include "amostra.h"

typedef struct fila Fila;


Fila* criaFila();

void insereInicFila(Fila*, void*);

void insereFila(Fila*, void*);

void* retiraFila(Fila*);

void destroiFila(Fila*);

int ehVaziaFila(Fila* f);

void imprimeFila(Fila* f);

#endif
