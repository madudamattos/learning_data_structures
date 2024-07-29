#ifndef hashGen_h
#define hashGen_h

#include <stdio.h>
#include <stdlib.h>

typedef struct hash Hash;

// Função para criar uma tabela hash
Hash* cria_hash(int tam);

// Função para inserir um elemento na tabela hash
void* insere_hash(Hash* h, void* key, void* objeto, int (*fhash)(void*, int htam), int (*cmp)(void*, void*));

// Função para buscar um elemento na tabela hash
void* busca_hash(Hash* h, void* key, int (*fhash)(void*, int htam), int (*cmp)(void*, void*));

// Função para imprimir os elementos da tabela hash
void imprime_hash(Hash* h, void (*imprimeDado)(void*));

// Função para imprimir os elementos da tabela hash em um arquivo
void imprime_hash_arquivo(Hash* h, void (*imprimeDadoArquivo)(void*, FILE*), FILE* arquivo);

// Função para liberar a memória da tabela hash
void libera_hash(Hash* h, void (*liberaDado)(void*));

#endif // !hashGen_h
