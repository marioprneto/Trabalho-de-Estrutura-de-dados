#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    char *arr[20] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi", "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};
    int contador = 0, contadorComp = 0;

    FILE *arquivoSaida;

    size_t tamanho = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i<=tamanho; i++){
        for(int j = 0; j<=tamanho; j++){
            int resultado = strcmp(arr[i], arr[j]);
            contadorComp++;
            if (resultado<0){
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                contador++;
            }
        }
    }

    arquivoSaida = fopen("ResultadoOrdenacao.txt","w");

    fprintf(arquivoSaida, "Número de trocas: %d\nNúmero de comparações: %d\nVetor ordenado:\n",contador,contadorComp);

    for (int k=0; k<tamanho;k++){
        printf("(%d) - %s\n",k+1,arr[k]);
        fprintf(arquivoSaida, "(%d) - %s\n",k+1,arr[k]);
    }

    if(tamanho%2==0){
        printf("Mediana: %s e %s", arr[(tamanho/2) - 1], arr[tamanho/2]);
        fprintf(arquivoSaida, "Mediana: %s e %s", arr[(tamanho/2) - 1], arr[tamanho/2]);
    } else{
        printf("Mediana: %s", arr[(tamanho/2)]);
        fprintf(arquivoSaida, "Mediana: %s", arr[(tamanho/2)]);
    }

    return 0;
}
