/* Exercicio 13

Implemente um TAD árvore binária de busca (ABB) de alunos, com as funcionalidades básicas de: criação, busca, impressão, inserção, retirada e liberação. Você escolhe o critério de ordenação para sua ABB.

Implemente um testador para sua implementação.

*/

#ifndef ARV_BUSCA_H
#define ARV_BUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Abb;

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int matricula);

Aluno* retornaAlunoNo(Abb* a);

void imprimeAluno(Aluno* aluno);

void liberaAluno(Aluno* aluno);

Abb* cria_arv();

void imprime_arv(Abb* a);

Abb* insere_arv(Abb* a, Aluno* s);

Abb* busca_arv(Abb* a, int chave);

Abb* retira_arv(Abb* a, int chave);

void libera_arv(Abb* a);

#endif //  ABB_H
