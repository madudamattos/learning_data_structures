#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore Arv;

Arv* cria_arv();

Arv* insere_arv(Arv* a, char* nome);

void imprime_arv(Arv* a, int nAula);

void imprime_arv_arquivo(Arv* a, int nAula, FILE* arquivo);

Arv* busca_arv(Arv* a, char* nome);

char* retornaNome(Arv* a);

int retornaPeso(Arv* a);

int retornaPresenca(Arv* a);

void incrementaPresenca(Arv* a);

int tamanhoPalavra(char* p);

int comparaNomes(char* nome1, char* nome2);