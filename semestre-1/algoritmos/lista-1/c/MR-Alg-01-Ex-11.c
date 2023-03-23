#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

void main() {
   double t1, g1, t2, g2;

   printf("Latitude 1: ");
   scanf("%lf", &t1);

   printf("Longitude 1: ");
   scanf("%lf", &g1);

   printf("Latitude 2: ");
   scanf("%lf", &t2);

   printf("Longitude 2: ");
   scanf("%lf", &g2);

   // Converte para radiano
   t1 = t1 * PI / 180;
   g1 = g1 * PI / 180;
   t2 = t2 * PI / 180;
   g2 = g2 * PI / 180;

   double distancia = 6371.01 * acos(sin(t1) * sin(t2) + cos(t1) * cos(t2) * cos(g1 - g2));
   printf("Distância dos dois pontos: %.3lf km\n", distancia);
}