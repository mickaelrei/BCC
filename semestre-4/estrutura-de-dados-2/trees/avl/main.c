#include <stdio.h>

#include "avl_tree.h"

int main() {
    avl_tree_t *avl_tree = avl_tree_init();
    printf("height: %ld\n", avl_tree_height(avl_tree));
    avl_tree_insert(avl_tree, 1);
    avl_tree_insert(avl_tree, 2);
    avl_tree_insert(avl_tree, 3);
    avl_tree_insert(avl_tree, 4);
    avl_tree_insert(avl_tree, 5);
    avl_tree_insert(avl_tree, 6);
    avl_tree_insert(avl_tree, 7);
    avl_tree_insert(avl_tree, 8);
    avl_tree_insert(avl_tree, 9);
    printf("height: %ld\n", avl_tree_height(avl_tree));

    printf("min=%d, max=%d\n", avl_tree_min(avl_tree), avl_tree_max(avl_tree));

    printf("printing\n");
    avl_tree_print(avl_tree);

    int x = 5;
    printf("deleting %d\n", x);
    avl_tree_delete(avl_tree, x);

    printf("root is %d\n", avl_tree->root->value);

    printf("printing\n");
    avl_tree_print(avl_tree);

    avl_tree_free(avl_tree);
}