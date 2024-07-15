#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz {
  int linhas;
  int colunas;
  int **mat;
};
0
/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz *inicializaMatriz(int nlinhas, int ncolunas) {

  if (nlinhas <= 0 || ncolunas <= 0) {
    return NULL;
  }

  Matriz *mat = (Matriz *)malloc(sizeof(Matriz));

  mat->linhas = nlinhas;
  mat->colunas = ncolunas;

  mat->mat = calloc(nlinhas, sizeof(int *));
  for (int i = 0; i < nlinhas; i++) {
    mat->mat[i] = calloc(ncolunas, sizeof(int));
  }

  printf("Insira os elementos da matriz:\n");

  for (int i = 0; i < nlinhas; i++) {
    for (int j = 0; j < ncolunas; j++) {
      scanf("%d", &mat->mat[i][j]);
    }
  }

  return mat;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento(Matriz *mat, int linha, int coluna, int elem) {
  mat->mat[linha][coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna s„o v·lidos na matriz
 * pos-condicao: mat n„o È modificada
 */
int recuperaElemento(Matriz *mat, int linha, int coluna) {
  return mat->mat[linha][coluna];
}

/*Retorna o n˙mero de colunas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNColunas(Matriz *mat) { return mat->colunas; }

/*Retorna o n˙mero de linhas da matriz mat
 * inputs: a matriz
 * output: o n˙mero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada
 */
int recuperaNLinhas(Matriz *mat) { return mat->linhas; }

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat n„o È modificada e matriz transposta existe
 */
Matriz *transposta(Matriz *mat) {
  if (mat == NULL)
    return NULL;

  Matriz *transposta = calloc(1, sizeof(Matriz));

  transposta->linhas = mat->colunas;
  transposta->colunas = mat->linhas;

  transposta->mat = calloc(transposta->linhas, sizeof(int *));

  for (int i = 0; i < transposta->linhas; i++) {
    transposta->mat[i] = calloc(transposta->colunas, sizeof(int));
  }

  for (int i = 0; i < mat->linhas; i++) {
    for (int j = 0; j < mat->colunas; j++) {
      transposta->mat[j][i] = mat->mat[i][j];
    }
  }

  return transposta;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicaÁ„o
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 n„o s„o modificadas e a matriz multiplicacao
 * existe
 */
Matriz *multiplicacao(Matriz *mat1, Matriz *mat2) {
  if (mat1 == NULL || mat2 == NULL)
    return NULL;

  else if (mat1->colunas != mat2->linhas) {
    printf("Não é possível realizar a multiplicação\n");
    return NULL;
  }

  Matriz *resultado = calloc(1, sizeof(Matriz));

  resultado->linhas = mat1->linhas;
  resultado->colunas = mat2->colunas;

  resultado->mat = calloc(resultado->linhas, sizeof(int *));

  for (int i = 0; i < resultado->linhas; i++) {
    resultado->mat[i] = calloc(resultado->colunas, sizeof(int));
  }

  for (int i = 0; i < mat1->linhas; i++) {
    for (int j = 0; j < mat2->colunas; j++) {
      for (int k = 0; k < mat1->colunas; k++) {
        resultado->mat[i][j] += mat1->mat[i][k] * mat2->mat[k][j];
      }
    }
  }

  return resultado;
}


/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz *mat) {

  if (mat == NULL)
    return;

  for (int i = 0; i < mat->linhas; i++) {
    for (int j = 0; j < mat->colunas; j++) {
      printf("%d ", mat->mat[i][j]);
    }
    printf("\n");
  }
}

void imprimeLinhas(Matriz *mat, int indice) {
  for (int i = 0; i < mat->colunas; i++) {
    printf("%d", mat->mat[indice][i]);
  }
}

void destroiMatriz(Matriz *mat) {
  for (int i = 0; i < mat->linhas; i++) {
    free(mat->mat[i]);
  }
  free(mat->mat);

  free(mat);
}