/*Uma função quadrática pode ser descrita da seguinte forma:
f(x) = ax² + bx + c, onde a, b e c são constantes, e a é diferente de zero. As raízes da
função quadrática podem ser encontradas determinando-se os valores de x que satisfaçam a
equação quadrática ax² + bx + c = 0. Uma função quadrática pode ter 0, 1 ou 2 raízes
reais. Essas raízes podem ser calculadas pela fórmula da Bháskara, mostrada abaixo:

A parte da expressão dentro da raiz quadrada é chamada de discriminante. Se o discriminante
for negativo, a equação não possui raízes reais. Se o discriminante for igual a zero, então a
equação tem apenas uma raiz real. Caso contrário, a equação tem duas raízes reais e a
expressão deve ser computada duas vezes, uma com o sinal de + e a outra com o sinal de -
ao se calcular o numerador da fração.
Escreva um programa Python que calcula as raízes reais de uma função quadrática. Seu
programa deve iniciar solicitando ao usuário os valores de a, b e c. Então o programa deve
exibir uma mensagem informando a quantidade de raízes reais e o(s) valor(es) da(s) raiz(es).*/

#include <stdio.h>
#include <math.h>

void main() {
    float a, b, c;

    printf("Valor de a: ");
    scanf("%f", &a);

    printf("Valor de b: ");
    scanf("%f", &b);

    printf("Valor de c: ");
    scanf("%f", &c);

    float delta = b*b - 4*a*c;
    if (delta < 0)
        printf("Nao ha raizes reais para a equacao dada.\n");
    else if (delta == 0) {
        float x = -b / (2*a);
        printf("Ha uma raiz unica: %f\n", x);
    } else {
        float x1 = (-b + sqrt(delta)) / (2*a);
        float x2 = (-b - sqrt(delta)) / (2*a);
        printf("Ha duas raizes reais distintas: %f e %f\n", x1, x2);
    }
}
