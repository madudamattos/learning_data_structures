#ifndef LISTAALUNO_H_
#define LISTAALUNO_H_

#include <stdio.h>
#include "aluno.h"
#include "listagen.h"

ListaGen* retiraAluno(ListaGen* lista, int matricula);

int pertenceAluno(ListaGen* lista, int matricula);

void imprimeListaAlunos(ListaGen* lista);

float mediaTurma(ListaGen* lista);

#endif /* LISTAALUNO_H_ */