/*Admitindo que uma data é lida pelo algoritmo em uma variável inteira, e não
em uma variável do tipo data, crie um programa Python que leia uma data no formato
DDMMAA e imprima essa data no formato AAMMDD, onde:
• a letra D corresponde a dois algarismos representando o dia;
• a letra M corresponde a dois algarismos representando o mês;
• a letra A corresponde aos dois últimos algarismos representando o ano.
Por exemplo: a data 110618 (11 de junho de 2018), deve ser impressa como 180611*/

#include <stdio.h>

void main() {
    int data;
    printf("Digite uma data no formato DDMMAA: ");
    scanf("%d", &data);

    int dia = data / 10000;
    int mes = data / 100 % 100;
    int ano = data % 100;

    printf("%c%d", ano < 10 ? '0' : '\0', ano);
    printf("%c%d", mes < 10 ? '0' : '\0', mes);
    printf("%c%d\n", dia < 10 ? '0' : '\0', dia);
}
