#include <stdio.h>

#include "cayley.h"
#include "permutation_iterator.h"
#include "mixed_radix.h"

char* vertices[24] = {
    "0123",
    "0213",
    "2013",
    "1203",
    "2103",
    "0132",
    "1032",
    "0312",
    "3012",
    "1302",
    "3102",
    "0231",
    "2031",
    "0321",
    "3021",
    "2301",
    "3201",
    "1230",
    "2130",
    "1320",
    "3120",
    "2310",
    "3210"
};

char * test_vertices[] = {
    "012",
    "102",
    "021",
    "201",
    "120",
    "210"
};

int test_vertices_strlen = 3;


int check_adjacency(struct permutation_iterator * p, int k) {
    int n = p->how_many_elements;
    int u_index;
    int v_index;
    char * u;
    char * v;

    while (k < n - 2) {
        u_index = p->elements[k];
        v_index = p->elements[k + 1];
        u = test_vertices[u_index];
        v = test_vertices[v_index];
        if (!cayley_adjacent(u, v, test_vertices_strlen)) {
            return 0;
        }
        k += 1;
    }
    return 1;
}

void show_vertices(struct permutation_iterator * p) {
    int i;

    for (i = 0; i < p->how_many_elements; i++) {
        printf("%s\n", test_vertices[p->elements[i]]);
    }
    printf("----------------------------------------\n\n");
}

int main() {
    int n = 3;
    struct permutation_iterator * p;

    printf("about to search for cycles in the cayley graph on S_3\n");
    p = new_permutation_iterator(3 * 2 * 1);
    p->valid_suffix = &check_adjacency;
    if (!p) {
        printf("Could not construct a new permutation iterator.\n");
        exit(1);
    }
    permutation_iterator_visit_valid(p, &print_permutation_iterator);
    //    permutation_iterator_visit_valid(p, &show_vertices);

    
}
