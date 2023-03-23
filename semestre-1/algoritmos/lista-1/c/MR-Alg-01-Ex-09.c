#include <stdio.h>
#include <math.h>

void main() {
   float inicial;

   printf("Digite o valor inicial do investimento: ");
   scanf("%f", &inicial);

   float taxa = .12;
   int anos = 3;
   for (int i = 1; i <= anos; i++) {
        double valor = inicial * pow(1 + taxa, i);
        printf("Valor do investimento após %i anos: R$ %.2f\n", i, valor);
   }
}