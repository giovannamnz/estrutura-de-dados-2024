#include <stdio.h>
#include <stdlib.h>

// regressao linear

typedef struct {
    int x;
    float y;
} Ponto;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s dados.csv\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    int num_registros = 0;
    while (fscanf(arquivo, "%*d,%*f\n") != EOF) {
        num_registros++;
    }

    rewind(arquivo);

    Ponto *pontos = malloc(num_registros * sizeof(*pontos));
    if (!pontos) {
        perror("Erro ao alocar memoria");
        fclose(arquivo);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_registros && fscanf(arquivo, "%d,%f", &pontos[i].x, &pontos[i].y) == 2; i++);

    float media_x = 0, media_y = 0, soma_numerador = 0, soma_denominador = 0;

    for (int i = 0; i < num_registros; i++) {
        media_x += pontos[i].x;
        media_y += pontos[i].y;
        soma_numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        soma_denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }

    media_x /= num_registros;
    media_y /= num_registros;

    float inclinacao = soma_numerador / soma_denominador;
    float intercepcao = media_y - inclinacao * media_x;

    printf("Equacao da reta: y = %.2fx + %.2f\n", inclinacao, intercepcao);

    free(pontos);
    fclose(arquivo);

    return EXIT_SUCCESS;
}
