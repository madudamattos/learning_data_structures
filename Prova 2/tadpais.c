/*

PROVA 2 DA DISCIPLINA DE ESTRUTURA DE DADOS I
ALUNA: MARIA EDUARDA NOIA MATTOS DE AZEVEDO
DATA: 29/07/2024

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadpais.h"

struct pais{
    char* nome;
    int ouro;
    int prata;
    int bronze;
    int total;
};

char* retornaNome(Pais* p){
    return p->nome;
}

int retornaOuro(Pais* p){
    return p->ouro;
}

int retornaPrata(Pais* p){
    return p->prata;
}

int retornaBronze(Pais* p){
    return p->bronze;
}

int retornaTotal(Pais* p){
    return p->total;
}

Pais* criaPais(char* nome, int ouro, int prata, int bronze, int total){
    Pais* p = malloc(sizeof(Pais));

    if(!p){
        printf("Nao foi possivel criar pais!");
        return NULL;
    }

    p->nome = strdup(nome);
    p->ouro = ouro;
    p->prata = prata;
    p->bronze = bronze;
    p->total = total;

    return p;
}

void atualizaMedalhas(Pais* p, int ouro, int prata, int bronze, int total){
    if(!p){
        printf("pais invalido ou inexistente!");
        return;
    }
    
    p->ouro = ouro;
    p->prata = prata;
    p->bronze = bronze;
    p->total = total;
}


void imprimePais(Pais* p){
    printf("%s %d %d %d %d\n", p->nome, p->ouro, p->prata, p->bronze, p->total);
}

void imprimePaisArquivo(Pais* p, FILE* arquivo){
    fprintf(arquivo, "%s %d %d %d %d\n", p->nome, p->ouro, p->prata, p->bronze, p->total);
}

void liberaPais(Pais* p){
    free(p->nome);
    free(p);
}

void liberaPaises(Pais** p, int total){
    for(int i=0; i<total; i++){
        liberaPais(p[i]);
    }
    free(p);
}

void imprimePaises(Pais** p, int total){
    for(int i=0; i< total; i++){
        imprimePais(p[i]);
    }
}


void imprimePaisesArquivo(Pais** p, int total, FILE* arquivo){
    for(int i=0; i<total; i++){
        imprimePaisArquivo(p[i],arquivo);
    }
}

int comparaPaises(const void* a, const void* b){
    Pais** pais1 = (void*)a;
    Pais** pais2 = (void*)b;

    Pais* p1 = *pais1;
    Pais* p2 = *pais2;

    // compara as medalhas de ouro
    if(p1->ouro > p2->ouro) return -1;
    else if(p1->ouro < p2->ouro) return 1;
    else {
        // compara as medalhas de prata;
        if(p1->prata > p2->prata) return -1;
        else if(p1->prata < p2->prata) return 1;
        else {
            // compara as medalhas de bronze
            if(p1->bronze > p2->bronze) return -1;
            else if(p1->bronze < p2->bronze) return 1;
            else return 0;
        }
    }

    return 0;
}

