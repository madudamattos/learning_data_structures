/*
    exemplo de utilizacao do quicksort da biblioteca padrao C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

// Função de comparação para strings
int comparaNomes(const void* a, const void* b) {
    const char* nomeA = *(const char**)a;
    const char* nomeB = *(const char**)b;
    return strcmp(nomeA, nomeB);
}

int main(){

    //comparacao de numeros 

    printf("Ordenação de inteiros\n");
    int vet[5] = {3, 5 , 2, 4, 1}; 

    printf("\nantes\n");
    for(int i=0; i<5; i++){
        printf("%d ", vet[i]);
    }

    qsort(vet, 5, sizeof(int), comp);

    printf("\ndepois\n");
    for(int i=0; i<5; i++){
        printf("%d ", vet[i]);
    }

    printf("\nOrdenação de nomes\n");
    const char* nomes[] = {"Carlos", "Ana", "Bruno", "Daniel", "Elena"};

    printf("\nantes\n");
    for (int i = 0; i < 5; i++) {
        printf("%s ", nomes[i]);
    }

    qsort(nomes, 5, sizeof(const char*), comparaNomes);

    printf("\ndepois\n");
    for (int i = 0; i < 5; i++) {
        printf("%s ", nomes[i]);
    }


    return 0;

}