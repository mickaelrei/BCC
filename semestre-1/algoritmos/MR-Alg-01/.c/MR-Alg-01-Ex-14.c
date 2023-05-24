#include <stdio.h>
#include <math.h>

void main() {
    float l1, l2, l3;

    printf("Programa para calcular a área de um triângulo, baseado no comprimento dos lados.\n");
    printf("Lado 1 (em cm): ");
    scanf("%f", &l1);

    printf("Lado 2 (em cm): ");
    scanf("%f", &l2);

    printf("Lado 3 (em cm): ");
    scanf("%f", &l3);

    float l = (l1 + l2 + l3) / 2;
    float area = powf(l * (l - l1) * (l - l2) * (l - l3), .5);

    printf("\nÁrea do triângulo: %.2f cm²\n", area);
}