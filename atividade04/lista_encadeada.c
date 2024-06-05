#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

typedef struct No {
    char valor;
    struct No* proximo_no;
} No;

No* no(char valor, No* proximo_no) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void inserir_no(No* H, No* no) {
    if (H != NULL) {
        if (H->proximo_no == NULL) {
            H->proximo_no = no;
        } else {
            inserir_no(H->proximo_no, no);
        }
    }
}

void imprimir_lista(No* H) {
    while (H != NULL) {
        printf("%c ", H->valor);
        H = H->proximo_no;
    }
}

int quantidade_nos(No* H) {
    int count = 0;
    while (H != NULL) {
        count++;
        H = H->proximo_no;
    }
    return count;
}

No* copiar_lista(No* H) {
    if (H == NULL) {
        return NULL;
    }
    return no(H->valor, copiar_lista(H->proximo_no));
}

void liberar_lista(No* H) {
    while (H != NULL) {
        No* temp = H;
        H = H->proximo_no;
        free(temp);
    }
}

int verificar_existencia(No* H, char valor_busca) {
    while (H != NULL) {
        if (H->valor == valor_busca) {
            return 1;
        }
        H = H->proximo_no;
    }
    return 0;
}

int verificar_ocorrencias(No* H, char valor_busca) {
    int count = 0;
    while (H != NULL) {
        if (H->valor == valor_busca) {
            count++;
        }
        H = H->proximo_no;
    }
    return count;
}

void imprimir_inversa(No* H) {
    if (H != NULL) {
        imprimir_inversa(H->proximo_no);
        printf("%c ", H->valor);
    }
}

void inserir_no_i(No* H, int i, No* no) {
    if (H != NULL && i > 0) {
        if (i == 1) {
            no->proximo_no = H->proximo_no;
            H->proximo_no = no;
        } else {
            inserir_no_i(H->proximo_no, i - 1, no);
        }
    }
}

void remover_no_i(No* H, int i, No* no_ant) {
    if (H != NULL) {
        if (i == 0 && no_ant != NULL) {
            no_ant->proximo_no = H->proximo_no;
            free(H);
        } else {
            remover_no_i(H->proximo_no, i - 1, H);
        }
    }
}