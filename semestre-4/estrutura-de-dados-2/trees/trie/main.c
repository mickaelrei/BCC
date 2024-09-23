#include <stdio.h>

#include "trie_tree.h"

int main() {
    trie_node_t *tree = trie_node_init();

    // Add words
    char* words[] = {"quiabo", "douglas", "dores", "quilo", "estrada", "estar"};
    int n = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < n; i++) {
        trie_tree_insert(tree, words[i]);
    }

    // Search words
    char* searches[] = {"douglas", "do", "quilo", "qui", "estrada", "est"};
    int m = sizeof(searches) / sizeof(searches[0]);

    for (int i = 0; i < m; i++) {
        printf("Word: %s\n", searches[i]);
        if (trie_tree_search(tree, searches[i])) {
            printf("Found\n\n");
        } else {
            printf("Not found\n\n");
        }
    }

    trie_tree_free(tree);

    return 0;
}