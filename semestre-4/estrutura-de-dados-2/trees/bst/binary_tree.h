typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} node_t;

typedef struct bin_tree {
    node_t *root;
} bin_tree_t;

/// @brief Create and initialize new binary tree
/// @return Binary tree initialized
bin_tree_t *bin_tree_init();

/// @brief Frees a binary tree
/// @param bin_tree binary tree to be freed
void bin_tree_free(bin_tree_t *bin_tree);

/// @brief Get a binary tree's height
/// @param bin_tree binary tree to check
/// @return The binary tree's height
size_t bin_tree_height(bin_tree_t *bin_tree);

/// @brief Insert new value into a binary tree
/// @param bin_tree binary tree to insert
/// @param value value to be inserted
void bin_tree_insert(bin_tree_t *bin_tree, int value);

/// @brief Deletes a value in a binary tree, if found
/// @param bin_tree binary tree to check
/// @param value value to delete
void bin_tree_delete(bin_tree_t *bin_tree, int value);

/// @brief Get the minimum value of a binary tree
/// @param bin_tree binary tree to check
/// @return Tree minimum value
int bin_tree_min(bin_tree_t *bin_tree);

/// @brief Get the maximum value of a binary tree
/// @param bin_tree binary tree to check
/// @return Tree maximum value
int bin_tree_max(bin_tree_t *bin_tree);

/// @brief Print a binary tree
/// @param bin_tree binary tree to be printed
void bin_tree_print(bin_tree_t *bin_tree);

/// @brief Attempts to find a value in a binary tree
/// @param bin_tree binary tree to check
/// @param value value to find
/// @param parent optional output parent node value (set to NULL if not found)
/// @return Node if found, NULL otherwise
node_t *bin_tree_find(bin_tree_t *bin_tree, int value, node_t **parent);