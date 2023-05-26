/*Escreva um programa Python que calcula a média aritmética de um
conjunto de valores fornecidos pelo usuário. O usuário deve entrar com o valor 0 indicando
que não serão mais fornecidos novos valores. Seu programa deve exibir uma mensagem de
erro se o primeiro valor fornecido pelo usuário for 0.

Dica: o número 0 não deve ser incluído no cálculo da média, pois ele só serve para sinalizar
o final da entrada de dados.*/

#include <stdio.h>

void main() {
    int soma = 0, quant = 0, n;

    while (1) {
        printf("Digite um numero (0 para sair): ");
        scanf("%d", &n);

        if (n == 0)
            break;

        soma += n;
        quant++;
    }

    float media = (float)soma / (float)quant;
    printf("Media dos numeros inseridos: %.2f\n", media);
}
