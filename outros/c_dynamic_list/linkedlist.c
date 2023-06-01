#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct reg {
    int value;
    struct reg *next;
} cell;

cell *ll_create() {
    cell *ll = malloc(sizeof(cell));
    ll->next = NULL;

    return ll;
}

int ll_len(cell *ll) {
    if (ll == NULL)
        return -1;
    
    int i = 0;
    cell *p = ll->next;
    while (p != NULL) {
        p = p->next;
        i++;
    }

    return i;
}

int ll_index(cell *ll, int value, int start) {
    if (ll == NULL || start < 0 || start >= ll_len(ll))
        return -1;

    int i = 0, found = 0;
    cell *p = ll->next;
    while (p != NULL) {
        if (i >= start && p->value == value) {
            found = 1;
            break;
        }
        p = p->next;
        i++;
    }

    if (found) return i;
    else return -1;
}

cell *ll_get_at(cell *ll, int index) {
    if (index < 0 || ll == NULL)
        return NULL;
        
    int i = 0;
    cell *p = ll->next;

    while (p != NULL && i != index) {
        p = p->next;
        i++;
    }

    return p;
}

void ll_set_at(cell *ll, int index, int value) {
    ll_get_at(ll, index)->value = value;
}

void ll_print(cell *ll) {
    if (ll == NULL)
        return;

    printf("[");
    cell *p;
    for (p = ll->next; p != NULL; p = p->next) {
        printf("%d", p->value);
        if (p->next != NULL)
            printf(", ");
    }
    
    printf("]\n");
}

void ll_append(cell *ll, int value) {
    if (ll == NULL)
        return;

    cell *p;
    p = malloc(sizeof(cell));
    p->value = value;
    p->next = NULL;

    cell *p1 = ll;
    while (p1->next != NULL)
        p1 = p1->next;


    p1->next = p;
}

void ll_insert(cell *ll, int pos, int value) {
    if (ll == NULL || pos < 0 || pos >= ll_len(ll))
        return;

    if (pos == ll_len(ll)) {
        ll_append(ll, value);
        return;
    }

    cell *p = malloc(sizeof(cell));
    p->value = value;

    // Current and previous
    cell *curr = ll_get_at(ll, pos);
    cell *prev;
    if (pos == 0)
        prev = ll;
    else
        prev = ll_get_at(ll, pos - 1);

    prev->next = p;
    p->next = curr;
}

cell *ll_find(cell *ll, int value, int start) {
    if (ll == NULL || start < 0 || start >= ll_len(ll))
        return NULL;

    cell *p = ll->next;
    int i = 0;
    while (p != NULL && (p->value != value || i < start)) {
        p = p->next;
        i++;
    }
    
    return p;
}

void ll_remove(cell *ll, int pos) {
    if (ll == NULL || pos < 0 || pos >= ll_len(ll))
        return;

    cell *p, *q;
    p = ll;
    q = ll->next;
    int i = 0;
    while (q != NULL && i != pos) {
        p = q;
        q = q->next;
        i++;
    }

    if (q != NULL) {
        p->next = q->next;
        free(q);
    }
}

cell *ll_slice(cell *ll, int start, int size) {
    int len = ll_len(ll);
    if (ll == NULL || start < 0 || start >= len)
        return NULL;

    cell *new_ll = ll_create();

    size = fmin(size, len - start);

    if (size == 0)
        return new_ll;

    cell *st = ll_get_at(ll, start);
    for (int i = 0; i < size; i++) {
        ll_append(new_ll, st->value);
        st = st->next;
    }

    return new_ll;
}

void ll_swap(cell *ll, int pos0, int pos1) {
    if (pos0 == pos1 || ll == NULL)
        return;
    
    cell *p0 = ll_get_at(ll, pos0);
    cell *p1 = ll_get_at(ll, pos1);

    if (p0 == NULL || p1 == NULL)
        return;

    cell *p0_prev = ll_get_at(ll, pos0 - 1);
    cell *p1_prev = ll_get_at(ll, pos1 - 1);
    cell *p0_next = p0->next;
    cell *p1_next = p1->next;
    int close = abs(pos0 - pos1) == 1;

    // Se pos0 ou pos1 forem zero, o anterior do mesmo
    // deve ser a cabeça da lista
    if (pos0 == 0)
        p0_prev = ll;
    else if (pos1 == 0)
        p1_prev = ll;

    // A ordem de mudança de endereços é diferente se pos0 < pos1 ou pos0 > pos1
    if (pos0 < pos1) {
        p0_prev->next = p1;
        p1->next = close ? p0 : p0->next;
        p1_prev->next = p0;
        p0->next = p1_next;
    } else {
        p1_prev->next = p0;
        p0->next = close ? p1 : p1->next;
        p0_prev->next = p1;
        p1->next = p0_next;
    }
}

void ll_clear(cell *ll) {
    if (ll == NULL)
        return;

    cell *p = ll->next;
    if (p == NULL)
        return;

    ll->value = 0;
    ll->next = NULL;
    ll_clear(p);
    free(ll->next);
}

void ll_bubblesort(cell *ll) {
    if (ll == NULL)
        return;
    
    int size = ll_len(ll);
    for (int i = size; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (ll_get_at(ll, j)->value > ll_get_at(ll, j + 1)->value)
                ll_swap(ll, j, j + 1);
        }
    }
}

int random(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void main() {
    srand(time(NULL));

    // Cria lista encadeada vazia
    cell *ll = ll_create();

    // Insere valores aleatórios
    for (int i = 0; i < 10; i++) {
        ll_append(ll, random(-15, 15));
    }

    // Mostra a lista original
    ll_print(ll);
    printf("Tamanho: %d\n\n", ll_len(ll));

    // Cria slice
    cell *slice = ll_slice(ll, 8, 18);
    ll_print(slice);
    printf("Tamanho slice: %d\n", ll_len(slice));

    // Limpa
    ll_clear(ll);
    printf("\nCleared\n");
    printf("Tamanho: %d\n", ll_len(ll));
    free(ll);

    ll_clear(slice);
    free(slice);
}