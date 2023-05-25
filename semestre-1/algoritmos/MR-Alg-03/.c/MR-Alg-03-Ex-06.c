/*Baseado nos comprimentos dos seus lados, um triângulo pode ser
classificado como equilátero (quando os três lados tem o mesmo tamanho), isósceles (quando
apenas dois lados são iguais) ou escaleno (quando os três lados são diferentes). Escreva um
programa Python que recebe do usuário os comprimentos dos 3 lados de um triângulo e exiba
uma mensagem informando qual é o tipo do triângulo.*/

#include <stdio.h>

void main() {
    int a, b, c;

    printf("Lado a: ");
    scanf("%d", &a);

    printf("Lado b: ");
    scanf("%d", &b);

    printf("Lado c: ");
    scanf("%d", &c);

    if (a == b && b == c)
        printf("Equilatero\n");
    else if (a == b || a == c || b == c)
        printf("Isosceles");
    else
        printf("Escaleno\n");
}
