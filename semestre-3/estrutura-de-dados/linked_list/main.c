#include <stdio.h>
#include <linked_list.h>


int main(int argc, char **argv) {
    printf("start\n");
    linked_list_t *ll = ll_new();

    printf("\nappending\n----------\n");
    ll_append(ll, 2);
    ll_append(ll, 4);
    ll_append(ll, 6);
    ll_append(ll, 8);
    ll_append(ll, 10);

    ll_print(ll);

    printf("4 appeared %d times in ll (length: %d)\n", ll_count(ll, 4), ll->length);

    ll_insert(ll, 2, -50);
    ll_insert(ll, 4, -70);

    printf("\nGoing from start\n------------\n");
    int i = 0;
    linked_list_node_t *node = ll->first;
    while (node != NULL) {
        printf("ll[%d] = %d\n", i, node->value);
        i++;
        node = node->next;
    }

    printf("\n\nComing from end\n-----------\n");
    i = ll->length - 1;
    node = ll->last;
    while (node != NULL) {
        printf("ll[%d] = %d\n", i, node->value);
        i--;
        node = node->previous;
    }

    printf("\n\nUsing ll_get_at()\n----------\n");
    for (int i = 0; i <= ll->length; i++) {
        linked_list_node_t *node = ll_get_at(ll, i);
        if (node == NULL) {
            printf("ll[%d] = NULL\n", i);
        } else {
            printf("ll[%d] = %d\n", i, node->value);
        }
    }

    printf("\nll_pop()\n--------\n");
    linked_list_node_t *last = ll_pop(ll);
    if (last != NULL) {
        printf("popped %d, previous: %p, next: %p\n", last->value, last->previous, last->next);
        ll_node_free(last);
        last = NULL;
    } else {
        printf("list was empty!\n");
    }

    printf("\nll_count()\n----------\n");
    printf("4 appeared %d times in ll (length: %d)\n", ll_count(ll, 4), ll->length);
    ll_print(ll);

    printf("\nll_pop() until empty\n------------\n");
    while (ll->length > 0) {
        linked_list_node_t *node = ll_pop(ll);
        if (node != NULL) {
            printf("popped %d\n", node->value);
            ll_node_free(node);
            node = NULL;
        }
        ll_print(ll);
    }

    printf("\nll_free()\n");
    ll_free(ll);
    ll = NULL;
    printf("\nDone\n");

    return 0;
}