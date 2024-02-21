#include <stdio.h>
#include <linked_list.h>

int main(int argc, char **argv) {
    linked_list_t *ll = ll_new();

    ll_append(ll, 4);
    ll_append(ll, 2);
    ll_append(ll, 1);
    ll_append(ll, 9);
    ll_append(ll, 4);

    ll_print(ll);

    printf("4 appeared %d times in ll (length: %d)\n", ll_count(ll, 4), ll->length);

    linked_list_node_t *last = ll_pop(ll);
    if (last != NULL) {
        printf("popped %d\n", last->value);
    } else {
        printf("list was empty!\n");
    }

    printf("4 appeared %d times in ll (length: %d)\n", ll_count(ll, 4), ll->length);

    ll_print(ll);

    while (ll->length > 0) {
        linked_list_node_t *node = ll_pop(ll);
        if (node != NULL) {
            printf("popped %d\n", node->value);
        }
    }

    return 0;
}