#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>

linked_list_t *ll_new() {
    // Alloc linked list and set first to null
    linked_list_t *ll = malloc(sizeof(linked_list_t));
    ll->length = 0;
    ll->first = NULL;
    ll->last = NULL;
    return ll;
}

void ll_print(linked_list_t *ll) {
    if (ll == NULL) return;

    linked_list_node_t *current = ll->first;
    printf("[");
    while (current != NULL) {
        printf("%d%s", current->value, current->next == NULL ? "" : ", ");
        current = current->next;
    }
    printf("]\n");
}

linked_list_node_t *ll_get_at(linked_list_t *ll, int index) {
    if (ll == NULL) return NULL;
    if (index >= ll->length || index < 0) return NULL;

    // Check if first or last
    if (index == 0) {
        return ll->first;
    } else if (index == ll->length - 1) {
        return ll->last;
    }

    // Check if faster starting from last
    linked_list_node_t *node;
    if (index > ll->length / 2) {
        // Start from last
        int i = ll->length - 2;
        node = ll->last->previous;
        while (node != NULL && i != index) {
            node = node->previous;
            i--;
        }
    } else {
        // Start from first
        int i = 1;
        node = ll->first->next;
        while (node != NULL && i != index) {
            node = node->next;
            i++;
        }
    }

    return node;
}

void ll_set_at(linked_list_t *ll, int index, int value) {
    if (ll == NULL) return;
    if (index >= ll->length || index < 0) return;

    // Check if first or last
    if (index == 0) {
        ll->first->value = value;
        return;
    } else if (index == ll->length - 1) {
        ll->last->value = value;
        return;
    }

    // Check if faster starting from last
    linked_list_node_t *node;
    if (index > ll->length / 2) {
        // Start from last
        int i = ll->length - 2;
        node = ll->last->previous;
        while (node != NULL && i != index) {
            node = node->previous;
            i--;
        }
    } else {
        // Start from first
        int i = 1;
        node = ll->first->next;
        while (node != NULL && i != index) {
            node = node->next;
            i++;
        }
    }

    // Assign value if node was found
    if (node != NULL) {
        node->value = value;
    }
}

void ll_append(linked_list_t *ll, int value) {
    if (ll == NULL) return;

    // Create new node and set values
    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
    node->value = value;
    node->previous = NULL;
    node->next = NULL;

    // Check if it's the first item
    if (ll->first == NULL) {
        // First item
        ll->first = node;
        ll->last = node;
        ll->length++;
        return;
    }

    // Set current last's next
    ll->last->next = node;

    // Set new node's previous
    node->previous = ll->last;

    // Change list attributes
    ll->last = node;
    ll->length++;
}

void ll_insert(linked_list_t *ll, int index, int value) {
    if (ll == NULL) return;
    if (index >= ll->length || index < 0) return;

    // Create new node and set values
    linked_list_node_t *node = malloc(sizeof(linked_list_node_t));
    node->value = value;
    node->previous = NULL;
    node->next = NULL;

    // Check if first or last
    if (index == 0) {
        node->next = ll->first;
        ll->first = node;
        // Set last if was empty
        if (ll->length == 0) {
            ll->last = node;
        }
        ll->length++;
        return;
    } else if (index == ll->length - 1) {
        node->previous = ll->last;
        ll->last = node;
        // Set first if was empty
        if (ll->length == 0) {
            ll->first = node;
        }
        ll->length++;
        return;
    }

    // Check if faster starting from last
    linked_list_node_t *current;
    if (index > ll->length / 2) {
        // Start from last
        int i = ll->length - 2;
        current = ll->last->previous;
        while (i != index) {
            current = current->previous;
            i--;
        }
    } else {
        // Start from first
        int i = 1;
        current = ll->first->next;
        while (i != index) {
            current = current->next;
            i++;
        }
    }

    // if (current != NULL) {
        // Connect previous and new nodes
        current->previous->next = node;
        node->previous = current->previous;

        // Connect new and current nodes
        current->previous = node;
        node->next = current;

        // Increase length
        ll->length++;
    // }
}

linked_list_node_t *ll_pop(linked_list_t *ll) {
    if (ll == NULL) return NULL;

    // Check if list is empty
    if (ll->first == NULL) {
        return NULL;
    }
    
    // Go to last value
    linked_list_node_t *last = ll->first;
    linked_list_node_t *current = last->next;

    // Check if list has only one value
    if (current == NULL) {
        ll->first = NULL;
        ll->last = NULL;
        ll->length = 0;

        return last;
    }

    while (current->next != NULL) {
        last = current;
        current = current->next;
    }

    // Remove reference to popped node
    last->next = NULL;

    // Change list attributes
    ll->last = last;
    ll->length--;

    // Remove references from popped node
    current->previous = NULL;
    return current;
}

int ll_count(linked_list_t *ll, int value) {
    if (ll == NULL) return -1;

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

linked_list_node_t *ll_find(linked_list_t *ll, int value) {
    if (ll == NULL) return NULL;

    linked_list_node_t *current = ll->first;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
}
