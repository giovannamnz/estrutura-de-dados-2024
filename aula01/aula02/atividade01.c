#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void bubbleSort(int *array, int tamanho) //usei o bubbleShort que geralmente não daria certo com algoritmos grandes, mas nesse deu :))
{
    for (int posicao = 0; posicao < tamanho - 1; ++posicao)
    {
        for (int i = 0; i < tamanho - posicao - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("(!) Erro: Nenhum numero foi detectado.\n");
        return 1;
    }

    int numeros[argc - 1];
    int soma = 0, min = INT_MAX, max = INT_MIN;

    for (int i = 1; i < argc; i++)
    {
        numeros[i - 1] = atoi(argv[i]);
        soma += numeros[i - 1];
        if (numeros[i - 1] < min)
            min = numeros[i - 1];
        if (numeros[i - 1] > max)
            max = numeros[i - 1];
    }

    bubbleSort(numeros, argc - 1);

    printf("Quantidade de numeros recebidos: %d\n", argc - 1);
    printf("Valor medio dos numeros: %.2f\n", soma / (float)(argc - 1));
    printf("Menor numero: %d\n", min);
    printf("Maior numero: %d\n", max);
    printf("Lista de numeros em ordem crescente: ");
    for (int i = 0; i < argc - 1; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
