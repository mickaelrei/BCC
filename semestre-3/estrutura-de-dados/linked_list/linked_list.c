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

void ll_free(linked_list_t *ll) {
    if (ll == NULL) return;

    // Check if empty
    if (ll->first == NULL) {
        ll->first = NULL;
        ll->last = NULL;
        ll->length = 0;
        free(ll);
        return;
    }

    // Free all nodes
    linked_list_node_t *last = ll->first;
    linked_list_node_t *current = last->next;
    while (current != NULL) {
        last->previous = NULL;
        last->next = NULL;
        last->value = 0;
        free(last);
        last = current;
        current = current->next;
    }
    // Free last node
    last->previous = NULL;
    last->next = NULL;
    last->value = 0;
    free(last);

    // Free list
    ll->first = NULL;
    ll->last = NULL;
    ll->length = 0;
    free(ll);
}

void ll_node_free(linked_list_node_t *node) {
    if (node == NULL) return;
    node->next = NULL;
    node->previous = NULL;
    node->value = 0;
    free(node);
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

    // Connect previous and new nodes
    current->previous->next = node;
    node->previous = current->previous;

    // Connect new and current nodes
    current->previous = node;
    node->next = current;

    // Increase length
    ll->length++;
}

linked_list_node_t *ll_remove(linked_list_t *ll, int index) {
    if (ll == NULL) return NULL;

    if (index >= ll->length || index < 0) return NULL;

    // Check if first or last
    if (index == 0) {
        linked_list_node_t *node = ll->first;
        ll->first = ll->first->next;
        // Second value's "previous" needs to be set to null
        if (ll->first->next != NULL) {
            ll->first->next->previous = NULL;
        }
        node->previous = NULL;
        node->next = NULL;
        ll->length--;
        return node;
    } else if (index == ll->length - 1) {
        linked_list_node_t *node = ll->last;
        ll->last = ll->last->previous;
        // Second-to-last value's "next" needs to be set to null
        if (ll->last->previous != NULL) {
            ll->last->previous->next = NULL;
        }
        node->previous = NULL;
        node->next = NULL;
        ll->length--;
        return node;
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

    // Connect previous to next
    current->previous->next = current->next;
    current->next->previous = current->previous;

    // Set current references to null
    current->previous = NULL;
    current->next = NULL;
    ll->length--;
    return current;
}

linked_list_node_t *ll_pop(linked_list_t *ll) {
    if (ll == NULL) return NULL;

    // Check if list is empty
    if (ll->first == NULL) return NULL;

    // Check if only one element
    if (ll->first->next == NULL) {
        // Get last node
        linked_list_node_t *node = ll->first;
        
        // Change list attributes
        ll->first = NULL;
        ll->last = NULL;
        ll->length--;

        return node;        
    }

    // Get last node
    linked_list_node_t *last = ll->last;

    // Remove reference from second-to-last node and set new last
    last->previous->next = NULL;
    ll->last = last->previous;
    ll->length--;

    // Remove reference from returned node
    last->previous = NULL;
    return last;
}

void ll_clear(linked_list_t *ll) {
    if (ll == NULL) return;

    while (ll->length > 0) {
        linked_list_node_t *node = ll_pop(ll);
        ll_node_free(node);
    }
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

int ll_find(linked_list_t *ll, int value) {
    if (ll == NULL) return -1;

    int i = 0;
    linked_list_node_t *current = ll->first;
    while (current != NULL) {
        if (current->value == value) break;

        current = current->next;
        i++;
    }

    return i;
}

void ll_swap(linked_list_t *ll, int index0, int index1) {
    if (ll == NULL) return;

    // Check if out of bounds or same index
    if (index0 >= ll->length || index0 < 0 || index1 >= ll->length || index1 < 0 || index0 == index1) return;

    // Get nodes at indexes
    linked_list_node_t *node0 = ll_get_at(ll, index0);
    linked_list_node_t *node1 = ll_get_at(ll, index1);
    if (node0 == NULL || node1 == NULL) return;

    // Swap values
    int temp = node0->value;
    node0->value = node1->value;
    node1->value = temp;
}

void ll_node_swap(linked_list_t *ll, linked_list_node_t *node0, linked_list_node_t *node1) {
    if (ll == NULL || node0 == NULL || node1 == NULL) return;

    int temp = node0->value;
    node0->value = node1->value;
    node1->value = temp;
}

void ll_selection_sort(linked_list_t *ll) {
    if (ll == NULL || ll->length == 0) return;

    // Traverse through list
    linked_list_node_t *node0 = ll->first;
    for (int i = 0; i < ll->length; i++) {
        linked_list_node_t *node1 = node0->next;

        // Min value node
        linked_list_node_t *node_min = NULL;
        for (int j = i + 1; j < ll->length; j++) {
            // Check if less than min node
            if (node1->value < node0->value) {
                node_min = node1;
            }
            node1 = node1->next;
        }

        // Swap
        ll_node_swap(ll, node0, node_min);
        node0 = node0->next;
    }
}
