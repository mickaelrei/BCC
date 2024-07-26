typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} node_t;

typedef struct btree {
    node_t *root;
} btree_t;

/// @brief Create and initialize new binary tree
/// @return Binary tree initialized
btree_t *btree_init();

/// @brief Frees a binary tree
/// @param btree binary tree to be freed
void btree_free(btree_t *btree);

/// @brief Get a binary tree's height
/// @param btree binary tree to check
/// @return The binary tree's height
size_t btree_height(btree_t *btree);

/// @brief Insert new value into a binary tree
/// @param btree binary tree to insert
/// @param value value to be inserted
void btree_insert(btree_t *btree, int value);

/// @brief Deletes a value in a binary tree, if found
/// @param btree binary tree to check
/// @param value value to delete
void btree_delete(btree_t *btree, int value);

/// @brief Get the minimum value of a binary tree
/// @param btree binary tree to check
/// @return Tree minimum value
int btree_min(btree_t *btree);

/// @brief Get the maximum value of a binary tree
/// @param btree binary tree to check
/// @return Tree maximum value
int btree_max(btree_t *btree);

/// @brief Print a binary tree
/// @param btree binary tree to be printed
void btree_print(btree_t *btree);

/// @brief Pretty prints a binary tree
/// @param btree binary tree to be printed
void btree_pretty_print(btree_t *btree);

/// @brief Attempts to find a value in a binary tree
/// @param btree binary tree to check
/// @param value value to find
/// @param parent optional output parent node value (set to NULL if not found)
/// @return Node if found, NULL otherwise
node_t *btree_find(btree_t *btree, int value, node_t **parent);