#include <stdio.h>

void main() {
   int n;

   printf("Digite um número inteiro positivo: ");
   scanf("%i", &n);

    int soma = n * (n + 1) / 2;
    printf("A soma de todos os números inteiros de 1 a %i é igual a %i\n", n, soma);
}