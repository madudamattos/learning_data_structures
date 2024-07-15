#include "fila.h"
#include "amostra.h"
#include <stdio.h>
#include <stdlib.h>


#define TAM 20


struct fila{
    int n;
    int ini;
    void* vetor[TAM];
};


Fila* criaFila(){
    Fila* f = calloc(1, sizeof(Fila));

    f->n = 0;
    f->ini = 0; 

    return f;
}

void insereInicFila(Fila* f, void* elemento){
    if(!f || !elemento || f->n >= TAM){
        printf("Fila cheia ou inválida ou elemento inválido!\n");
        return;
    }

    int novoInicio;

    if(f->ini == 0) novoInicio = 0;
    else novoInicio = f->ini - 1;

    f->ini = novoInicio;

    f->vetor[novoInicio] = elemento;
    f->n++;
}

void insereFila(Fila* f, void* elemento){
    if(!f || !elemento || f->n >= TAM){
        printf("Fila cheia ou inválida ou elemento inválido!\n");
        return;
    }

    int posLivre = (f->n + f->ini) % TAM;

    f->vetor[posLivre] = elemento;

    f->n++;
}

void* retiraFila(Fila* f){
    if(!f || f->n == 0){
        printf("Fila inválida ou vazia!\n");
        return NULL;
    }

    void* elemento;

    elemento = f->vetor[f->ini];
    f->ini = (f->ini + 1) % TAM;
    
    f->n--;

    return elemento;
}

void destroiFila(Fila* f){
    if(f){
        free(f);
    }
}

int ehVaziaFila(Fila* f){
    if(!f)return -1;
    if(f->n == 0) return 1;
    return 0;
}

void imprimeFila(Fila* f){

    if(!f) return; 

    for(int i=0; i<f->n; i++){
        int indice = (f->ini + i) % TAM;
        imprimeAmostra(f->vetor[indice]);
    }

    printf("\n");

}
