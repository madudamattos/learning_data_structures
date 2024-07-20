#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>

typedef struct aluno Aluno;

Aluno* IniciaAluno (int mat, char* nome, float cr);

void imprimeAluno (Aluno* aluno);

int retornaMat (Aluno* aluno);

char* retornaNomeAluno (Aluno* aluno);

float retornaCR (Aluno* aluno);

void destroiAluno (Aluno* aluno);

#endif 