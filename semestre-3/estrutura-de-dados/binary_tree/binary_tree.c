#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "binary_tree.h"

/// @brief Creates and initializes new node
/// @param value value that node will hold
/// @return The created node
node_t *node_init(int value);

/// @brief Frees a node
/// @param node node to free 
void node_free(node_t *node);

/// @brief Frees a node and its descendants
/// @param node node to free
void node_recursive_free(node_t *node);

/// @brief Print a node, used in recursive binary tree printing
/// @param node node to be printed
void node_print(node_t *node);

/// @brief Height of a node in a binary tree
/// @param node node to test
/// @return Height for given node
size_t node_height(node_t *node);

/// @brief Find minimum value node starting on this node
/// @param node node to start
/// @param parent optional output parent node value
/// @return Node with minimum value
node_t *node_min(node_t *node, node_t **parent);

/// @brief Find maximum value node starting on this node
/// @param node node to start
/// @param parent optional output parent node value
/// @return Node with maximum value
node_t *node_max(node_t *node, node_t **parent);

btree_t *btree_init() {
    btree_t *btree = (btree_t*)malloc(sizeof(btree_t));
    btree->root = NULL;

    return btree;
}

void btree_free(btree_t *btree) {
    if (btree == NULL) return;

    node_recursive_free(btree->root);

    btree->root = NULL;
}

size_t btree_height(btree_t *btree) {
    if (btree == NULL || btree->root == NULL) return 0;

    return node_height(btree->root) - 1;
}

void btree_insert(btree_t *btree, int value) {
    if (btree == NULL) return;

    node_t *new_node = node_init(value);
    if (btree->root == NULL) {
        btree->root = new_node;
        return;
    }

    node_t *node = btree->root;
    while (1) {
        if (value <= node->value) {
            // Going left in the tree
            if (node->left == NULL) {
                node->left = new_node;
                break;
            } else {
                node = node->left;
            }
        } else {
            // Going right in the tree
            if (node->right == NULL) {
                node->right = new_node;
                break;
            } else {
                node = node->right;
            }
        }
    }
}

void btree_delete(btree_t *btree, int value) {
    // If no root can't delete anything
    if (btree == NULL || btree->root == NULL) return;

    // Try to find node
    node_t *parent = NULL;
    node_t *node = btree_find(btree, value, &parent);
    if (node == NULL) return;

    // Handle case where the root is to be deleted (no parent)
    if (node == btree->root) {
        if (node->left == NULL && node->right == NULL) {
            // Only root
            btree->root = NULL;
        } else if (node->right == NULL) {
            // Node to left is new root
            btree->root = node->left;
        } else if (node->left == NULL) {
            // Node to right is new root
            btree->root = node->right;
        } else {
            // Minimum node to right is new root
            node_t *min_parent = NULL;
            node_t *min = node_min(node->right, &min_parent);

            min->left = node->left;
            btree->root = min;

            if (min_parent != NULL) {
                printf("parent is %d\n", min_parent->value);
                min_parent->left = NULL;
            }
        }

        node_free(node);
        return;
    }

    // Whether node is to left or right of parent
    int to_left = parent->left == node;

    if (node->left == NULL && node->right == NULL) {
        // No children
        if (to_left) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (node->right == NULL) {
        // Child only at left
        if (to_left) {
            parent->left = node->left;
        } else {
            parent->right = node->left;
        }
    } else if (node->left == NULL) {
        // Child only at right
        if (to_left) {
            parent->left = node->right;
        } else {
            parent->right = node->right;
        }
    } else {
        // Two children
        node_t *min_parent = NULL;
        node_t *min = node_min(node->right, &min_parent);
        min->left = node->left;

        if (to_left) {
            parent->left = min;
        } else {
            parent->right = min;
        }

        if (min_parent != NULL) {
            min_parent->left = NULL;
        }
    }

    node_free(node);

}

int btree_min(btree_t *btree) {
    if (btree == NULL) return 0;

    node_t *node = node_min(btree->root, NULL);
    if (node == NULL) {
        return 0;
    }

    return node->value;
}

int btree_max(btree_t *btree) {
    if (btree == NULL) return 0;

    node_t *node = node_max(btree->root, NULL);
    if (node == NULL) {
        return 0;
    }

    return node->value;
}

void btree_print(btree_t *btree) {
    if (btree == NULL) return;

    node_print(btree->root);
}

void btree_pretty_print(btree_t *btree) {
    if (btree == NULL || btree->root == NULL) return;

    int max = btree_max(btree);
    size_t height = btree_height(btree);
    size_t digits = log10(max);
    digits++;

    size_t num_elements_last_line = pow(2, height);
    size_t last_line_length = num_elements_last_line * 4 - 3;

    // Print first line
    size_t i;
    for (i = 0; i < last_line_length / 2 - 1; ++i)
        printf(" ");
    printf("%d", btree->root->value);
    for (i = 0; i < last_line_length / 2 - 1; ++i)
        printf(" ");
    printf("\n");

    // TODO: Recursively print other lines
    // node_pretty_print(btree->root); // not implemented
}

node_t *btree_find(btree_t *btree, int value, node_t **parent) {
    if (btree == NULL) return NULL;

    node_t *parent_p = NULL;
    node_t *node = btree->root;
    while (node != NULL) {
        if (value == node->value) {
            break;
        } else if (value < node->value) {
            parent_p = node;
            node = node->left;
        } else {
            parent_p = node;
            node = node->right;
        }
    }

    // Set parent output
    if (parent != NULL) {
        if (parent_p == NULL) {
            *parent = NULL;
        } else {
            *parent = parent_p;
        }
    }

    return node;
}

node_t *node_init(int value) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

void node_free(node_t *node) {
    if (node == NULL) return;

    free(node);
    node->left = NULL;
    node->right = NULL;
    node->value = 0;
}

void node_recursive_free(node_t *node) {
    if (node == NULL) return;

    node_recursive_free(node->left);
    node_recursive_free(node->right);

    node_free(node);
}

void node_print(node_t *node) {
    if (node == NULL) return;

    // Print left side
    if (node->left != NULL) {
        node_print(node->left);
    }

    // Print current node
    printf("%d\n", node->value);

    // Print right side
    if (node->right != NULL) {
        node_print(node->right);
    }
}

size_t node_height(node_t *node) {
    if (node == NULL) return 0;

    size_t h_left = node_height(node->left);
    size_t h_right = node_height(node->right);

    return ((h_left > h_right) ? h_left : h_right) + 1;
}

node_t *node_min(node_t *node, node_t **parent) {
    if (node == NULL) return NULL;

    node_t *parent_p = NULL;
    node_t *node_n = node;
    while (node_n->left != NULL) {
        parent_p = node_n;
        node_n = node_n->left;
    }

    // Set parent output
    if (parent != NULL) {
        *parent = parent_p;
    }

    return node_n;
}

node_t *node_max(node_t *node, node_t **parent) {
    if (node == NULL) return NULL;

    node_t *parent_p = NULL;
    node_t *node_n = node;
    while (node_n->right != NULL) {
        parent_p = node_n;
        node_n = node_n->right;
    }

    // Set parent output
    if (parent != NULL) {
        *parent = parent_p;
    }

    return node_n;
}
