#include "lista.h"
#include "produto.h"
#include <stdio.h>

int main(void) {
  tLista *l = criaLista();

  printf("TESTADOR DE LISTA\n\n");

  printf("- Criação dos produtos iniciais\n");

  tProduto *p1 = criaProduto(12345, 10.0, "batata");
  tProduto *p2 = criaProduto(23135, 20.0, "arroz");
  tProduto *p3 = criaProduto(54231, 15.0, "feijao");
  tProduto *p4 = criaProduto(23154, 5.0, "macarrao");
  tProduto *p5 = criaProduto(43513, 25.0, "frango");

  printf("- Inserção dos produtos na lista\n");
  insereLista(p1, l);
  insereLista(p2, l);
  insereLista(p3, l);
  insereLista(p4, l);
  insereLista(p5, l);

  printf("- Impressão da lista inicial\n");
  imprimeLista(l);

  printf("- Retirada de produto por nome - 'macarrao'\n");
  retiraListaPorNome("macarrao", l);
  imprimeLista(l);

  printf("- Retirada de produto por ID - 43513\n");
  retiraListaPorID(43513, l);
  imprimeLista(l);

  printf("- Retirada de produto por ID - 12345\n");
  retiraListaPorID(12345, l);
  imprimeLista(l);

  printf("- Liberação de lista\n");
  liberaLista(l);

  printf("- Liberando produtos\n");
  destroiProduto(p1);
  destroiProduto(p2);
  destroiProduto(p3);
  destroiProduto(p4);
  destroiProduto(p5);

  printf("\nFINALIZANDO TESTADOR\n");
  printf("----------------------------------------------------\n\n");
  printf("OBRIGADO POR USAR O PROGRAMA!\n");

  return 0;
}