#include <stdlib.h>
#include <stdio.h>

#include "permutation_iterator.h"
#include "mixed_radix.h"

void permutation_iterator_flip_elements(struct permutation_iterator *, int);

void permutation_iterator_swap_elements(struct permutation_iterator *, int, int);

int n = 0;

struct permutation_iterator * new_permutation_iterator(int n) {
    struct permutation_iterator * new_instance = NULL;
    struct mixed_radix * control = NULL;
    int * elements = NULL;

    control = new_permutation_control(n);
    if (!control) {
        return NULL;
    }
    elements = malloc(n * sizeof(int));
    if (!elements) {
        return NULL;
    }
    new_instance = malloc(sizeof(struct permutation_iterator));
    if (!new_instance) {
        return NULL;
    }
    new_instance->how_many_elements = n;
    new_instance->control = control;
    new_instance->elements = elements;
    new_instance->omega = &default_omega;
    new_instance->tau = &default_tau;
    new_instance->sigma_k_k_inverse = &default_sigma_k_k_inverse;
    new_instance->k = n - 1;
    initialize_permutation_iterator_elements(new_instance);
    return new_instance;
}

void destroy_permutation_iterator(struct permutation_iterator * self) {
    destroy_mixed_radix(self->control);
    free(self->elements);
    free(self);
}

struct permutation_iterator * permutation_iterator_next(struct permutation_iterator * self) {
    int k;
    int j;

    k = increment_mixed_radix(self->control);
    if (k >= self->control->how_many_radices) {
        return NULL;
    }
    j = self->control->c[k];
    (*self->omega)(self, k);
    (*self->tau)(self, k, j);
    self->k = k;
    return self;
}

struct permutation_iterator * permutation_iterator_skip_suffix(struct permutation_iterator * self) {
    int k = self->k;

    while (k) {
        if (permutation_iterator_valid_suffix(self, k)) {
            k = k - 1;
        }
        else {
            if (!permutation_iterator_next_block(self, k)) {
                return NULL;
            }
            k = k + 1;
        }
    }
    return self;
}

int permutation_iterator_valid_suffix(struct permutation_iterator * self, int k) {
    int length = self->how_many_elements;
    int last_element = self->elements[length - 1];
    if (last_element == 3) {
        return 0;
    }
    if (k > length - 2) {
        return 1;
    }
    int next_to_last = self->elements[length - 2];
    if (next_to_last == 2) {
        return 0;
    }
    return 1;
}

struct permutation_iterator * permutation_iterator_next_block(struct permutation_iterator * self, int k) {

    while (self->control->c[k] == k + 1) {
        (*self->sigma_k_k_inverse)(self, k + 1);
        self->control->c[k] = 0;
        k += 1;
    }
    if (k >= self->how_many_elements) {
        return NULL;
    }
    self->control->c[k] += 1;
    (*self->tau)(self, k, self->control->c[k]);
    return self;
}


struct mixed_radix * new_permutation_control(int n) {
    int * radices = NULL;
    int i;

    radices = malloc(n * sizeof(int));
    if (!radices) {
        return NULL;
    }
    for (i = 0; i < n; i++) {
        radices[i] = i + 1;
    }
    return new_mixed_radix(n, radices);
    free(radices); // new_mixed_radix uses it's own radices array.
}

void initialize_permutation_iterator_elements(struct permutation_iterator * self) {
    int i = 0;

    for (i = 0; i < self->how_many_elements; i++) {
        self->elements[i] = i;
    }
}

void print_permutation_iterator(struct permutation_iterator * self) {
    int i = 0;

    for (i = 0; i < self->how_many_elements; i++) {
        printf("%d", self->elements[i]);
        if (i < self->how_many_elements - 1) {
            printf(", ");           
        }
    }
    printf("\n");
}

void permutation_iterator_flip_elements(struct permutation_iterator * self, int k) {
    int i = 0;
    int j = k - 1;

    while (j - i > 0) {
        permutation_iterator_swap_elements(self, i, j);
        i += 1;
        j -= 1;
    }
}

void permutation_iterator_swap_elements(struct permutation_iterator * self, int i, int j) {
    int temp = self->elements[i];

    self->elements[i] = self->elements[j];
    self->elements[j] = temp;
}

void default_omega(struct permutation_iterator * self, int k) {
    permutation_iterator_flip_elements(self, k);
}

void default_tau(struct permutation_iterator * self, int k, int j) {
    permutation_iterator_swap_elements(self, k - j, k);
}

void default_sigma_k_k_inverse(struct permutation_iterator * self, int k) {
    int temp = self->elements[k];

    while (k - 1 >= 0) {
        self->elements[k] = self->elements[k - 1];
        k--;
    }
    self->elements[0] = temp;
}
