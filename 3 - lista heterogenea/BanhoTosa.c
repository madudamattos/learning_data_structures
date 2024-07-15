//
//  BanhoTosa.h
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#include "BanhoTosa.h"
#include "Lista.h"
#include <string.h>
#include <stdlib.h>

#define BRAVO 0
#define MANSO 1

#define CACHORRO 2
#define GATO 3

struct banhotosa{
    char* nomeLoja;
    Lista* lAgressivos;
    Lista* lMansos;
};

BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa* loja = (BanhoTosa*) malloc(sizeof(BanhoTosa));
    loja->nomeLoja = strdup(nome);
    loja->lAgressivos = criaLista();
    loja->lMansos = criaLista();
    return loja;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){

    if(retornaNivelAgressividadeCachorro(dog) == BRAVO){
        insereLista(loja->lAgressivos, CACHORRO, dog);
    }
    else if(retornaNivelAgressividadeCachorro(dog) == MANSO){
        insereLista(loja->lMansos, CACHORRO, dog);
    }
}

void cadastraGato(BanhoTosa* loja, Gato* cat){
    if(loja == NULL || cat == NULL) return;
    
    if(retornaNivelAgressividadeGato(cat) == BRAVO){
        insereLista(loja->lAgressivos, GATO, cat);
    }
    else if(retornaNivelAgressividadeGato(cat) == MANSO){
        insereLista(loja->lMansos, GATO, cat);
    }
}

/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){

    if(buscaItemLista(loja->lAgressivos, cat)){
        if(retornaNivelAgressividadeGato(cat) == MANSO){
            retiraLista(loja->lAgressivos, cat);
            insereLista(loja->lMansos, GATO, cat);
        }
    }
    if(buscaItemLista(loja->lMansos, cat)){
        if(retornaNivelAgressividadeGato(cat) == BRAVO){
            retiraLista(loja->lMansos, cat);
            insereLista(loja->lAgressivos, GATO, cat);
        }
    }

}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
    if(buscaItemLista(loja->lAgressivos, dog)){
        if(retornaNivelAgressividadeCachorro(dog) == MANSO){
            retiraLista(loja->lAgressivos, dog);
            insereLista(loja->lMansos, CACHORRO, dog);
        }
    }
    if(buscaItemLista(loja->lMansos, dog)){
        if(retornaNivelAgressividadeCachorro(dog) == BRAVO){
            retiraLista(loja->lMansos, dog);
            insereLista(loja->lAgressivos, CACHORRO, dog);
        }
    }
}


void imprimeBanhoTosa(BanhoTosa* loja){
    printf("%s\n\n", loja->nomeLoja);
    printf("Lista de animais agressivos:\n");
    imprimeLista(loja->lAgressivos);
    printf("\n");
    printf("Lista de animais mansos:\n");
    imprimeLista(loja->lMansos);
    printf("\n");
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja);


void liberaBanhoTosa(BanhoTosa* loja){
    liberaLista(loja->lAgressivos);
    liberaLista(loja->lMansos);
    free(loja);
}
