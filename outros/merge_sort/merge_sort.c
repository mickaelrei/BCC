#include <stdlib.h>
#include <stdio.h>

#include "merge_sort.h"

void divide(int *arr, size_t start, size_t end, size_t tab);
void merge(int *arr, size_t start, size_t mid, size_t end, size_t tab);

void merge_sort(int *arr, size_t n) {
    if (n <= 1) return;

    size_t mid = n / 2;
    divide(arr, 0, mid, 0);
    divide(arr, mid, n, 0);
    merge(arr, 0, mid, n, 0);
}

void divide(int *arr, size_t start, size_t end, size_t tab) {
    size_t size = end - start;
    if (size == 1) return;

    size_t mid = (start + end) / 2;

    // Divide left, then right, then merge
    divide(arr, start, mid, tab + 1);
    divide(arr, mid, end, tab + 1);
    merge(arr, start, mid, end, tab);
}

void merge(int *arr, size_t start, size_t mid, size_t end, size_t tab) {
    size_t i;
    size_t size = end - start;

    // Allocate auxiliary array
    int *aux = malloc(sizeof(int) * size);
    for (i = 0; i < size; ++i) {
        aux[i] = arr[start + i];
    }

    size_t left = 0;
    size_t size_left = mid - start;
    size_t size_right = end - mid;
    size_t right = size_left;

    // Fill in ascending order making sure not to read out of bounds
    for (i = 0; i < size; ++i) {
        if (right == size || (aux[left] < aux[right] && left < size_left)) {
            arr[start + i] = aux[left++];
        } else {
            arr[start + i] = aux[right++];
        }
    }

    free(aux);
}
