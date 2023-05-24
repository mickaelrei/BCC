#include <stdio.h>

void main() {
   float b, h;

   printf("Digite a base do triângulo (em cm): ");
   scanf("%f", &b);

   printf("Digite a altura do triângulo (em cm): ");
   scanf("%f", &h);

   float area = b * h / 2;

   printf("Área do triângulo = %.2f cm²\n", area);
}