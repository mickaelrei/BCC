﻿/*A tabela abaixo mostra uma lista de volume sonoro em decibéis para
diferentes tipos comuns de barulhos.

Escreva um programa Python que receba do usuário um nível de volume em decibéis. Se o
usuário entrar com um valor igual a um daqueles listados na tabela, então seu programa deve
exibir uma mensagem informando o tipo de barulho da tabela equivalente ao valor informado.
Se o usuário entrar um valor intermediário entre dois valores da tabela, então seu programa
deve exibir uma mensagem informando que o nível está entre os dois barulhos (deve informar
quais são eles). Certifique-se também que seu programa exiba mensagens apropriadas caso o
usuário entre com valor menor que o menor valor da tabela ou maior que o maior valor.*/

#include <stdio.h>

void main() {
    int db;
    printf("Volume em db: ");
    scanf("%d", &db);

    if (db > 130)
        printf("Mais barulhento que britadeira\n");
    else if (db == 130)
        printf("Britadeira\n");
    else if (db < 130 && db > 106)
        printf("Entre cortador de grama e britadeira\n");
    else if (db == 106)
        printf("Cortador de grama\n");
    else if (db < 106 && db > 70)
        printf("Entre despertador e cortador de grama\n");
    else if (db == 70)
        printf("Despertador\n");
    else if (db < 70 && db > 40)
        printf("Entre sala silenciosa e despertador\n");
    else if (db == 40)
        printf("Sala silenciosa\n");
    else
        printf("Mais silencioso que sala silenciosa\n");
}
