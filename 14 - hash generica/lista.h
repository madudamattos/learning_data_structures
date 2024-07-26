#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;

// cria lista vazia
Lista *cria_lista();

// insere lista no inicio
Lista *insereLista(Lista *l, void *info);

// retira lista por chave e retorna o elemento retirado
// a funcao de callback tem que retornar 0 quando os elementos forem iguais
Lista *retiraLista(Lista *l, int (*cb)(void *, void *), void *chave);

// retorna um ponteiro para o objeto encontrado, caso contrario retorna NULL
// a funcao de callback tem que retornar 0 quando os elementos forem iguais
Lista *buscaNaLista(Lista *l, int (*cb)(void *, void *), void *chave);

void imprimeLista(Lista *l, void (*cb)(void *));

// libera lista mas nao libera os itens, responsabilidade do cliente
void liberaLista(Lista *l);