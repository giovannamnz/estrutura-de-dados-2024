#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

Nodo* criarNodo(int dado) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo) {
        novoNodo->dado = dado;
        novoNodo->esquerda = NULL;
        novoNodo->direita = NULL;
    }
    return novoNodo;
}

Nodo* inserirNodo(Nodo* raiz, int dado) {
    if (raiz == NULL) {
        return criarNodo(dado);
    }

    if (dado < raiz->dado) {
        raiz->esquerda = inserirNodo(raiz->esquerda, dado);
    } else {
        raiz->direita = inserirNodo(raiz->direita, dado);
    }

    return raiz;
}

void percursoEmOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        percursoEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        percursoEmOrdem(raiz->direita);
    }
}


void percursoPreOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        percursoPreOrdem(raiz->esquerda);
        percursoPreOrdem(raiz->direita);
    }
}

void percursoPosOrdem(Nodo* raiz) {
    if (raiz != NULL) {
        percursoPosOrdem(raiz->esquerda);
        percursoPosOrdem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

Nodo* buscarNodo(Nodo* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado) {
        return raiz;
    }

    if (dado < raiz->dado) {
        return buscarNodo(raiz->esquerda, dado);
    } else {
        return buscarNodo(raiz->direita, dado);
    }
}

Nodo* encontrarMin(Nodo* raiz) {
    while (raiz && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

Nodo* removerNodo(Nodo* raiz, int dado) {
    if (raiz == NULL) {
        return raiz;
    }

    if (dado < raiz->dado) {
        raiz->esquerda = removerNodo(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = removerNodo(raiz->direita, dado);
    } else {
        if (raiz->esquerda == NULL) {
            Nodo* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Nodo* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        Nodo* temp = encontrarMin(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = removerNodo(raiz->direita, temp->dado);
    }

    return raiz;
}
