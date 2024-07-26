#ifndef ARV_BUSCA_H
#define ARV_BUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Abb;


// Cria uma árvore vazia
Abb *cria_arv(void);

void* retornaArvConteudo(Abb* a);

// Imprime a árvore usando a função de callback cb para processar os elementos
void imprime_arv(Abb *arv, void (*cb)(void *));

// Insere um elemento na árvore, usando a função de comparação comp
Abb *insere_arv(Abb *arv, void *conteudo, int (*comp)(void *, void *));

// Busca um elemento na árvore, usando a função de comparação comp
Abb *busca_arv(Abb *arv, int (*comp)(void *, void *), void *conteudo);

// Remove um elemento da árvore, usando a função de comparação comp
Abb *retira_arv(Abb *arv, int (*comp)(void *, void *), void *conteudo);

// Libera a memória ocupada pela árvore
void libera_arv(Abb *arv);


#endif