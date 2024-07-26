#include <stdio.h>

#include "binary_tree.h"

int main() {
    btree_t *btree = btree_init();
    printf("height: %ld\n", btree_height(btree));
    btree_insert(btree, 5);

    btree_insert(btree, 3);
    btree_insert(btree, 1);
    btree_insert(btree, 2);
    btree_insert(btree, 4);

    btree_insert(btree, 8);
    btree_insert(btree, 6);
    btree_insert(btree, 7);
    btree_insert(btree, 9);
    printf("height: %ld\n", btree_height(btree));

    printf("min=%d, max=%d\n", btree_min(btree), btree_max(btree));

    printf("printing\n");
    btree_print(btree);

    int x = 5;
    printf("deleting %d\n", x);
    btree_delete(btree, x);

    printf("printing\n");
    btree_print(btree);

    printf("pretty printing\n");
    btree_pretty_print(btree);

    btree_free(btree);

}