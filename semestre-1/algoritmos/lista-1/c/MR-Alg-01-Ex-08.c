#include <stdio.h>

void main() {
   int bugigangas, quinquilharias;

   printf("Digite a quantidade de bugigangas: ");
   scanf("%i", &bugigangas);

   printf("Digite a quantidade de quinquilharias: ");
   scanf("%i", &quinquilharias);

   float peso = bugigangas * .075 + quinquilharias * .112;
   printf("Peso total do pedido: %.3f kg\n", peso);
}