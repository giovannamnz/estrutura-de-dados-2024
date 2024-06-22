#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main() {
    Nodo* raiz = NULL;
    raiz = inserirNodo(raiz, 50);
    raiz = inserirNodo(raiz, 30);
    raiz = inserirNodo(raiz, 20);
    raiz = inserirNodo(raiz, 40);
    raiz = inserirNodo(raiz, 70);
    raiz = inserirNodo(raiz, 60);
    raiz = inserirNodo(raiz, 80);

    printf("Percurso em-ordem: ");
    percursoEmOrdem(raiz);
    printf("\n");

    printf("Percurso pré-ordem: ");
    percursoPreOrdem(raiz);
    printf("\n");

    printf("Percurso pós-ordem: ");
    percursoPosOrdem(raiz);
    printf("\n");

    printf("Buscar por 40: %s\n", buscarNodo(raiz, 40) != NULL ? "Encontrado" : "Não Encontrado");
    printf("Buscar por 90: %s\n", buscarNodo(raiz, 90) != NULL ? "Encontrado" : "Não Encontrado");

    raiz = removerNodo(raiz, 20);
    printf("Após remover 20, percurso em-ordem: ");
    percursoEmOrdem(raiz);
    printf("\n");

    raiz = removerNodo(raiz, 30);
    printf("Após remover 30, percurso em-ordem: ");
    percursoEmOrdem(raiz);
    printf("\n");

    raiz = removerNodo(raiz, 50);
    printf("Após remover 50, percurso em-ordem: ");
    percursoEmOrdem(raiz);
    printf("\n");

    return 0;
}
