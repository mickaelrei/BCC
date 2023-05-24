#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void main() {
    double r;

    printf("Digite o raio (em cm): ");
    scanf("%lf", &r);

    double area = PI * pow(r, 2);
    double volume = 4.0 / 3.0 * PI * pow(r, 3);

    printf("\nÁrea de um círculo com raio %lf = %.2lf cm²\n", r, area);
    printf("Volume de uma esfera com raio %lf = %.2lf cm³\n", r, volume);
}