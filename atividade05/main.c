#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    No* H = inicializar_lista('A'); 
    
    inserir_no(H, 'B');
    inserir_no(H, 'C');
    imprimir_lista(H); // Imprime 'A', 'B', 'C'
    printf("\n");

    remover_no(&H, 'B'); 
    imprimir_lista(H); 
    printf("\n");

    remover_no(&H, 'C');
    imprimir_lista(H); 
    printf("\n");

    liberar_lista(&H); 
    return 0;
}