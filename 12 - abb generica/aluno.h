#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *iniciaAluno(char *nome, int mat);

void imprimeAluno(void *aluno);

int retornaMat(Aluno *aluno);

char *retornaNomeAluno(Aluno *aluno);

void liberaAluno(Aluno *aluno);

// retorna 1 mat 1 for maior que mat 2, retorna -1 se mat 1 for menor que mat 2 e retorna 0 se for igual
int comparaMatricula(void* aluno1, void* aluno2);

// int comparaMatriculaGen(void* aluno1, void* aluno2);

// void imprimeAlunoGen(void* aluno);

#endif