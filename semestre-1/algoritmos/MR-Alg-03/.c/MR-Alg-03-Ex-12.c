/*A maioria dos anos possui 365 dias. Porém, o tempo para a Terra dar uma volta
completa em torno do Sol é um pouco maior que isso. Como consequência, um dia extra (29
de fevereiro) é incluído em alguns anos para compensar essa diferença. Tais anos são
chamados de anos bissextos. As regras para determinar se um ano é ou não bissexto são as
seguintes:
• Qualquer ano divisível por 400 é bissexto
• Dos demais anos, qualquer ano divisível por 100 não é um ano bissexto
• Dos demais anos, qualquer ano divisível por 4 é um ano bissexto
• Todos os outros anos não são bissextos.
Escreva um programa Python que recebe do usuário um ano, e exibe uma mensagem
informando se o ano é ou não é bissexto.*/

#include <stdio.h>

void main() {
    int ano;
    printf("Ano: ");
    scanf("%d", &ano);

    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
        printf("%d e bissexto\n", ano);
    else
        printf("%d nao e bissexto\n", ano);
}
