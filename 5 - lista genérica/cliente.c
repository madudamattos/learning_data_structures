#include <stdio.h>
#include "listaAlunos.h"

int main(int argc, char const *argv[]) {

    //Cria lista genérica para teste
    ListaGen* lista = criaLista();

    //Criando alguns alunos para teste
    Aluno* guilherme = IniciaAluno (2019123, "Guilherme", 10.0);
    Aluno* bruno = IniciaAluno (2019321, "Bruno", 8.0);
    Aluno* joana = IniciaAluno (2019213, "Joana", 7.5);
    Aluno* mirelly = IniciaAluno (2019231, "Mirelly", 7.5);
    Aluno* luiza = IniciaAluno (2019456, "Luiza", 7.5);
    Aluno* gabriel = IniciaAluno (2019444, "Gabriel", 8.0);

    //Inserindo alunos na lista 
    lista = insereLista(lista, guilherme);
    lista = insereLista(lista, bruno);
    lista = insereLista(lista, luiza);
    lista = insereLista(lista, gabriel);
    lista = insereLista(lista, joana);
    lista = insereLista(lista, mirelly);

    //Imprime lista com todos os alunos
    printf("Imprimindo lista genérica:\n");
    imprimeListaAlunos(lista);
    printf("\n");

    //Retira joana
    lista = retiraAluno(lista, 2019213);
    
    //Imprime lista sem Joana
    printf("Imprimindo lista genérica:\n");
    imprimeListaAlunos(lista);
    printf("\n");

    //Verifica se Luiza está na lista
    int i = pertenceAluno(lista, 2019456);
    if (i == 0)
        printf("Luiza está na lista!\n");
    else
        printf("Luiza NÃO está na lista!\n");

    //Retorna a media
    printf("A media da Turma é: %.2f\n", mediaTurma(lista)); 

    //Retira todos os alunos da lista
    lista = retiraAluno(lista, 2019123); //guilherme
    lista = retiraAluno(lista, 2019321); //bruno
    lista = retiraAluno(lista, 2019231); //mirelly
    lista = retiraAluno(lista, 2019456); //luiza
    lista = retiraAluno(lista, 2019444); //gabriel

    //Verifica se Gabriel está na lista
    i = pertenceAluno(lista, 2019444);
    if (i == 0)
        printf("Gabriel está na lista!\n");
    else
        printf("Gabriel NÃO está na lista!\n");

    //Imprime lista vazia
    printf("Imprimindo lista genérica:\n");
    imprimeListaAlunos(lista);
    printf("\n");

    //Libera memória alocada
    liberaLista(lista);
    destroiAluno(guilherme);
    destroiAluno(bruno);
    destroiAluno(joana);
    destroiAluno(mirelly);
    destroiAluno(luiza);
    destroiAluno(gabriel);

    return 0;
}