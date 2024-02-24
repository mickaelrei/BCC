#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>
#include <time.h>

int main(int argc, char **argv) {
    time_t t;
    srand((unsigned) time(&t));
    printf("start\n");
    linked_list_t *ll = ll_new();

    // Testing append
    {
        printf("\nappending\n----------\n");
        ll_append(ll, 2);
        ll_append(ll, 4);
        ll_append(ll, 6);
        ll_append(ll, 8);
        ll_append(ll, 10);
        ll_print(ll);
    }

    // Testing insert
    {
        printf("\nll_insert()\n--------\n");
        ll_insert(ll, 2, -50);
        ll_insert(ll, 4, -70);
        ll_insert(ll, ll->length - 1, 15);
        ll_print(ll);
    }

    // Testing swap
    {
        printf("\nll_swap()\n-----------\n");
        ll_swap(ll, 1, 2);
        ll_swap(ll, 3, 2);
        ll_swap(ll, 6, 4);
        ll_swap(ll, 5, 1);
        ll_print(ll);
    }

    // Testing traverse from start to end and from end to start
    {
        printf("\nGoing from start to end\n------------\n");
        int i = 0;
        linked_list_node_t *node = ll->first;
        while (node != NULL) {
            printf("ll[%d] = %d\n", i, node->value);
            i++;
            node = node->next;
        }

        printf("\n\nGoing from end to start\n-----------\n");
        i = ll->length - 1;
        node = ll->last;
        while (node != NULL) {
            printf("ll[%d] = %d\n", i, node->value);
            i--;
            node = node->previous;
        }
    }

    // Testing get
    {
        printf("\n\nUsing ll_get_at()\n----------\n");
        for (int i = 0; i <= ll->length; i++) {
            linked_list_node_t *node = ll_get_at(ll, i);
            if (node == NULL) {
                printf("ll[%d] = NULL\n", i);
            } else {
                printf("ll[%d] = %d\n", i, node->value);
            }
        }
    }

    // Testing remove
    {
        printf("\nll_remove()\n-----------\n");
        int i = 3;
        linked_list_node_t *node = ll_remove(ll, i);
        if (node != NULL) {
            printf("Removed ll[%d] = %d\n", i, node->value);
            ll_print(ll);

            // Free node
            ll_node_free(node);
            node = NULL;
        } else {
            printf("Failed removing node at index %d\n", i);
        }
    }

    // Testing pop
    {
        printf("\nll_pop()\n------------\n");
        linked_list_node_t *node = ll_pop(ll);
        if (node != NULL) {
            printf("popped %d\n", node->value);
            ll_print(ll);

            // Free node
            ll_node_free(node);
            node = NULL;
        }
    }

    // Testing clear
    {
        printf("\nll_clear()\n-----------\n");
        ll_clear(ll);
        printf("ll->length = %d\n", ll->length);
        ll_print(ll);
    }

    
    // Testing selection sort
    {
        printf("\nll_selection_sort()\n-----------\n");
        for (int i = 0; i < 150; i++) {
            int r = rand() % 5;
            ll_append(ll, r);
        }
        ll_print(ll);
        ll_selection_sort(ll);
        ll_print(ll);
    }


    // Testing free
    {
        printf("\nll_free()\n");
        ll_free(ll);
        ll = NULL;
    }

    printf("\nDone\n");

    return 0;
}