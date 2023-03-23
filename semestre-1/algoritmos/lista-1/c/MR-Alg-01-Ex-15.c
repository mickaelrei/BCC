#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void main() {
    float l;
    int n;

    printf("Digite o comprimento do lado do polígono (em cm): ");
    scanf("%f", &l);

    printf("Digite o número de lados do polígono: ");
    scanf("%i", &n);

    float area = ((float)n * powf(l, 2)) / (4 * tanf(PI / (float)n));

    printf("Área do polígono regular de %i lados = %.2f cm²\n", n, area);
}