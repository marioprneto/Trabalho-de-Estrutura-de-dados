#include <stdio.h>
#include <stdlib.h>
#include "calculos.c"

int main()
{
    FILE *arquivo = fopen("entradas.txt", "r");

    if (arquivo == NULL)
    {
        printf("Ocorreu um erro ao tentar abrir o arquivo.\n");
        exit(1);
    }

    printf("O resultado da area do poligono eh %.2f",processamento(arquivo));

    return 0;
}
