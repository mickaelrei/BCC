#define CHILDREN_COUNT 26

/// @brief Node of a trie tree
typedef struct trie_node {
    /// @brief Whether this node represents the end of a word
    int isEnd;

    /// @brief List of children nodes
    struct trie_node* children[CHILDREN_COUNT];
} trie_node_t;

/// @brief Create and initialize a new trie node
/// @return new trie node
trie_node_t *trie_node_init();

/// @brief Inserts a word on a trie tree
/// @param root root of trie tree
/// @param word word to insert
void trie_tree_insert(trie_node_t *root, const char *word);

/// @brief Searches a word on a trie tree
/// @param root root of trie tree
/// @param word word to search
/// @return 1 if found, 0 otherwise
int trie_tree_search(trie_node_t *root, const char *word);

/// @brief Frees an existent trie tree
/// @param root root of trie tree
void trie_tree_free(trie_node_t *root);