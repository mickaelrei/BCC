/*Uma loja está oferecendo uma liquidação com descontos de 60% em
uma variedade de produtos em final de estoque. O vendedor gostaria de ajudar seus clientes a
determinar o preço reduzido (com desconto) de seus produtos. Ele quer criar uma tabela que
mostra os preços originais e os preços após o desconto ser aplicado. Escreva um programa
Python usando laço de repetição que gere esta tabela mostrando o preço original, o valor de
desconto e o novo valor com desconto aplicado para produtos com os seguintes valores:
R$ 4.95, R$ 9.95, R$ 14.95, R$ 19.95 e R$ 24.95. Certifique-se que todos os valores são
mostrados com duas casas decimais.*/

#include <stdio.h>

void main() {
    float precos[] = {4.95, 9.95, 14.95, 19.95, 24.95};
    float desconto = .6;

    for (int i = 0; i < sizeof precos / sizeof *precos; i++) {
        float valor_desconto = precos[i] * desconto;
        float valor_final = precos[i] - valor_desconto;
        printf("Valor original: R$ %.2f\nDesconto: R$ %.2f\nNovo valor: R$ %.2f\n\n", precos[i], valor_desconto, valor_final);
    }
}
