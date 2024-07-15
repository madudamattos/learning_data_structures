#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int linha;
  int coluna;

  printf("Insira a quantidade de linhas da primeira matriz:");
  scanf("%d", &linha);
  printf("Insira a quantidade de colunas da primeira matriz:");
  scanf("%d", &coluna);

  Matriz *mat1 = inicializaMatriz(linha, coluna);

  printf("Insira a quantidade de linhas da segunda matriz:");
  scanf("%d", &linha);
  printf("Insira a quantidade de colunas da segunda matriz:");
  scanf("%d", &coluna);

  Matriz *mat2 = inicializaMatriz(linha, coluna);

  printf("As matrizes inicializadas são:\n\n");
  imprimeMatriz(mat1);
  printf("\n");
  imprimeMatriz(mat2);

  printf("As transpostas das duas matrizes são:\n\n");

  Matriz *tmat1 = transposta(mat1);
  Matriz *tmat2 = transposta(mat2);

  imprimeMatriz(tmat1);
  printf("\n");
  imprimeMatriz(tmat2);

  Matriz *m1 = multiplicacao(mat1, mat2);
  Matriz *m2 = multiplicacao(mat2, mat1);

  printf("As matrizes multiplicadas são:\n\n");
  printf("Matriz 1 x Matriz 2:\n");
  imprimeMatriz(m1);
  printf("Matriz 2 x Matriz 1:\n");
  imprimeMatriz(m2);

  destroiMatriz(tmat1);
  destroiMatriz(tmat2);
  destroiMatriz(m1);
  destroiMatriz(m2);
  destroiMatriz(mat1);
  destroiMatriz(mat2);

  return 0;
}