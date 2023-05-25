/*Dado um número de três algarismos N = CDU
(onde C é o algarismo das centenas, D é o algarismo das dezenas e U o algarismo das
unidades), considere o número M constituído pelos algarismos de N em ordem inversa, isto é,
M=UDC. Faça um programa Python para gerar e imprimir M a partir de N (p.ex.:N=123
->M=321).*/

#include <stdio.h>

void main() {
    int n;
    printf("Digite um numero de 3 algarismos: ");
    scanf("%d", &n);

    int centena = n / 100;
    int dezena = n / 10 % 10;
    int unidade = n % 10;

    int m = unidade * 100 + dezena * 10 + centena;
    printf("M = %d\n", m);
}
