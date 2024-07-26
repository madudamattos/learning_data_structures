#include <stdio.h>
#include <stdlib.h>

typedef struct hash Hash;

Hash *cria(int tam);

void *busca(Hash *hash, void *key, int (*fhash)(void *),
            int (*comp)(void *, void *));

void *hash_insere(Hash *thash, void* key, void *objeto, int (*hash)(void *), int (*comp)(void *, void *));

void libera(Hash *table);

void imprime(Hash *thash, void (*cb)(void *));