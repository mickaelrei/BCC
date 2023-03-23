#include <stdio.h>

void main() {
    float largura, profundidade;

    printf("Largura da sala (em metros): ");
    scanf("%f", &largura);

    printf("Profundidade da sala (em metros): ");
    scanf("%f", &profundidade);

    float area = largura * profundidade;
    printf("Área da sala: %fm²\n", area);
}