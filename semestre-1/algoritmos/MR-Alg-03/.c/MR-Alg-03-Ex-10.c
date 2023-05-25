/*As posições das casas em tabuleiros de xadrez são identificadas
por uma letra e um número. A letra identifica a coluna e o número define a linha, conforme a
figura abaixo:

Escreva um programa Python que receba do usuário um posição. Use um comando if para
determinar se a coluna informada começa com quadrado preto ou branco. Então, use
aritmética de inteiros para determinar a cor do quadrado da linha correspondente. Por
exemplo, se o usuário entrou com o valor a1, então seu programa deve informar que o
quadrado é preto. Se o usuário entrou com o valor d5, então seu programa deve informar que
o quadrado é branco. Seu programa pode assumir que o usuário vai entrar valores válidos,
não sendo necessário verificar eventuais erros de input.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void main() {
    int linha;
    char coluna;

    printf("Coluna da posicao: ");
    scanf("%c", &coluna);

    printf("Linha da posicao: ");
    scanf("%d", &linha);

    char *cor;

    switch (tolower(coluna)) {
        case 'a':
        case 'c':
        case 'e':
        case 'g':
            cor = "preto";
            break;
        case 'b':
        case 'd':
        case 'f':
        case 'h':
            cor = "branco";
            break;
        default:
            printf("Coluna invalida: %c\n", coluna);
            exit(-1);
    }

    // Se a linha é par, inverte a cor
    if (linha % 2 == 0) {
        if (cor == "branco")
            cor = "preto";
        else
            cor = "branco";
    }

    printf("Cor em %c%d: %s\n", toupper(coluna), linha, cor);
}
