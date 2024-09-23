#include <stdlib.h>

#include "trie_tree.h"

trie_node_t *trie_node_init() {
    trie_node_t *node = (trie_node_t*)malloc(sizeof(trie_node_t));
    node->isEnd = 0;
    for (int i = 0; i < CHILDREN_COUNT; ++i) {
        node->children[i] = NULL;
    }
    return node;
}

void trie_tree_insert(trie_node_t *root, const char *word) {
    while (*word != '\0') {
        int idx = *word - 'a';

        // Sanity check for invalid characters
        if (idx < 0 || idx >= CHILDREN_COUNT) {
            ++word;
            continue;
        }
        
        // Create node if not existent yet
        if (root->children[idx] == NULL) {
            root->children[idx] = trie_node_init();
        }

        root = root->children[idx];
        ++word;
    }

    // Final node represents the end of the new inserted word
    root->isEnd = 1;
}

int trie_tree_search(trie_node_t *root, const char *word) {
    while (*word != '\0') {
        int idx = *word - 'a';

        // If char is invalid skip
        if (idx < 0 || idx >= CHILDREN_COUNT) {
            ++word;
            continue;
        }

        // If child node is null, word is not found
        if (root->children[idx] == NULL) return 0;

        root = root->children[idx];
        ++word;
    }

    // Word only exists if last node is end of a word
    return root->isEnd;
}

void trie_tree_free(trie_node_t *root) {
    if (root == NULL) return;

    for (int i = 0; i < CHILDREN_COUNT; ++i)
        trie_tree_free(root->children[i]);

    free(root);
}