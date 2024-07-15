#include "Cachorro.h"

struct cachorro{
    char* nomeCachorro;
    int agressividade;
};

Cachorro* inicCachorro(char* nome, int agressividade){
    Cachorro* dog = (Cachorro*)malloc(sizeof(Cachorro));
    dog->nomeCachorro = strdup(nome);
    dog->agressividade = agressividade;
    return dog;
}

void liberaCachorro(Cachorro* dog){
    free(dog->nomeCachorro);
    free(dog);
}

int retornaNivelAgressividadeCachorro(Cachorro* dog){
    return dog->agressividade;
}

char* retornaNomeCachorro(Cachorro* dog){
    return dog->nomeCachorro;
}

void imprimeCachorro(Cachorro* dog){
    if(dog == NULL){
        printf("CACHORRO NULO\n");
        return;
    }
    printf("%s, ", dog->nomeCachorro);
    if(dog->agressividade == BRAVO) printf("BRAVO\n");
    else if(dog->agressividade == MANSO) printf("MANSO\n");
}

void atribuiNivelAgressividadeCachorro(Cachorro* dog, int agressividadeAtt){
    dog->agressividade = agressividadeAtt;
}