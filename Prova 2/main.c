/*

PROVA 2 DA DISCIPLINA DE ESTRUTURA DE DADOS I
ALUNA: MARIA EDUARDA NOIA MATTOS DE AZEVEDO
DATA: 29/07/2024

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadhash.h"
#include "tadpais.h"
#include "tadlista.h"

#define HASH_TAM 17

int main(int argv, char* argc[]){

    FILE* entrada = fopen("entrada.txt", "r");

    char nomePais[4];
    int ouro, prata, bronze, total;

    Hash* thash = criaHash(HASH_TAM);

    int totalPaises = 0;

    while(fscanf(entrada, "%s %d %d %d %d%*c", nomePais, &ouro, &prata, &bronze, &total) == 5){
        // busca o pais na tabela pra ver se ele ja existe
        Pais* p = buscaHash(thash, nomePais);

        if(!p){
            // se nao existir insere na tabela
            p = criaPais(nomePais, ouro, prata, bronze, total);
            insereHash(thash, p);
            totalPaises++;
        } else {
            // se ele ja existir, incrementa medalhas
            atualizaMedalhas(p, ouro, prata, bronze, total);
        }
    
    }

    // segunda parte

    Pais** paises = malloc(totalPaises * sizeof(Pais*));

    // insere paises no vetor 
    organizaPaises(thash, paises, totalPaises);

    qsort(paises, totalPaises, sizeof(Pais*), comparaPaises);

    FILE* saida = fopen("saida.txt", "w");

    if(!saida){
        printf("nao foi possivel gerar arquivo de saida");
        return 0;
    }

    imprimePaisesArquivo(paises, totalPaises, saida);

    free(paises);
    fclose(saida);
    fclose(entrada);
    liberaHash(thash);

    return 0;
}