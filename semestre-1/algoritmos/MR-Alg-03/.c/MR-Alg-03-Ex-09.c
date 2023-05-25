/*A tabela abaixo mostra os feriados nacionais brasileiros que caem sempre no
mesmo dia (em oposição aos feriados variáveis como carnaval e corpus christi).

Feriado                         Data
Confraternização universal      1o. de janeiro
Tiradentes                      21 de abril
Dia do trabalho                 1o. de maio
Independência do Brasil         7 de setembro
Nossa Senhora Aparecida         12 de outubro
Finados                         2 de novembro
Proclamação da República        15 de novembro
Natal                           25 de dezembro

Escreva um programa Python que leia do usuário o mês e o dia de uma determinada data. Se
o mês e o dia corresponderem a uma das datas da tabela acima, seu programa deve exibir o
nome do feriado. Caso contrário o programa deve informar que o dia e o mês informados não
correspondem a um feriado nacional.*/

#include <stdio.h>

void main() {
    int dia, mes;
    printf("Dia: ");
    scanf("%d", &dia);

    printf("Numero do mes: ");
    scanf("%d", &mes);

    int feriados_data[][2] = {
        {1, 1},
        {21, 4},
        {1, 5},
        {7, 9},
        {12, 10},
        {2, 11},
        {15, 11},
        {25, 12}
    };

    char *feriados_nome[] = {
        "Confraternizacao universal",
        "Tiradentes",
        "Dia do trabalho",
        "Independencia do Brasil",
        "Nossa Senhora Aparecida",
        "Finados",
        "Proclamacao da Republica",
        "Natal"
    };

    size_t num_feridos = sizeof feriados_data / sizeof *feriados_data;
    for (int i = 0; i < num_feridos; i++) {
        if (feriados_data[i][0] == dia && feriados_data[i][1] == mes) {
            printf("%c%d/%c%d: %s\n", dia < 10 ? '0' : '\0', dia, mes < 10 ? '0' : '\0', mes, feriados_nome[i]);
        }
    }
}
