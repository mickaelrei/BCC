/*O valor aproximado de pode ser calculado pela série infinita
apresentada abaixo:

Escreva um programa Python que exiba 15 aproximações de . A primeira aproximação deve
ter apenas o primeiro termo da série (ou seja, o valor resultante vai ser somente 3). Cada nova
aproximação de mostrada pelo seu programa deve incluir mais um termo da série, sendo
cada vez uma aproximação mais precisa do que a anterior.*/

#include <stdio.h>

void main() {
    int aproximacoes = 1000000000;
    double meu_pi = 3;

    for (int i = 0; i < aproximacoes - 1; i++) {
        double m = (i + 1) * 2;
        double termo = 4 / (m * (m + 1) * (m + 2));

        meu_pi += i % 2 == 0 ? termo : -termo;
    }

    printf("Pi apos %d aproximacoes: %.25lf\n", aproximacoes, meu_pi);
}