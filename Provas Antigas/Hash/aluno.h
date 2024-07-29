#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>

// Definição da estrutura Aluno
typedef struct aluno Aluno;

// Função que retorna o nome de um aluno (retorna um void* para manter a função genérica)
void* retornaNomeAluno(void* a);

// Função que cria um novo aluno
Aluno* criaAluno(char* nome);

// Função que verifica se dois alunos são iguais
int ehIgualAluno(void* aluno1, void* aluno2);

// Função que imprime os dados de um aluno
void imprimeAluno(void* aluno);

// Função que imprime os dados de um aluno em um arquivo
void imprimeAlunoArquivo(void* aluno, FILE* arquivo);

// Função de hash que soma os códigos ASCII de todas as letras do nome do aluno
int hashAluno(void* key, int tamanhoTabela);


void incrementaPresenca(void* aluno);

void incrementaFalta(void* aluno);

void liberaAluno(void* aluno);

#endif // ALUNO_H
