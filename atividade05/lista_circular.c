#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

typedef struct No {
    char valor;
    struct No* proximo_no;
} No;

No* no(char valor, No* proximo_no) {
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void inserir_no(No* H, char valor) {
    if (H != NULL) {
        No* novo_no = no(valor, H);
        if (H->proximo_no == NULL) {
            H->proximo_no = novo_no;
        } else {
            No* tmp = H->proximo_no;
            while (tmp->proximo_no != H) {
                tmp = tmp->proximo_no;
            }
            tmp->proximo_no = novo_no;
        }
    }
}

void imprimir_lista(No* H) {
    if (H != NULL) {
        printf("%c ", H->valor);
        No* tmp = H->proximo_no;
        while (tmp != H && tmp != NULL) {
            printf("%c ", tmp->valor);
            tmp = tmp->proximo_no;
        }
    }
}

void remover_no(No* H, char valor) {
    if (H != NULL) {
        No* tmp_ant = H;
        No* tmp = H->proximo_no;
        while (tmp != H && tmp != NULL) {
            if (tmp->valor == valor) {
                tmp_ant->proximo_no = tmp->proximo_no;
                free(tmp);
                tmp = tmp_ant->proximo_no;
            } else {
                tmp_ant = tmp;
                tmp = tmp->proximo_no;
            }
        }
    }
}