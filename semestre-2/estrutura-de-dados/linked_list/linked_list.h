#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_node {
    int value;
    struct linked_list_node *next;
} linked_list_node_t;

typedef struct linked_list_head {
    int length;
    linked_list_node_t *first;
} linked_list_t;

// Creates a linked list
linked_list_t *ll_new();

// Appends a value at the end of a linked list
void ll_append(linked_list_t *ll, int value);

// Removes the last node in a linked list
//
// Returns the removed node, or null if list was empty
linked_list_node_t *ll_pop(linked_list_t *ll);

// Prints a linked a list
void ll_print(linked_list_t *ll);

// Returns how many times a value is in a linked list
int ll_count(linked_list_t *ll, int value);

#endif // LINKED_LIST_H