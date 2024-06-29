#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void print_arr(int *arr, size_t n);

int main() {
    // srand(time(NULL));

    const size_t n = 25;

    int *arr = malloc(sizeof(int) * n);
    for (size_t i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    print_arr(arr, n);
    merge_sort(arr, n);
    print_arr(arr, n);
}

void print_arr(int *arr, size_t n) {
    size_t i;
    for (i = 0; i < n - 1; ++i) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[i]);
}