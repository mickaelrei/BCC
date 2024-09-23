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

bin_tree_t *bin_tree_init() {
    bin_tree_t *bin_tree = (bin_tree_t*)malloc(sizeof(bin_tree_t));
    bin_tree->root = NULL;

    return bin_tree;
}

void bin_tree_free(bin_tree_t *bin_tree) {
    if (bin_tree == NULL) return;

    node_recursive_free(bin_tree->root);
    bin_tree->root = NULL;

    free(bin_tree);
}

size_t bin_tree_height(bin_tree_t *bin_tree) {
    if (bin_tree == NULL || bin_tree->root == NULL) return 0;

    return node_height(bin_tree->root) - 1;
}

void node_insert(node_t *node, node_t *new_node) {
    if (node == NULL) return;

    if (new_node->value <= node->value) {
        // Going left
        if (node->left == NULL) {
            node->left = new_node;
        } else {
            node_insert(node->left, new_node);
        }
    } else {
        // Going right
        if (node->right == NULL) {
            node->right = new_node;
        } else {
            node_insert(node->right, new_node);
        }
    }
}

void bin_tree_insert(bin_tree_t *bin_tree, int value) {
    if (bin_tree == NULL) return;

    node_t *new_node = node_init(value);
    if (bin_tree->root == NULL) {
        bin_tree->root = new_node;
        return;
    }

    node_t *node = bin_tree->root;
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

node_t* delete_node(node_t* node, int x) {
    // Base case
    if (node == NULL) {
        return node;
    }

    // Check if need to either right or left
    if (node->value > x)
        node->left = delete_node(node->left, x);
    else if (node->value < x)
        node->right = delete_node(node->right, x);
    else {
        // If got here, node matches value

        // Case when node has 0 or only right child
        if (node->left == NULL) {
            node_t* temp = node->right;
            free(node);
            return temp;
        }

        // Case when node has only left child
        if (node->right == NULL) {
            node_t* temp = node->left;
            free(node);
            return temp;
        }

        // Case when node has 2 chidlren
        node_t* successor = node_min(node->right, NULL);
        node->value = successor->value;
        node->right = delete_node(node->right, successor->value);
    }
    return node;
}

void bin_tree_delete(bin_tree_t *bin_tree, int value) {
    // If no root can't delete anything
    if (bin_tree == NULL || bin_tree->root == NULL) return;

    bin_tree->root = delete_node(bin_tree->root, value);
}

int bin_tree_min(bin_tree_t *bin_tree) {
    if (bin_tree == NULL) return 0;

    node_t *node = node_min(bin_tree->root, NULL);
    if (node == NULL) {
        return 0;
    }

    return node->value;
}

int bin_tree_max(bin_tree_t *bin_tree) {
    if (bin_tree == NULL) return 0;

    node_t *node = node_max(bin_tree->root, NULL);
    if (node == NULL) {
        return 0;
    }

    return node->value;
}

void bin_tree_print(bin_tree_t *bin_tree) {
    if (bin_tree == NULL) return;

    node_print(bin_tree->root);
}

node_t *bin_tree_find(bin_tree_t *bin_tree, int value, node_t **parent) {
    if (bin_tree == NULL) return NULL;

    node_t *parent_p = NULL;
    node_t *node = bin_tree->root;
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

    node->left = NULL;
    node->right = NULL;
    node->value = 0;
    free(node);
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
    while (node->left != NULL) {
        parent_p = node;
        node = node->left;
    }

    // Set parent output
    if (parent != NULL) {
        *parent = parent_p;
    }

    return node;
}

node_t *node_max(node_t *node, node_t **parent) {
    if (node == NULL) return NULL;

    node_t *parent_p = NULL;
    while (node->right != NULL) {
        parent_p = node;
        node = node->right;
    }

    // Set parent output
    if (parent != NULL) {
        *parent = parent_p;
    }

    return node;
}
