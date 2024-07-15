#include "lista.h"
#include <stdio.h>

int main(void) {
  tLista *lista = criaLista();

  lista = insereLista(lista, 1);
  lista = insereLista(lista, 2);
  lista = insereLista(lista, 3);
  lista = insereLista(lista, 4);
  lista = insereLista(lista, 5);
  lista = insereLista(lista, 6);

  imprimeLista(lista);

  lista = retiraLista(lista, 3);
  lista = retiraLista(lista, 5);

  imprimeLista(lista);

  liberaLista(lista);

  return 0;
}