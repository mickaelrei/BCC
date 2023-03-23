#include <stdio.h>

void main() {
   float suco, prato_principal, sobremesa;

   printf("Digite o valor do suco: ");
   scanf("%f", &suco);

   printf("Digite o valor do prato principal: ");
   scanf("%f", &prato_principal);

   printf("Digite o valor da sobremesa: ");
   scanf("%f", &sobremesa);

   float total = (suco + prato_principal + sobremesa) * 1.1;
   printf("O valor total da refeição, junto com a taxa de serviço é de R$ %.2f\n", total);
}