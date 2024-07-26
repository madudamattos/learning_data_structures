#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    int mat;
    char* nome;
};

Aluno* iniciaAluno (char* nome, int mat){
    Aluno* a = malloc(sizeof(Aluno));
    a->mat = mat;
    a->nome = strdup(nome);

    return a;
}

void imprimeAluno (Aluno* aluno){
    printf("\nNome:%s  Matricula:%d", aluno->nome, aluno->mat);
}

int retornaMat (Aluno* aluno){
    return aluno->mat;
}

char* retornaNomeAluno (Aluno* aluno){
    return aluno->nome;
}


void liberaAluno (Aluno* aluno){
    free(aluno->nome);
    free(aluno);
}

int comparaMatricula(Aluno* aluno1, Aluno* aluno2){
    if(aluno1->mat > aluno2->mat) return 1;
    else if(aluno1->mat < aluno2->mat) return -1;
    else return 0;
}


// generico

int comparaMatriculaGen(void* aluno1, void* aluno2){
    return comparaMatricula((Aluno *)aluno1, (Aluno *)aluno2);
}

void imprimeAlunoGen(void* aluno){
    imprimeAluno((Aluno*) aluno);
}