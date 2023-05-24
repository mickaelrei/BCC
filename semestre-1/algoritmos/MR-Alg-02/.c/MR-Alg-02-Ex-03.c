/*A linguagem Python possui uma biblioteca de funções para lidar com tempo,
incluindo a função asctime no módulo time. Ela lê o tempo atual do Clock interno do
computador e o retorna em um formato legível. Escreva um programa que exiba a data e a
hora atuais. Seu programa não precisa obter qualquer entrada do usuário.*/

#include <stdio.h>
#include <time.h>

// https://stackoverflow.com/questions/5141960/get-the-current-time-in-c
// By: mingos
void main() {
    // time_t rawtime;
    // struct tm * timeinfo;

    // time(&rawtime);
    // timeinfo = localtime(&rawtime);
    // printf("Current local time and date: %s", asctime(timeinfo));
    char buffer[50];
    time_t now = time(NULL);
    struct tm *ts = localtime(&now);
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %a %H:%M:%S", ts);
    printf("'%s'\n", buffer);
}