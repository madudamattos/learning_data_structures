#ifndef ALUNO_H
#define ALUNO_H

// Definição da estrutura Aluno
typedef struct aluno Aluno;

// Função para inicializar um novo aluno
Aluno *iniciaAluno(int mat, char *nome);

// Função para imprimir os dados de um aluno
void imprimeAluno(Aluno *aluno);

// Função para retornar a matrícula de um aluno
int* retornaMat(Aluno *aluno);

// Função para retornar o nome de um aluno
char *retornaNomeAluno(Aluno *aluno);

// Função para liberar a memória de um aluno
void destroiAluno(Aluno *aluno);

// Função para comparar a matrícula de um aluno com um inteiro
int comparacaoMat(Aluno *aluno, int* mat);

#endif // ALUNO_H
