#include <stdio.h>

#include "cayley.h"
#include "permutation_iterator.h"
#include "mixed_radix.h"

int N;

char ** vertices;

int DEBUG = 1;

int how_many_found = 0;

char * vertices_3[] = {
    "012",
    "102",
    "021",
    "201",
    "120",
    "210"
};

char * vertices_4[] = {
    "0123",
    "1023",
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

int check_adjacency(struct permutation_iterator * p, int k) {
    int n = p->how_many_elements;
    int u_index;
    int v_index;
    char * u;
    char * v;
    int d; // Will hold the delta number (for display purposes)

    u_index = p->elements[k] + 1;
    u = vertices[u_index];
    if (k >= n - 1) { // 1-element suffixes always valid.
        v = vertices[0];
        return cayley_adjacent(u, v, N, &d);
    }
    v_index = p->elements[k + 1] + 1;
    v = vertices[v_index];
    if (!cayley_adjacent(u, v, N, &d)) {
        return 0;
    }
    if (k == 1) { // Need to also check against first element
        if (!cayley_adjacent(vertices[p->elements[0] + 1], u, N, &d)) {
            return 0;
        }
        if (!cayley_adjacent(vertices[0], vertices[p->elements[0] + 1], N, &d)) {
            return 0;
        }
    }
    return 1;
}


void show_vertices(struct permutation_iterator * p) {
    int i;
    int d;
    int u_index;
    int v_index;
    char * u;
    char * v;

    // Show delta-sequence.
    printf("________________________________________\n\n");
    u = vertices[0];
    v = vertices[p->elements[0] + 1];
    cayley_adjacent(u, v, N, &d);
    printf("%d ", d);
    for (i = 0; i < p->how_many_elements; i++) {
        u_index = p->elements[i] + 1;
        if (i == p->how_many_elements - 1) {
            v_index = 0;
        }
        else {
            v_index = p->elements[i + 1] + 1;
        }
        u = vertices[u_index];
        v = vertices[v_index];
        cayley_adjacent(u, v, N, &d);
        printf("%d ", d);
    }
    printf("\n\n");

    if (DEBUG) {

        // Show vertex-sequence.
        printf("%-4d %s\n", 0, vertices[0]);
        for (i = 0; i < p->how_many_elements; i++) {
            printf("%-4d %s\n", p->elements[i] + 1, vertices[p->elements[i] + 1]);
        }
    }

    printf("----------------------------------------\n\n");
    how_many_found += 1;
}

int main(int argc, char * argv[]) {
    char * n_string;
    int n_factorial;
    struct permutation_iterator * p;

    if (argc < 2) {
        printf("Need to provide argument for N: either 3 or 4\n");
        exit(1);
    }
    if (argc > 2) {
        printf("Too many arguments, can only provide one argument for N: either 3 or 4\n");
        exit(1);
    }
    n_string = argv[1];
    N = atoi(n_string);
    if (N == 3) {
        vertices = vertices_3;
        n_factorial = 6;
    }
    else if (N == 4) {
        vertices = vertices_4;
        n_factorial = 24;
    }
    else {
        printf("Not guaranteed to work for N = %d\n", N);
    }
    printf("about to search for cycles in the cayley graph on S_%d\n", N);
    p = new_permutation_iterator(n_factorial - 1);
    p->valid_suffix = &check_adjacency;
    if (!p) {
        printf("Could not construct a new permutation iterator.\n");
        exit(1);
    }
    permutation_iterator_visit_valid(p, &show_vertices);
    printf("Found %d valid cycles\n", how_many_found);
    
}
