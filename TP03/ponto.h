#define Ponto_h

typedef struct{
    float x;
    float y;
} Ponto;

float calcularArea(Ponto *vertices, int numVertices);
