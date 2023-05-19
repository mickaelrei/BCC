#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula *le_create() {
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;

    return le;
}

int le_len(celula *le) {
    if (le == NULL)
        return -1;
    
    int i = 0;
    celula *p = le->prox;
    while (p != NULL) {
        p = p->prox;
        i++;
    }

    return i;
}

int le_index(celula *le, int value, int start) {
    if (le == NULL || start < 0 || start >= le_len(le))
        return -1;

    int i = 0, achou = 0;
    celula *p = le->prox;
    while (p != NULL) {
        if (i >= start && p->conteudo == value) {
            achou = 1;
            break;
        }
        p = p->prox;
        i++;
    }

    if (achou) return i;
    else return -1;
}

celula *le_get_at(celula *le, int index) {
    if (index < 0 || le == NULL)
        return NULL;
        
    int i = 0;
    celula *p = le->prox;

    while (p != NULL && i != index) {
        p = p->prox;
        i++;
    }

    return p;
}

void le_print(celula *le) {
    if (le == NULL)
        return;

    celula *p;
    for (p = le->prox; p != NULL; p = p->prox) {
        printf("%d", p->conteudo);
        if (p->prox != NULL)
            printf(", ");
    }
    
    printf("\n");
}

void le_append(celula *le, int value) {
    if (le == NULL)
        return;

    celula *p;
    p = malloc(sizeof(celula));
    p->conteudo = value;
    p->prox = NULL;

    celula *p1 = le;
    while (p1->prox != NULL)
        p1 = p1->prox;


    p1->prox = p;
}

void le_insert(celula *le, int pos, int value) {
    if (le == NULL || pos < 0 || pos > le_len(le))
        return;

    if (pos == le_len(le)) {
        le_append(le, value);
        return;
    }

    celula *p = malloc(sizeof(celula));
    p->conteudo = value;

    // Atual e anterior
    celula *curr = le_get_at(le, pos);
    celula *prev;
    if (pos == 0)
        prev = le;
    else
        prev = le_get_at(le, pos - 1);

    prev->prox = p;
    p->prox = curr;
}

celula *le_find(celula *le, int value) {
    if (le == NULL)
        return NULL;

    celula *p = le->prox;
    while (p != NULL && p->conteudo != value)
        p = p->prox;
    
    return p;
}

void le_remove(celula *le, int value) {
    if (le == NULL)
        return;
        
    celula *p, *q;
    p = le;
    q = le->prox;
    while (q != NULL && q->conteudo != value) {
        p = q;
        q = q->prox;
    }
    if (q != NULL) {
        p->prox = q->prox;
        free(q);
    }
}

void le_swap(celula *le, int pos0, int pos1) {
    if (pos0 == pos1 || le == NULL)
        return;
    
    celula *p0 = le_get_at(le, pos0);
    celula *p1 = le_get_at(le, pos1);

    if (p0 == NULL || p1 == NULL)
        return;

    celula *p0_prev = le_get_at(le, pos0 - 1);
    celula *p1_prev = le_get_at(le, pos1 - 1);
    celula *p0_prox = p0->prox;
    celula *p1_prox = p1->prox;
    int colados = abs(pos0 - pos1) == 1;

    // Se pos0 ou pos1 forem zero, o anterior do mesmo
    // deve ser a cabeça da lista
    if (pos0 == 0)
        p0_prev = le;
    else if (pos1 == 0)
        p1_prev = le;

    // A ordem de mudança de endereços é diferente se pos0 < pos1 ou pos0 > pos1
    if (pos0 < pos1) {
        p0_prev->prox = p1;
        p1->prox = colados ? p0 : p0->prox;
        p1_prev->prox = p0;
        p0->prox = p1_prox;
    } else {
        p1_prev->prox = p0;
        p0->prox = colados ? p1 : p1->prox;
        p0_prev->prox = p1;
        p1->prox = p0_prox;
    }
}

void le_clear(celula *le) {
    if (le == NULL)
        return;

    celula *p = le->prox;
    if (p == NULL)
        return;

    le->conteudo = 0;
    le->prox = NULL;
    free(le->prox);
    le_clear(p);
}

void le_bubblesort(celula *le) {
    if (le == NULL)
        return;
    
    int size = le_len(le);
    for (int i = size; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (le_get_at(le, j)->conteudo > le_get_at(le, j + 1)->conteudo)
                le_swap(le, j, j + 1);
        }
    }
}

int random(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void main() {
    srand(time(NULL));

    // Cria lista encadeada vazia
    celula *le = le_create();

    // Insere valores aleatórios
    for (int i = 0; i < 10; i++) {
        le_append(le, random(-15, 15));
        le_insert(le, 0, i);
    }

    // Mostra a lista original
    le_print(le);
    printf("Tamanho: %d\n", le_len(le));

    // le_insert(le, 2, 15);

    // Ordena
    le_bubblesort(le);

    // Mostra a lista ordenada
    le_print(le);
    printf("Tamanho: %d\n", le_len(le));

    // Limpa
    le_clear(le);
    printf("Cleared\n");
    printf("Tamanho: %d\n", le_len(le));
    free(le);
}