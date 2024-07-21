#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"
#include "listaAlunos.h"

typedef struct cr{
    int n;    //n de alunos
    float CR; //CR acumulado
}CR;

static int comparacaoMat(void* aluno, void* mat) {
    Aluno* a = (Aluno*) aluno;
    int* imat = (int*) mat;

    //retorna 0 se forem iguais
    if(retornaMat(a) == *imat) return 0;

    //retorna 1 se forem diferentes
    return 1;
}

static int imprime(void* aluno, void* dado) {
    imprimeAluno(aluno);
    return 1;
}

static int acumula(void* aluno, void* dado) {
    CR* acumulado = (CR*) dado;
    
    acumulado->CR += retornaCR(aluno);
    acumulado->n++;
    
    return 1;
}

ListaGen* retiraAluno(ListaGen* lista, int matricula) {
    return retiraLista(lista, comparacaoMat, &matricula);
}

int pertenceAluno(ListaGen* lista, int matricula) {
    return percorreLista(lista, comparacaoMat, &matricula);
}

void imprimeListaAlunos(ListaGen* lista) {
    if(lista==NULL){
        printf("Lista vazia\n");
    }
    percorreLista(lista, imprime, NULL);
}

float mediaTurma(ListaGen* lista) {
    CR* acumulado = (struct cr*)malloc(sizeof(CR));
    acumulado->CR = 0.0;
    acumulado->n = 0;

    percorreLista(lista, acumula, acumulado);

    float media = acumulado->CR / acumulado->n;

    free(acumulado);

    return media;
}