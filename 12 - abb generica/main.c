/*
A ideia do exercício é implementar uma ABB Genérica! Escolha uma das opções
abaixo:
=> opção1 (mais rápida): 1 tad genérico e 1 cliente implementando todos os
callbacks
=> opção2 (mais demorada, porém com modularização): 1 tad genérico e 1 tad para
cada uso específico da árvore e 1 cliente.

Testem a árvore genérica com 2 tipos de chave de busca. Por exemplo, em uma
árvore de alunos, deve-se fazer busca por nome ou por matrícula.
*/

#include <stdio.h>
#include "aluno.h"
#include "arvore.h"

int main(void) {
  // Cria alguns alunos
  Aluno* aluno1 = iniciaAluno("Alice", 1);
  Aluno* aluno2 = iniciaAluno("Bob", 2);
  Aluno* aluno3 = iniciaAluno("Charlie", 3);
  Aluno* aluno4 = iniciaAluno("David", 4);
  Aluno* aluno5 = iniciaAluno("Eve", 5);
  Aluno* aluno6 = iniciaAluno("Frank", 6);
  Aluno* aluno7 = iniciaAluno("Grace", 7);


  printf("%d %d %d", comparaMatricula(aluno1, aluno2), comparaMatricula(aluno3, aluno2), comparaMatricula(aluno5, aluno5));


  // Cria uma árvore
  Abb* arvore = cria_arv();

  // Insere alunos na árvore
  arvore = insere_arv(arvore, aluno4, comparaMatriculaGen); 
  arvore = insere_arv(arvore, aluno2, comparaMatriculaGen);
  arvore = insere_arv(arvore, aluno6, comparaMatriculaGen);
  arvore = insere_arv(arvore, aluno1, comparaMatriculaGen);
  arvore = insere_arv(arvore, aluno3, comparaMatriculaGen);
  arvore = insere_arv(arvore, aluno5, comparaMatriculaGen);
  arvore = insere_arv(arvore, aluno7, comparaMatriculaGen);

  // Imprime a árvore
  printf("Árvore após inserções:\n");
  imprime_arv(arvore, imprimeAlunoGen);

  // Testa remoção de uma folha
  printf("\nRemovendo uma folha (Aluno com matrícula 1):\n");
  arvore = retira_arv(arvore, comparaMatriculaGen, aluno1);
  imprime_arv(arvore, imprimeAlunoGen);

  // Testa remoção de um nó com um filho
  printf("\nRemovendo um nó com um filho (Aluno com matrícula 6):\n");
  arvore = retira_arv(arvore, comparaMatriculaGen, aluno6);
  imprime_arv(arvore, imprimeAlunoGen);

  // Testa remoção de um nó com dois filhos
  printf("\nRemovendo um nó com dois filhos (Aluno com matrícula 2):\n");
  arvore = retira_arv(arvore, comparaMatriculaGen, aluno2);
  imprime_arv(arvore, imprimeAlunoGen);

  // Testa remoção da raiz
  printf("\nRemovendo a raiz (Aluno com matrícula 4):\n");
  arvore = retira_arv(arvore, comparaMatriculaGen, aluno4);
  imprime_arv(arvore, imprimeAlunoGen);

  // Libera a árvore
  libera_arv(arvore);

  // Libera os alunos (caso não tenham sido liberados pela árvore)

  liberaAluno(aluno1);
  liberaAluno(aluno2);
  liberaAluno(aluno3);
  liberaAluno(aluno4);
  liberaAluno(aluno5);
  liberaAluno(aluno6);
  liberaAluno(aluno7);

  printf("\nPrograma finalizado!\n");

  return 0;
}