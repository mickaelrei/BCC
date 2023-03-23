#include <stdio.h>

void main() {
   float largura, profundidade;

    printf("Largura do terreno (em metros): ");
    scanf("%f", &largura);

    printf("Profundidade do terreno (em metros): ");
    scanf("%f", &profundidade);

    float area = largura * profundidade;
    float hectares = area / 10000;
    printf("Hectares do terreno: %f\n", hectares);
}