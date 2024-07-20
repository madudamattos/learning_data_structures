#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include "palavra.h"

typedef struct hash Hash;

Hash* inicHash(int tamanho);

/*Faz acesso à hash em duas possíveis operações:
1)inserção, caso a palavra não esteja na hash
2)incremento de ocorrência, caso a palavra já esteja na hash*/
Palavra* acessa(Hash* h, char* string);

int contaPalavras(Hash* h);

void imprimeHash(Hash* h);

void liberaHash(Hash* h);

#endif /* HASH_H */