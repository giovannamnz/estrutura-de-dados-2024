#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct Nodo {
    int dado;
    struct Nodo* esquerda;
    struct Nodo* direita;
} Nodo;

Nodo* criarNodo(int dado);
Nodo* inserirNodo(Nodo* raiz, int dado);
void percursoEmOrdem(Nodo* raiz);
void percursoPreOrdem(Nodo* raiz);
void percursoPosOrdem(Nodo* raiz);
Nodo* buscarNodo(Nodo* raiz, int dado);
Nodo* encontrarMin(Nodo* raiz);
Nodo* removerNodo(Nodo* raiz, int dado);

#endif 
