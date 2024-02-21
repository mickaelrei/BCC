#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>

linked_list_t *ll_new() {
    // Alloc linked list and set first to null
    linked_list_t *ll = malloc(sizeof(linked_list_t));
    ll->length = 0;
    ll->first = NULL;
    return ll;
}

void ll_append(linked_list_t *ll, int value) {
    // Create new node and set values
    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
    node->value = value;
    node->next = NULL;

    // Check if it's the first item
    if (ll->first == NULL) {
        // First item
        ll->first = node;
        ll->length++;
        return;
    }

    // Get to end of list
    linked_list_node_t *current = ll->first;
    while (current->next != NULL) {
        current = current->next;
    }

    // Set next node
    current->next = node;
    ll->length++;
}

linked_list_node_t *ll_pop(linked_list_t *ll) {
    // Check if list is empty
    if (ll->first == NULL) {
        return NULL;
    }
    
    // Go to last value
    linked_list_node_t *last = ll->first;
    linked_list_node_t *current = last->next;

    // Check if list has only one value
    if (current == NULL) {
        last->next = NULL;
        ll->length--;
    }
    // while (1) {
    //     if (current->next == NULL) {
    //         last->next = NULL;
    //         return current;
    //     }
    //     last = current;
    //     current = current->next;
    // }

    while (current->next != NULL) {
        last = current;
        current = current->next;
    }

    last->next = NULL;
    ll->length--;
    return current;
}

int ll_count(linked_list_t *ll, int value) {
    int count = 0;

    linked_list_node_t *current = ll->first;
    while (current != NULL) {
        if (current->value == value) {
            count++;
        }
        current = current->next;
    }

    return count;
}

void ll_print(linked_list_t *ll) {
    linked_list_node_t *current = ll->first;
    printf("[");
    while (current != NULL) {
        printf("%d%s", current->value, current->next == NULL ? "" : ", ");
        current = current->next;
    }
    printf("]\n");
}