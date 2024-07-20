#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

typedef struct aluno{
    char* nome;
}Aluno;

typedef struct arvore{
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
}Arv;

//cria aluno
Aluno* criaAluno(char* nome){
    Aluno* aluno = calloc(1, sizeof(Aluno));
    aluno->nome = strdup(nome);

    return aluno;
}

//libera aluno
void liberaALuno(Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}

//Cria uma árvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (Aluno* aluno, Arv* e, Arv* d){
    Arv* a = calloc(1, sizeof(Arv));

    a->aluno = aluno;
    a->esq = e;
    a->dir = d;

    return a;
}

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a){
    if(!a) return NULL;
    
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);

    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (Arv* a){
    if(!a) return 1;
    return 0;
}

//indica a ocorrência do aluno na arvore
int arv_pertence (Arv* a, Aluno* aluno){
    if(arv_vazia(a)) return 0;

    return  a->aluno == aluno || 
            arv_pertence(a->dir, aluno) ||
            arv_pertence(a->esq, aluno);
}

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a){
    if(arv_vazia(a)){
        return;
    }
    printf("Aluno: %s\n", a->aluno->nome);
    arv_imprime(a->esq);
    arv_imprime(a->dir);
}

//retorna o número de folhas da árvore
int arv_folhas(Arv* a) {

    if (arv_vazia(a)) return 0;

    if (a->esq == NULL && a->dir == NULL) return 1;
    
    return arv_folhas(a->esq) + arv_folhas(a->dir);
}


//retorna o número de vezes que o aluno aparece na árvore
int arv_ocorrencias (Arv* a , char* nome){
    int ocorrencias = 0;

    if (arv_vazia(a)) return 0;

    if (strcmp(a->aluno->nome, nome) == 0) ocorrencias = 1;
    
    return ocorrencias + arv_ocorrencias(a->esq, nome) + arv_ocorrencias(a->dir, nome);
}

//retorna o maior dos dois inteiros
int max2 (int a, int b)
{
    return (a > b) ? a : b;
}

//retorna a altura da árvore
int arv_altura (Arv* a){
    if (arv_vazia(a)){
        return -1;
    } 
    else {
        return 1 + max2 (arv_altura (a->esq), arv_altura(a->dir));
    }
} 
