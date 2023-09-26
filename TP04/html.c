#include <stdio.h>

int main(){
    FILE *htmlEntrada, *textoSaida;
    char caractere;
    int isTag = 0;

    htmlEntrada = fopen("entrada.txt","r");
    textoSaida = fopen("saida.txt","w");

    if (htmlEntrada == NULL || textoSaida == NULL) {
        printf("Ocorreu um erro ao abrir o arquivo.\n");
        exit(1);
    }

    while ((caractere = fgetc(htmlEntrada)) != EOF) {
        if (caractere == '<') {
            isTag = 1;
            continue;
        }
        if (caractere == '>') {
            isTag = 0;
            continue;
        }
        if (!isTag) {
            fputc(caractere, textoSaida);
        }
    }

    fclose(htmlEntrada);
    fclose(textoSaida);

    printf("As tags HTML foram removidas com sucesso!\n");

    return 0;
}
