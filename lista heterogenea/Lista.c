#include "Lista.h"
#include <stdio.h>
#include "Gato.h"
#include "Cachorro.h"

#define CACHORRO 2
#define GATO 3


typedef struct celula{
    void* item;
    int tipo;
    struct celula* prox;
    struct celula* ant;
} Celula;

struct lista{
    int tam;
    Celula* prim;
    Celula* ult;
};

Lista* criaLista(){
    Lista* l = calloc(1, sizeof(Lista));

    l->tam = 0;
    l->prim = NULL;
    l->ult = NULL;

    return l;
}

void insereLista(Lista* l, int tipoAnimal, void* animal){
    if(l == NULL || animal == NULL) return;

    //cria a celula para o objeto a ser colocado na lista
    Celula* cel = calloc(1, sizeof(Celula));
    cel->item = animal;
    cel->tipo = tipoAnimal;
    cel->prox = NULL;
    cel->ant = NULL;

    //quando é o primeiro da lista
    if(l->tam == 0 || l->prim == NULL){
        l->prim = cel;
        l->ult = cel;
    }
    //caso nao seja o primeiro da lista
    else{
        cel->ant = l->ult;
        l->ult->prox = cel;
        l->ult = cel;
    }

    l->tam++;
}

void* retiraLista(Lista* l, void* item){
    
    if(!buscaItemLista(l, item)) return NULL;

    Celula* atual = NULL;
    Celula* ant = NULL;
    void* itemRetirado = NULL;

    atual = l->prim;
    
    for(int i=0; i<l->tam;i++){

        if(atual->item == item){
            itemRetirado = atual->item;

            //se for o primeiro da lista
            if(i==0){
                //verifica se so tem um na lista
                if(l->prim == l->ult){
                    l->prim = NULL;
                    l->ult = NULL;
                }
                else{
                    atual->prox->ant = NULL;
                    l->prim = atual->prox;
                }
                
            }
            //se for o ultimo da lista
            else if(i == (l->tam - 1)){
                atual->ant->prox = NULL;
                l->ult = atual->ant;
            }
            else{
                atual->prox->ant = atual->ant;
                atual->ant->prox = atual->prox;
            }
            
            l->tam--;
            free(atual);

            return itemRetirado;
        }

        ant = atual;
        atual = ant->prox;
    }

    return NULL;
}

int buscaItemLista(Lista* l, void* item){
    Celula* atual = NULL;
    Celula* ant = NULL;

    int encontrado = 0;

    atual = l->prim;

    for(int i=0; i<l->tam; i++){
        
        if(atual->item == item){
            encontrado = 1;
            break;
        }
        ant = atual;
        atual = ant->prox;
    }

    return encontrado;
}

void imprimeLista(Lista* l){
    Celula* ant = NULL;
    Celula* atual = NULL;

    for(int i=0; i<l->tam; i++){
        if(i==0){
            atual = l->prim;
        }
        
        if(atual->tipo == CACHORRO) imprimeCachorro(atual->item);
        else imprimeGato(atual->item);

        //atualiza o anterior e o atual
        ant = atual;
        atual = ant->prox;

    }
}

void liberaLista(Lista* l){
    Celula* prox = NULL;
    Celula* atual = NULL;
    
    for(int i=0; i<l->tam; i++){
        if(i==0){
            atual = l->prim;
        }
        prox = atual->prox;

        free(atual);

        atual = prox;

        if(prox == NULL) break;
    }

    free(l);
}
