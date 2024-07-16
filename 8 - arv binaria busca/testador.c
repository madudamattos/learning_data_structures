#include <stdio.h>
#include "arvore_busca.h"

int main() {
    // Cria alguns alunos
    Aluno* aluno1 = criaAluno("Alice", 1);
    Aluno* aluno2 = criaAluno("Bob", 2);
    Aluno* aluno3 = criaAluno("Charlie", 3);
    Aluno* aluno4 = criaAluno("David", 4);
    Aluno* aluno5 = criaAluno("Eve", 5);
    Aluno* aluno6 = criaAluno("Frank", 6);
    Aluno* aluno7 = criaAluno("Grace", 7);

    // Cria uma árvore
    Abb* arvore = cria_arv();

    // Insere alunos na árvore
    arvore = insere_arv(arvore, aluno4); // Root
    arvore = insere_arv(arvore, aluno2);
    arvore = insere_arv(arvore, aluno6);
    arvore = insere_arv(arvore, aluno1);
    arvore = insere_arv(arvore, aluno3);
    arvore = insere_arv(arvore, aluno5);
    arvore = insere_arv(arvore, aluno7);

    // Imprime a árvore
    printf("Árvore após inserções:\n");
    imprime_arv(arvore);

    // Testa remoção de uma folha
    printf("\nRemovendo uma folha (Aluno com matrícula 1):\n");
    arvore = retira_arv(arvore, 1);
    imprime_arv(arvore);

    // Testa remoção de um nó com um filho
    printf("\nRemovendo um nó com um filho (Aluno com matrícula 6):\n");
    arvore = retira_arv(arvore, 6);
    imprime_arv(arvore);

    // Testa remoção de um nó com dois filhos
    printf("\nRemovendo um nó com dois filhos (Aluno com matrícula 2):\n");
    arvore = retira_arv(arvore, 2);
    imprime_arv(arvore);

    // Testa remoção da raiz
    printf("\nRemovendo a raiz (Aluno com matrícula 4):\n");
    arvore = retira_arv(arvore, 4);
    imprime_arv(arvore);

    // Libera a árvore
    libera_arv(arvore);

    // Libera os alunos (caso não tenham sido liberados pela árvore)
    // liberaALuno(aluno1);
    // liberaALuno(aluno2);
    // liberaALuno(aluno3);
    // liberaALuno(aluno4);
    // liberaALuno(aluno5);
    // liberaALuno(aluno6);
    // liberaALuno(aluno7);

    return 0;
}
