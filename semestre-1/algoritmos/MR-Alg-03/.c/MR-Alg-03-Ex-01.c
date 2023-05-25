/*Escreva um programa Python que recebe do usuário um número inteiro. Seu
programa deve então exibir uma mensagem indicando se o número fornecido é par ou ímpar.*/

#include <stdio.h>

void main() {
    int n;
    printf("Numero inteiro: ");
    scanf("%d", &n);

    if (n % 2 == 0)
        printf("%d e par", n);
    else
        printf("%d e impar", n);
}
