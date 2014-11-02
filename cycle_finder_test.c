#include <stdio.h>

#include "permutation_iterator.h"
#include "mixed_radix.h"

int check_suffix_adjacency(struct permutation_iterator * p, int k) {
    int n = p->how_many_elements;
    int u;
    int v;

    if (k >= n - 1) {
        return 1;
    }
    u = p->elements[k];
    v = p->elements[k + 1];
    if ((u == 0 && v == 2) || (u == 2 && v == 0)) {
        return 0;
    }
    if ((u == 1 && v == 3) || (u == 3 && v == 1)) {
        return 0;
    }
    return 1;
}

int main() {
    int n = 4;
    struct permutation_iterator * p;

    printf("Constructing a new permutation iterator.\n");
    p = new_permutation_iterator(n);
    if (!p) {
        printf("Couldn't construct a new permutation iterator.\n");
        exit(1);
    }
    p->valid_suffix = &check_suffix_adjacency;
    permutation_iterator_visit_valid(p, &print_permutation_iterator);
}
