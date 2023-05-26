/*Crie um programa Python para calcular o perímetro de um
polígono sendo fornecidas as coordenadas x e y de cada um de seus vértices. Inicie lendo x e
y do primeiro vértice. Depois disso continue lendo x e y dos próximos vértices até que o
usuário entre com uma linha em branco para o valor da coordenada x (ou seja, quando ele
digitar “Enter" ou “Return" sem fornecer um valor). Cada vez que você ler as coordenadas de
um novo vértice, você deve calcular a distância em relação ao vértice anterior e acrescentá-la
ao valor do perímetro. A figura abaixo ilustra como se calcula a distância entre dois pontos
sendo dadas suas coordenadas x e y.

Quando o usuário entrar com a linha em branco na coordenada x, seu programa deve
adicionar ao perímetro a distância do último ponto até o primeiro. Depois disso, deve exibir o
valor do perímetro. Um exemplo de entrada é mostrado abaixo (o valores digitados pelo
usuário estão em negrito.
Digite a coordenada x de um ponto: 0
Digite a coordenada y de um ponto: 0
Digite a coordenada x de um ponto (enter para sair): 1
Digite a coordenada y de um ponto: 0
Digite a coordenada x de um ponto (enter para sair): 0
Digite a coordenada y de um ponto: 1
Digite a coordenada x de um ponto (enter para sair):
O perímetro deste polígono é igual a 3.41421356237309*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(double x0, double x1, double y0, double y1) {
    return sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
}

void main() {
    double perimetro = 0;
    double last_x, last_y;
    double first_x, first_y;    // Para fechar o polígono
    double x, y;
    int num_points = 0;
    char input[10];

    while (1) {
        printf("X (enter para sair): ");
        fgets(input, 9, stdin);
        if (*input == '\n')
            break;

        x = strtof(input, NULL);

        printf("Y: ");
        fgets(input, 9, stdin);
        if (*input == '\n')
            break;

        y = strtof(input, NULL);

        if (num_points == 0) {
            first_x = x;
            first_y = y;
        } else
            perimetro += distance(last_x, x, last_y, y);
        
        printf("New point: (%.9f, %.9f)\n", x, y);

        last_x = x;
        last_y = y;

        num_points++;
    }

    if (num_points > 2) {
        perimetro += distance(x, first_x, y, first_y);
        printf("Perimetro: %.2lf\n", perimetro);
    }
    else
        printf("Nao foram informados pontos suficientes (necessario no minimo 3)\n");
}
