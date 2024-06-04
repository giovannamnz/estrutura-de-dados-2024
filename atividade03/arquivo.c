#include <stdio.h>
#include <stdlib.h>
 
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
 
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }
 
    FILE *arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        perror("(!) Erro ao abrir o arquivo de entrada");
        return 1;
    }
 
    int *numeros = NULL;
    int tamanho = 0, valor, resultado;
 
    while ((resultado = fscanf(arquivo, "%d", &valor)) != EOF) {
        if (resultado == 1) {
            int *temp = realloc(numeros, (tamanho + 1) * sizeof(int));
            if (!temp) {
                perror("(!) Erro ao alocacar memoria");
                free(numeros);
                fclose(arquivo);
                return 1;
            }
            numeros = temp;
            numeros[tamanho++] = valor;
        }
    }
    fclose(arquivo);
 
    qsort(numeros, tamanho, sizeof(int), comparar);
 
    arquivo = fopen("saida.txt", "w");
    if (!arquivo) {
        perror("(!) Erro ao abrir o arquivo de saida");
        free(numeros);
        return 1;
    }
 
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", numeros[i]);
    }
    fclose(arquivo);
    free(numeros);
 
    printf("Processo concluido. Verifique o arquivo 'saida.txt'.\n");
    return 0;
}