#include "Ponto.h"
#include <stdio.h>
#include <stdlib.h>

float calcularResultado(Ponto *vertices, int qtdVertices){

    float area = 0.0;

    for(int i=0; i<qtdVertices; i++){
        int k = (i+1) % qtdVertices;
        area+=(vertices[i].x * vertices[k].y - vertices[k].x * vertices[i].y);
    }

    area = area/2.0;

    if(area<0){
        area = -area;
    }

    return area;
}

float processamento(FILE *arquivo){
    int numVertices;
    fscanf(arquivo, "%d", &numVertices);

    Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));

    for (int i = 0; i < numVertices; i++)
    {
        fscanf(arquivo, "%f %f", &vertices[i].x, &vertices[i].y);
    }

    fclose(arquivo);

    float area = calcularResultado(vertices, numVertices);

    return area;
}
