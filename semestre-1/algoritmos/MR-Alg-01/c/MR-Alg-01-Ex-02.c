#include <stdio.h>

void main() {
    char name[20];

    printf("Digite seu nome: ");
    fgets(name, 200, stdin);

    printf("Olá, %s\n", name);
}