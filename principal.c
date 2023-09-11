#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Nome[100];
    char Telefone[20];
    char Curso[50];
    float Nota1;
    float Nota2;
} Aluno;

int main(){
    FILE *arquivoEntrada;
    FILE *arquivoSaida;

    char linha[1024];
    Aluno aluno;

    arquivoEntrada = fopen("DadosEntrada.csv", "r");
    arquivoSaida = fopen("SituacaoFinal.csv","w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Ocorreu um erro na tentativa de abrir os arquivos.");
        exit(1);
    }

    fgets(linha, sizeof(linha), arquivoEntrada);

    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        char *token = strtok(linha, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(aluno.Nome, token);
        token = strtok(NULL, ",");
        strcpy(aluno.Telefone, token);
        token = strtok(NULL, ",");
        strcpy(aluno.Curso, token);
        token = strtok(NULL, ",");
        sscanf(token, "%f", &aluno.Nota1);
        token = strtok(NULL, ",");
        sscanf(token, "%f", &aluno.Nota2);

        float media = (aluno.Nota1 + aluno.Nota2) / 2.0;

        const char *situacao;
        if (media >= 7.0) {
            situacao = "APROVADO";
        } else {
            situacao = "REPROVADO";
        }

        fprintf(arquivoSaida, "%s, %.2f, %s\n", aluno.Nome, media, situacao);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Arquivo SituacaoFinal.csv criado com sucesso!\n");
    return 0;
}


