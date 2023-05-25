/*Considere o software que controla uma máquina automática de compras.
Uma tarefa que ele precisa realizar é determinar quanto troco fornecer ao comprador quando
este faz o pagamento em dinheiro. Escreva um programa Python que inicia lendo do usuario
uma quantidade de centavos como um número inteiro (portanto vamos considerar números de
0 a 99). Então o seu programa deve calcular e exibir quantidade e o valor de cada moeda para
compor este troco em centavos informado. O troco deve ser montado com a menor quantidade
possível de moedas. Assuma que a máquina possui moedas de 50, 25, 10, 5 e 1 centavos.*/

#include <stdio.h>

void main() {
    // Lista de moedas existentes
    int moedas[] = {50, 25, 10, 5, 1};

    // Pega troco do usuário
    int troco;
    while (1) {
        printf("Digite o troco (0-99 centavos): ");
        scanf("%d", &troco);

        if (troco >= 0 && troco <= 99)
            break;

        printf("Entre 0 e 99!\n");
    }

    // Calcula quantas moedas de cada
    if (troco == 0)
        printf("Sem troco!\n");
    else {
        printf("Quantidade de moedas:\n");
        size_t num_moedas = sizeof moedas / sizeof *moedas;
        for (int i = 0; i < num_moedas; i++) {
            int quant = troco / moedas[i];
            troco -= quant * moedas[i];

            // Mostra resultado
            if (quant > 0)
                printf("%d moeda%c de %d centavo%c\n", quant, quant != 1 ? 's' : '\0', moedas[i], moedas[i] != 1 ? 's' : '\0');
        }
    }
}
