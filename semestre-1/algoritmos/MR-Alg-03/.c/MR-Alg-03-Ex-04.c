/*Crie um programa Python que determina e exibe o nome de um polígono
regular sendo fornecida pelo usuário a quantidade de lados. Seu programa deve suportar
polígonos de 3 a 10 lados (inclusive). Caso o usuário forneça valores fora desta faixa, o
programa deve exibir uma mensagem de erro.*/

#include <stdio.h>

void main() {
    int lados;
    printf("Quantidade de lados (3-10): ");
    scanf("%d", &lados);
    
    switch (lados)
    {
    case 3:
        printf("Triangulo\n");
        break;
    case 4:
        printf("Quadrado\n");
        break;
    case 5:
        printf("Pentagono\n");
        break;
    case 6:
        printf("Hexagono\n");
        break;
    case 7:
        printf("Heptagono\n");
        break;
    case 8:
        printf("Octogono\n");
        break;
    case 9:
        printf("Eneagono\n");
        break;
    case 10:
        printf("Decagono\n");
        break;
    default:
        printf("Invalido\n");
        break;
    }
}
