#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "avl_tree.h"

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
int node_height(node_t *node);

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

int max(int a, int b) {
    return (a > b) ? a : b;
}

avl_tree_t *avl_tree_init() {
    avl_tree_t *avl_tree = (avl_tree_t*)malloc(sizeof(avl_tree_t));
    avl_tree->root = NULL;

    return avl_tree;
}

void avl_tree_free(avl_tree_t *avl_tree) {
    if (avl_tree == NULL) return;

    node_recursive_free(avl_tree->root);
    avl_tree->root = NULL;

    free(avl_tree);
}

size_t avl_tree_height(avl_tree_t *avl_tree) {
    if (avl_tree == NULL || avl_tree->root == NULL) return 0;

    return node_height(avl_tree->root) - 1;
}

node_t *left_rotate(node_t *node) {
    node_t *right = node->right;
    node_t *right_left = right->left;

    // Rotation
    right->left = node;
    node->right = right_left;

    // Set new heights
    node->height = 1 + max(node_height(node->left), node_height(node->right));
    right->height = 1 + max(node_height(right->left), node_height(right->right));

    // New root
    return right;
}

node_t *right_rotate(node_t *node) {
    node_t *left = node->left;
    node_t *left_right = left->right;

    // Rotation
    left->right = node;
    node->left = left_right;

    // Set new heights
    node->height = 1 + max(node_height(node->left), node_height(node->right));
    left->height = 1 + max(node_height(left->left), node_height(left->right));

    // New root
    return left;
}

int node_balance(node_t *node) {
    if (node == NULL) return 0;

    return node_height(node->left) - node_height(node->right);
}

node_t *node_insert(node_t *node, node_t *new_node) {
    if (node == NULL) return new_node;

    if (new_node->value < node->value) {
        // Recursive to left
        node->left = node_insert(node->left, new_node);
    } else if (new_node->value > node->value) {
        // Recursive to right
        node->right = node_insert(node->right, new_node);
    } else {
        // Same key not allowed
        return node;
    }

    // Update height
    node->height = 1 + max(node_height(node->left), node_height(node->right));

    // Check if node is unbalanced
    int diff = node_balance(node);

    if (diff > 1 && new_node->value < node->left->value) {
        // Left-left rotation
        return right_rotate(node);
    }

    if (diff < -1 && new_node->value > node->right->value) {
        // Right-right rotation
        return left_rotate(node);
    }

    if (diff > 1 && new_node->value > node->left->value) {
        // left-right rotation
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (diff < -1 && new_node->value < node->right->value) {
        // right-left rotation
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void avl_tree_insert(avl_tree_t *avl_tree, int value) {
    if (avl_tree == NULL) return;

    node_t *new_node = node_init(value);
    if (avl_tree->root == NULL) {
        avl_tree->root = new_node;
        return;
    }

    avl_tree->root = node_insert(avl_tree->root, new_node);
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

        if (node->left == NULL || node->right == NULL) {
            // Only 1 child or no children
            node_t* temp = node->left ? node->left : node->right;

            // If no children
            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }
            free(temp);
        } else {
            // Case when node has 2 chidlren
            node_t* successor = node_min(node->right, NULL);
            node->value = successor->value;
            node->right = delete_node(node->right, successor->value);
        }
    }

    if (node == NULL) {
        // No children
        return node;
    }

    // Update node height
    node->height = 1 + max(node_height(node->left), node_height(node->right));

    // Check if node is unbalanced
    int diff = node_balance(node);

    if (diff > 1 && node_balance(node->left) >= 0) {
        // left-left rotation
        return right_rotate(node);
    }

    if (diff > 1 && node_balance(node->left) < 0) {
        // left-right rotation
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (diff < -1 && node_balance(node->right) <= 0) {
        // right-right rotation
        return left_rotate(node);
    }

    if (diff < -1 && node_balance(node->right) > 0) {
        // right-left rotation
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void avl_tree_delete(avl_tree_t *avl_tree, int value) {
    // If no root can't delete anything
    if (avl_tree == NULL || avl_tree->root == NULL) return;

    avl_tree->root = delete_node(avl_tree->root, value);
}

int avl_tree_min(avl_tree_t *avl_tree) {
    if (avl_tree == NULL) return 0;

    node_t *node = node_min(avl_tree->root, NULL);
    if (node == NULL) {
        return 0;
    }

    return node->value;
}

int avl_tree_max(avl_tree_t *avl_tree) {
    if (avl_tree == NULL) return 0;

    node_t *node = node_max(avl_tree->root, NULL);
    if (node == NULL) {
        return 0;
    }

    return node->value;
}

void avl_tree_print(avl_tree_t *avl_tree) {
    if (avl_tree == NULL) return;

    node_print(avl_tree->root);
}

node_t *avl_tree_find(avl_tree_t *avl_tree, int value, node_t **parent) {
    if (avl_tree == NULL) return NULL;

    node_t *parent_p = NULL;
    node_t *node = avl_tree->root;
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
    node->height = 1;

    return node;
}

void node_free(node_t *node) {
    if (node == NULL) return;

    node->left = NULL;
    node->right = NULL;
    node->value = 0;
    node->height = 0;
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

int node_height(node_t *node) {
    if (node == NULL) return 0;

    return node->height;
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
