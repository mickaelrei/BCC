/*Desenvolva um programa que obtenha do usuário um
número inteiro de 4 dígitos e exiba a soma dos dígitos do número. Por exemplo, se o usuário
fornecer o número 3141, então seu programa deve exibir o número 9 (3 + 1 + 4 + 1).*/

#include <stdio.h>
#include <math.h>

void main() {
    int n;
    printf("Digite um numero de 4 digitos: ");
    scanf("%d", &n);

    // Número de dígitos de n
    int digits = floor(log10(n)) + 1;
    int sum = 0;

    // Soma os dígitos
    for (int pos = 0; pos < digits; pos++) {
        int digit = (int) ( n / pow(10, digits - pos - 1) ) % 10;
        sum += digit;
    }

    printf("Soma dos digitos de %d = %d\n", n, sum);
}
