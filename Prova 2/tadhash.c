/*

PROVA 2 DA DISCIPLINA DE ESTRUTURA DE DADOS I
ALUNA: MARIA EDUARDA NOIA MATTOS DE AZEVEDO
DATA: 29/07/2024

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadpais.h"
#include "tadhash.h"
#include "tadlista.h"


struct hash{
    int tam;
    Lista** tabela;
};


// aloca memoria pra tabela e inicia todas as posicoes com NULL
Hash* criaHash(int tam){
    Hash* h = malloc(sizeof(Hash));
    h->tam = tam;

    h->tabela = malloc(tam*sizeof(Lista*));

    for(int i=0; i<h->tam; i++){
        h->tabela[i] = criaLista();
    }

    return h;
}

Pais* buscaHash(Hash* h, char* nomePais){
    int indice = hashPais(h, nomePais);

    // se o endereco do indice estiver vazio retorna NULL
    if(h->tabela[indice] == NULL) return NULL;

    // se nao estiver vazio, busca na lista de paises 
    Lista* l = buscaLista(h->tabela[indice], nomePais);    

    if(l != NULL) return retornaPais(l);

    return NULL;
}

Pais* insereHash(Hash* h, Pais* p){
    if(!h || !p){
        printf("tabela hash ou pais inexistente, nao foi possivel realizar a insercao!\n");
        return NULL;
    } 

    int indice = hashPais(h, retornaNome(p));

    h->tabela[indice] = insereLista(h->tabela[indice], p);

    return p;
}

// funcao de hash que soma os valor ASCII dos caracteres e retorna um indice correspondente
int hashPais(Hash* h, char* nomePais){
    int soma = 0;
    int indice;

    for(int i=0; i<3; i++){
        soma += (int)nomePais[i];
    }

    indice = soma%(h->tam);

    return indice;
}

void imprimeHash(Hash* h){
    for(int i=0; i< h->tam; i++){
        printf("Hash[%d]:\n", i);
        imprimeLista(h->tabela[i]);
        printf("\n");
    }
}

void liberaHash(Hash* h){
    for(int i=0; i< h->tam; i++){
        liberaLista(h->tabela[i]);
    }
    free(h->tabela);
    free(h);
}


void organizaPaises(Hash* thash, Pais** paises, int total){
    int j=0;

    for(int i=0; i< thash->tam; i++){
        if(thash->tabela[i] != NULL){
            Lista* p = thash->tabela[i];
            while(p != NULL){
                paises[j] = retornaPais(p);
                // atualiza indice do vetor de paises
                j++;
                p = retornaProx(p);
            }
        }
    }

}