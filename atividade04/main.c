#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main() {
    No* lista = no('A', no('B', no('C', no('D', no('E', no('F', NULL))))));
    No* copia_lista = copiar_lista(lista);

    printf("Original:\n");
    imprimir_lista(lista);
    printf("\nCopia:\n");
    imprimir_lista(copia_lista);

    lista->proximo_no->valor = 'E';
    copia_lista->valor = 'U';

    printf("\nModificado:\n");
    imprimir_lista(lista);
    printf("\nCopia apos alteracao:\n");
    imprimir_lista(copia_lista);

    liberar_lista(copia_lista);

    printf("\nQuantidade de nos: %d", quantidade_nos(lista));
    printf("\n'E' existe na lista? %s", verificar_existencia(lista, 'E') ? "Sim" : "Não");
    printf("\n'E' ocorre quantas vezes na lista? %d\n", verificar_ocorrencias(lista, 'E'));

    imprimir_inversa(lista);

    inserir_no_i(lista, 2, no('J', NULL));
    printf("\nApos insercao:\n");
    imprimir_lista(lista);

    remover_no_i(lista, 6, NULL);
    printf("\nApos remocao:\n");
    imprimir_lista(lista);

    return 0;
}
