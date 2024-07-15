#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Questão 2.1
void calc_esfera(float r, float *area, float *volume);
void esfera();

// Questão 2.2
int raizes(float a, float b, float c, float *x1, float *x2);

void calc_raizes();

// Questão 2.3
int pares(int n, int *vet);

void calc_pares();

// Questão 2.4
void inverte(int n, int *vet);

void realiza_inversao();

// Questão 2.5
double avalia(double *poli, int grau, double x);

double realiza_avaliacao();

//------
void imprimeTabela();

// MAIN
int main(void) {

  int opcao = 1;

  while (1) {
    imprimeTabela();
    printf("Digite o número da operação que deseja realizar:");
    scanf("%d", &opcao);
    if (opcao == 6)
      break;

    switch (opcao) {
    case 1:
      esfera();
      break;
    case 2:
      calc_raizes();
      break;
    case 3:
      calc_pares();
      break;
    case 4:
      realiza_inversao();
      break;
    case 5:
      realiza_avaliacao();
      break;
    default:
      printf("Opção inválida");
      break;
    }
  }

  printf("Obrigado por utilizar o programa! :)\n");
  return 0;
}

void imprimeTabela() {
  printf("\n-------Tabela de operações disponíveis----");
  printf(
      "\n\t1 - Calculo de área e volume de esfera\n\t2 - Calculo de "
      "raízes\n\t3 - Contador de números pares em um vetor\n\t4 - Inversão de vetor\n\t5 - Avaliação"
      "de polinômio\n\t6 - Sair\n");
  printf("------------------------------------------\n");
}

// Questão 2.1
void esfera() {
  float r = 1;
  float *area = (float *)malloc(sizeof(float));
  float *volume = (float *)malloc(sizeof(float));

  printf("Cálculo da área e do volume de uma esfera\n");
  printf("Digite o valor do raio: ");
  scanf("%f", &r);

  calc_esfera(r, area, volume);

  printf("Área: %.2f\n", *area);
  printf("Volume: %.2f\n", *volume);
}

void calc_esfera(float r, float *area, float *volume) {
  *area = 4 * M_PI * r * r;
  *volume = 4 * M_PI * r * r * r / 3;
}

// Questão 2.2
void calc_raizes() {
  float a = 0;
  float b = 0;
  float c = 0;
  float *x1 = (float *)calloc(1, sizeof(float));
  float *x2 = (float *)calloc(1, sizeof(float));

  printf("Cálculo das raízes de uma equação do segundo grau de forma ax² + bx "
         "+ c = 0\n");
  printf("Digite o valor de a: ");
  scanf("%f", &a);
  printf("Digite o valor de b: ");
  scanf("%f", &b);
  printf("Digite o valor de c: ");
  scanf("%f", &c);

  int retorno = raizes(a, b, c, x1, x2);

  if (retorno == -1) {
    printf("Essa equação não possui raízes reais\n");
  } else if (retorno == 0) {
    printf("Essa equação possui uma raiz real\n");
    printf("x1: %.4f\n", *x1);
  } else if (retorno == 1) {
    printf("Essa equação possui duas raízes reais\n");
    printf("x1: %.4f\n", *x1);
    printf("x2: %.4f\n", *x2);
  }
}

int raizes(float a, float b, float c, float *x1, float *x2) {

  float delta = b * b - 4 * a * c;
  if (delta < 0) {
    return -1;
  } else if (delta == 0) {
    *x1 = -b / (2 * a);
    return 0;
  } else {
    *x1 = -b + sqrt(delta) / (2 * a);
    *x2 = -b - sqrt(delta) / (2 * a);
  }
  return 1;
}

// Questão 2.3
int pares(int n, int *vet) {

  int par = 0;

  for (int i = 0; i < n; i++) {
    if (vet[i] % 2 == 0) {
      par++;
    }
  }

  return par;
}

void calc_pares() {
  int n;

  printf("Calculo da quantidade de números pares em um vetor\n");
  printf("Digite o tamanho do vetor:");
  scanf("%d", &n);

  int *vet = calloc(n, sizeof(int));

  printf("Digite os valores do vetor:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  printf("Existem %d números pares no vetor\n", pares(n, vet));
}

// Questão 2.4
void inverte(int n, int *vet) {
  int *inv = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    inv[i] = vet[n - i - 1];
  }

  printf("O vetor invertido é:");

  for (int i = 0; i < n; i++) {
    printf(" %d", inv[i]);
  }

  printf("\n");
}

void realiza_inversao() {
  int n;
  printf("Inversão de vetor\n");
  printf("Digite o tamanho do vetor:");
  scanf("%d", &n);

  int *vet = calloc(n, sizeof(int));

  printf("Digita os valores do vetor:\n");

  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }

  inverte(n, vet);
}

// Questão 2.5
double avalia(double *poli, int grau, double x) {
  double resultado = 0;

  for (int i = 0; i <= grau; i++) {
    resultado += poli[i] * pow(x, i);
  }

  return resultado;
}

double realiza_avaliacao() {
  int grau;
  double x;

  printf("Avaliação de polinômios de forma a + bx¹ + cx² + ... mx^n\n");
  printf("Digite o grau do polinômio: ");
  scanf("%d", &grau);
  double *poli = (double *)calloc(grau + 1, sizeof(double));

  printf("Digite os coeficientes do polinômio:\n");

  for (int i = 0; i <= grau; i++) {
    scanf("%lf", &poli[i]);
  }

  printf("Digite o valor de x: ");
  scanf("%lf", &x);

  printf("O valor do polinômio é: %.2lf\n", avalia(poli, grau, x));
}