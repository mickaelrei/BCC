/*Dado um número de três algarismos N = CDU (onde C é o
algarismo das centenas, D é o algarismo das dezenas e U o algarismo das unidades) Faça um
programa Python que receba do usuário o número inteiro N, e imprima separadamente a
centena, a dezena e a unidade.*/

#include <stdio.h>

void main() {
    int n;
    printf("Digite um numero de 3 algarismos: ");
    scanf("%d", &n);

    int centena = n / 100;
    int dezena = n / 10 % 10;
    int unidade = n % 10;

    printf("Centena: %d\nDezena: %d\nUnidade: %d\n", centena, dezena, unidade);
}
