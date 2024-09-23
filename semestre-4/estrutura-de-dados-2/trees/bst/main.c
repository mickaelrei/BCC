#include <stdio.h>

#include "binary_tree.h"

int main() {
    bin_tree_t *bin_tree = bin_tree_init();
    printf("height: %ld\n", bin_tree_height(bin_tree));
    bin_tree_insert(bin_tree, 1);

    bin_tree_insert(bin_tree, 2);
    bin_tree_insert(bin_tree, 3);
    bin_tree_insert(bin_tree, 4);
    bin_tree_insert(bin_tree, 5);

    bin_tree_insert(bin_tree, 6);
    bin_tree_insert(bin_tree, 7);
    bin_tree_insert(bin_tree, 8);
    bin_tree_insert(bin_tree, 9);
    printf("height: %ld\n", bin_tree_height(bin_tree));

    printf("min=%d, max=%d\n", bin_tree_min(bin_tree), bin_tree_max(bin_tree));

    printf("printing\n");
    bin_tree_print(bin_tree);

    int x = 5;
    printf("deleting %d\n", x);
    bin_tree_delete(bin_tree, x);

    printf("root is %d\n", bin_tree->root->value);

    printf("printing\n");
    bin_tree_print(bin_tree);

    bin_tree_free(bin_tree);

}