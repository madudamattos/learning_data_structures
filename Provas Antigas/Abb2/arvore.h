#ifndef ARVORE_H
#define ARVORE_H

typedef struct arvore Arv;

char* retornaPalavra(Arv* a);

int retornaFrequencia(Arv* a);

Arv* criaArvore();

Arv* insereArv(Arv* a, char* palavra);

Arv* buscaArv(Arv* a, char* palavra);

void liberaArv(Arv* a);

int contaPalavrasDistintas(Arv* a);

int contaPalavrasTotal(Arv* a);

Arv* maiorFrequenciaArv(Arv* a);

#endif