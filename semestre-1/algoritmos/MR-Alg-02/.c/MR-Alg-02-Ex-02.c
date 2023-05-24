/*Neste exercício você deve fazer o processo inverso do
exercício anterior. Desenvolva um programa Python que recebe do usuário uma quantidade de
tempo em segundos. Então o programa deve exibir a quantidade de tempo equivalente na
forma D:HH:MM:SS, onde D, HH, MM e SS representam dias, horas, minutos e segundos
respectivamente. Os valores de horas, minutos e segundos devem ser formatados todos com
dois dígitos, sendo obrigatória a inclusão do dígito 0 para valores menores que 10.*/

#include <stdio.h>

void main() {
    int total_segundos;
    printf("Segundos: ");
    scanf("%d", &total_segundos);

    int segundos = total_segundos % 60;
    int minutos = total_segundos / 60 % 60;
    int horas = total_segundos / 3600 % 24;
    int dias = total_segundos / 86400;

    if (dias < 10)
        printf("0%d:", dias);
    else
        printf("%d:", dias);

    if (horas < 10)
        printf("0%d:", horas);
    else
        printf("%d:", horas);

    if (minutos < 10)
        printf("0%d:", minutos);
    else
        printf("%d:", minutos);

    if (segundos < 10)
        printf("0%d\n", segundos);
    else
        printf("%d\n", segundos);
}