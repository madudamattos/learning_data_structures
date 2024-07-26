#include "aluno.h"
#include "hash.h"
#include "lista.h"
#include <stdio.h>

void imprimeHashAluno(Hash* thash, void imprimeAluno(Aluno*));

void *hash_insere_aluno(Hash *thash, int* matricula, Aluno *aluno, int (*hash)(int *), int (*comp)(void *, void *));

int comparaMatVoid(void* aluno, void* mat);

// Função de hash que soma os últimos três dígitos da matrícula
int hashMatricula(int* matricula);

int main(void) {

  Hash *thash = cria(20);

  Aluno *guilherme = iniciaAluno(2019123, "Guilherme");
  Aluno *bruno = iniciaAluno(2019321, "Bruno");
  Aluno *joana = iniciaAluno(2019213, "Joana");
  Aluno *mirelly = iniciaAluno(2019231, "Mirelly");
  Aluno *luiza = iniciaAluno(2019456, "Luiza");
  Aluno *gabriel = iniciaAluno(2019444, "Gabriel");

  hash_insere_aluno(thash, retornaMat(guilherme), guilherme, hashMatricula, comparaMatVoid);
  hash_insere_aluno(thash, retornaMat(bruno), bruno, hashMatricula, comparaMatVoid);
  hash_insere_aluno(thash, retornaMat(joana), joana, hashMatricula, comparaMatVoid);
  hash_insere_aluno(thash, retornaMat(mirelly), mirelly, hashMatricula, comparaMatVoid);
  hash_insere_aluno(thash, retornaMat(luiza), luiza, hashMatricula, comparaMatVoid);
  hash_insere_aluno(thash, retornaMat(gabriel), gabriel, hashMatricula, comparaMatVoid);

  imprimeHashAluno(thash, imprimeAluno);

  libera(thash);

  destroiAluno(guilherme);
  destroiAluno(bruno);
  destroiAluno(joana);
  destroiAluno(mirelly);
  destroiAluno(luiza);
  destroiAluno(gabriel);

  return 0;
}

void *hash_insere_aluno(Hash *thash, int* matricula, Aluno *aluno, int (*hash)(int *), int (*comp)(void *, void *)) {
  hash_insere(thash, (void*)matricula, aluno, (int (*)(void*))hash, comp);
}


int comparaMatVoid(void* aluno, void* mat){
  return comparacaoMat((Aluno*) aluno, (int *)mat);
}

// Função de hash que soma os últimos três dígitos da matrícula
int hashMatricula(int* matricula) {
  int ult3dig = *matricula % 1000; // Obtém os últimos três dígitos
  int soma = (ult3dig / 100) + ((ult3dig / 10) % 10) + (ult3dig % 10);
  return soma;
}

void imprimeHashAluno(Hash* thash, void imprimeAluno(Aluno*)){
  imprime(thash, (void (*)(void*))imprimeAluno);
}