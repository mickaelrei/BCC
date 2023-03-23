#include <stdio.h>
#include <math.h>

void main() {
   int a, b;

   printf("Valor de a: ");
   scanf("%i", &a);

    printf("Valor de b: ");
   scanf("%i", &b);

   printf("\na + b = %i\n", a + b);
   printf("a - b = %i\n", a - b);
   printf("a * b = %i\n", a * b);
   printf("a / b = %f\n", (float)(a) / (float)b);
   printf("log10 de a = %f\n", log10((double)a));
   printf("a^b = %f\n", pow(a, b));
}