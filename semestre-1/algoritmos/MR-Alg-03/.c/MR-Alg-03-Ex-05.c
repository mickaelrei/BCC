/*A quantidade de dias de um mês pode variar de 28 a 31
dias. Neste exercício você deve criar um programa Python que recebe do usuário o nome de
um mês (como uma string). Então seu programa deve exibir uma mensagem informando a
quantidade de dias daquele mês. Caso o mês seja fevereiro, sua mensagem pode informar
“28 ou 29 dias”.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lower_string(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

void main() {
    char mes[10];
    printf("Mes: ");
    scanf("%s", &mes);

    // Deixa em minúsculo
    lower_string(mes);

    if (strcmp(mes, "abril") == 0 || strcmp(mes, "junho") == 0 ||
        strcmp(mes, "setembro") == 0 || strcmp(mes, "novembro") == 0)
    {
        printf("30 dias\n");
    }
    else if (strcmp(mes, "fevereiro") == 0)
    {
        printf("28 ou 29 dias\n");
    }
    else if (strcmp(mes, "janeiro") == 0 || strcmp(mes, "marco") == 0 || strcmp(mes, "maio") == 0 ||
             strcmp(mes, "julho") == 0 ||  strcmp(mes, "agosto") == 0 || strcmp(mes, "outubro") == 0 ||
             strcmp(mes, "dezembro") == 0)
    {
        printf("31 dias\n");
    } else
    {
        printf("Mes invalido\n");
    }

}
