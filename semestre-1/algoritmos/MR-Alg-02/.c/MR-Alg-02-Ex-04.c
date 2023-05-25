/*Crie um programa que obtém 3 números inteiros do usuário e os
exibe de forma ordenada do menor para o maior. Use as funções min e max para encontrar o
menor valor e o maior valor. Dica: o valor do meio pode ser obtido pela soma dos três valores,
subtraída do maior e do menor.*/

#include <stdio.h>

int min(int *arr, size_t size) {
    int curr_min = __INT_MAX__;
    for (int i = 0; i < size; i++) {
        if (arr[i] < curr_min)
            curr_min = arr[i];
    }

    return curr_min;
}

int max(int *arr, size_t size) {
    int curr_max = -__INT_MAX__;
    for (int i = 0; i < size; i++) {
        if (arr[i] > curr_max)
            curr_max = arr[i];
    }

    return curr_max;
}

void main() {
    int a, b, c;
    printf("A: ");
    scanf("%d", &a);

    printf("B: ");
    scanf("%d", &b);

    printf("C: ");
    scanf("%d", &c);

    int arr[3] = {a, b, c};
    int _min = min(arr, sizeof arr / sizeof *arr);
    int _max = max(arr, sizeof arr / sizeof *arr); 
    int median = a + b + c - _min - _max;
    printf("Ordem crescente: %d, %d, %d\n", _min, median, _max); 
}