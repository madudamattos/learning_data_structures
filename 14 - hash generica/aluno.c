#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  int mat;
  char *nome;
};

Aluno *iniciaAluno(int mat, char *nome) {
  Aluno *a = malloc(sizeof(Aluno));
  a->mat = mat;
  a->nome = strdup(nome);

  return a;
}

void imprimeAluno(Aluno *aluno) {
  printf("\nNome:%s  Matricula:%d ", aluno->nome, aluno->mat);
}

int* retornaMat(Aluno *aluno) { 
  return &aluno->mat; 
}

char *retornaNomeAluno(Aluno *aluno) { 
  return aluno->nome;
}

void destroiAluno(Aluno *aluno) {
  free(aluno->nome);
  free(aluno);
}

int comparacaoMat(Aluno *aluno, int* mat) {
  // retorna 0 se forem iguais
  if (aluno->mat == *mat){
    return 0;
  }

  // retorna 1 se forem diferentes
  return 1;
}


