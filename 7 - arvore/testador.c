#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){

    Aluno* a1 = criaAluno("a1");
    Aluno* a2 = criaAluno("a2");
    Aluno* a3 = criaAluno("a3");
    Aluno* a4 = criaAluno("a4");
    Aluno* a5 = criaAluno("a5");
    Aluno* a6 = criaAluno("a6");
    Aluno* a7 = criaAluno("a7");

    //nivel 3
    Arv* v7 = arv_cria(a4, NULL, NULL);
    Arv* v8 = arv_cria(a3, NULL, NULL);
    Arv* v9 = arv_cria(a3, NULL, NULL); 
    //nivel 2
    Arv* v4 = arv_cria(a4, NULL, NULL); 
    Arv* v5 = arv_cria(a5, v7, NULL);
    Arv* v6 = arv_cria(a6, v8, v9);
    //nivel 1
    Arv* v2 = arv_cria(a2, NULL, v4);
    Arv* v3 = arv_cria(a3, v5, v6);
    //nivel 0
    Arv* v1 = arv_cria(a1, v2, v3);
    
    printf("\nArvore A1:\n");
    arv_imprime(v1);

    printf("O numero de folhas dessa árvore é: %d\n", arv_folhas(v1));

    //aluno 4 e aluno 3 se repetem 2 vezes;

    printf("O aluno 6 pertence a arvore: %d\n", arv_pertence(v1, a6));
    printf("O aluno 7 pertence a arvore: %d\n", arv_pertence(v1, a7));

    printf("O aluno 1 aparece: %d\n", arv_ocorrencias(v1, "a1"));
    printf("O aluno 2 aparece: %d\n", arv_ocorrencias(v1, "a2"));
    printf("O aluno 3 aparece: %d\n", arv_ocorrencias(v1, "a3"));
    printf("O aluno 4 aparece: %d\n", arv_ocorrencias(v1, "a4"));
    printf("O aluno 5 aparece: %d\n", arv_ocorrencias(v1, "a5"));
    printf("O aluno 6 aparece: %d\n", arv_ocorrencias(v1, "a6"));
    printf("O aluno 7 aparece: %d\n", arv_ocorrencias(v1, "a7"));

    arv_libera(v1);

    liberaALuno(a1);
    liberaALuno(a2);
    liberaALuno(a3);
    liberaALuno(a4);
    liberaALuno(a5);
    liberaALuno(a6);

    return 0;
}