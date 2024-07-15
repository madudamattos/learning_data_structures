#ifndef arvore_h
#define arvore_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

typedef struct arvore Arv;

//cria aluno
Aluno* criaAluno(char* nome);

//libera aluno
void liberaALuno(Aluno* aluno);

//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (Aluno* a, Arv* e, Arv* d);

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);

//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a);

//indica a ocorrência ou nao do aluno na arvore
int arv_pertence (Arv* a, Aluno* aluno);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

//retorna o numero de folhas em uma arvore
int arv_folhas(Arv* a);

//retorna o número de vezes que o aluno aparece na árvore
int arv_ocorrencias (Arv* a , char* nome);

//retorna o maior dos dois inteiros
int max2 (int a, int b);

//retorna a altura da árvore
int arv_altura (Arv* a);
#endif