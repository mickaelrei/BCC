/* Crie um programa Python que leia do usuário um valor de intervalo de
tempo expresso em número de dias, horas, minutos e segundos. O programa deve computar e
exibir a quantidade total de segundos deste intervalo de tempo informado. */

#include <stdio.h>

void main() {
    int dias, horas, minutos, segundos;
    printf("Dias: ");
    scanf("%d", &dias);

    printf("Horas: ");
    scanf("%d", &horas);

    printf("Minutos: ");
    scanf("%d", &minutos);

    printf("Segundos: ");
    scanf("%d", &segundos);

    int total_time = ((dias * 24 + horas) * 60 + minutos) * 60 + segundos;

    printf("Total de segundos: %d\n", total_time);
}