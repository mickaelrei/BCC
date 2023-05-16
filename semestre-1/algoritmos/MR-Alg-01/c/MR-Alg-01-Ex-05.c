#include <stdio.h>

void main() {
   int tipo1, tipo2;

   printf("Vasilhames de 1 litro ou menos: ");
   scanf("%i", &tipo1);

   printf("Vasilhames de mais de 1 litro: ");
   scanf("%i", &tipo2);

   float credito = tipo1 * .10 + tipo2 * .25;
   printf("Crédito referente ao retorno dos vasilhames: R$ %.2f\n", credito);
}