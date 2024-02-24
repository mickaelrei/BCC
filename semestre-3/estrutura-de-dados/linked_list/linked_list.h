#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_node {
    int value;
    struct linked_list_node *previous;
    struct linked_list_node *next;
} linked_list_node_t;

typedef struct linked_list_head {
    int length;
    linked_list_node_t *first;
    linked_list_node_t *last;
} linked_list_t;

// Creates a linked list
linked_list_t *ll_new();

// Frees a linked list and all its current items
void ll_free(linked_list_t *ll);

// Frees a node, generally used on ll_pop()'d nodes
void ll_node_free(linked_list_node_t *node);

// Prints a linked a list
void ll_print(linked_list_t *ll);

// Returns the node at given index, or null if invalid
linked_list_node_t *ll_get_at(linked_list_t *ll, int index);

// Sets the value of node at given index
void ll_set_at(linked_list_t *ll, int index, int value);

// Appends a value at the end of a linked list
void ll_append(linked_list_t *ll, int value);

// Inserts a value at the specified index of a linked list
void ll_insert(linked_list_t *ll, int index, int value);

// Removes the node at the specified index
linked_list_node_t *ll_remove(linked_list_t *ll, int index);

// Removes the last node in a linked list
//
// Returns the removed node, or null if list was empty
linked_list_node_t *ll_pop(linked_list_t *ll);

// Clears a linked list
void ll_clear(linked_list_t *ll);

// Returns how many times a value is in a linked list
int ll_count(linked_list_t *ll, int value);

// Attempts to find a value in a linked list
//
// Returns the index of the first occurrence, or -1 if not found
int ll_find(linked_list_t *ll, int value);

// Attempts to swap two elements at specified indexes
void ll_swap(linked_list_t *ll, int index0, int index1);

// Swaps value of two given nodes
void ll_node_swap(linked_list_t *ll, linked_list_node_t *node0, linked_list_node_t *node1);

// Sorts a linked list using selection sort
void ll_selection_sort(linked_list_t *ll);

#endif // LINKED_LIST_H