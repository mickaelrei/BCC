typedef struct node {
    struct node *left;
    struct node *right;
    int value;
    int height;
} node_t;

typedef struct avl_tree {
    node_t *root;
} avl_tree_t;

/// @brief Create and initialize new binary tree
/// @return Binary tree initialized
avl_tree_t *avl_tree_init();

/// @brief Frees a binary tree
/// @param avl_tree binary tree to be freed
void avl_tree_free(avl_tree_t *avl_tree);

/// @brief Get a binary tree's height
/// @param avl_tree binary tree to check
/// @return The binary tree's height
size_t avl_tree_height(avl_tree_t *avl_tree);

/// @brief Insert new value into a binary tree
/// @param avl_tree binary tree to insert
/// @param value value to be inserted
void avl_tree_insert(avl_tree_t *avl_tree, int value);

/// @brief Deletes a value in a binary tree, if found
/// @param avl_tree binary tree to check
/// @param value value to delete
void avl_tree_delete(avl_tree_t *avl_tree, int value);

/// @brief Get the minimum value of a binary tree
/// @param avl_tree binary tree to check
/// @return Tree minimum value
int avl_tree_min(avl_tree_t *avl_tree);

/// @brief Get the maximum value of a binary tree
/// @param avl_tree binary tree to check
/// @return Tree maximum value
int avl_tree_max(avl_tree_t *avl_tree);

/// @brief Print a binary tree
/// @param avl_tree binary tree to be printed
void avl_tree_print(avl_tree_t *avl_tree);

/// @brief Attempts to find a value in a binary tree
/// @param avl_tree binary tree to check
/// @param value value to find
/// @param parent optional output parent node value (set to NULL if not found)
/// @return Node if found, NULL otherwise
node_t *avl_tree_find(avl_tree_t *avl_tree, int value, node_t **parent);