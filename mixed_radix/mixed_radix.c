#include <stdlib.h>
#include <stdio.h>

#include "mixed_radix.h"

struct mixed_radix * new_mixed_radix(int how_many_radices, int * radices) {
    struct mixed_radix * new_mixed_radix = NULL;
    int * new_radices = NULL;
    int * c = NULL;
    
    new_radices = copy_radices(how_many_radices, radices);
    if (!new_radices) {
        return NULL;
    }
    c = malloc(how_many_radices * sizeof(int));
    if (!c) {
        return NULL;
    }
    new_mixed_radix = malloc(sizeof(struct mixed_radix));
    if (!new_mixed_radix) {
        return NULL;
    }
    new_mixed_radix->radices = new_radices;
    new_mixed_radix->c = c;
    new_mixed_radix->how_many_radices = how_many_radices;
    return new_mixed_radix;
}

void destroy_mixed_radix(struct mixed_radix * self) {
    free(self->radices);
    free(self->c);
    free(self);
}

int increment_mixed_radix(struct mixed_radix * self) {
    int k = 0;
    
    while (k < self->how_many_radices && 
           self->c[k] >= self->radices[k] - 1) {
        self->c[k] = 0;
        k += 1;
    }
    if (k < self->how_many_radices) {
        self->c[k] += 1;
    }
    return k;
}

void print_mixed_radix(struct mixed_radix * self) {
    int r = self->how_many_radices;
    int i;
    
    for (i = r - 1; i >= 0; i--) {
        printf("%d_%d", self->radices[i], self->c[i]);
        if (i) {
            printf(", ");
        }
    }
    printf("\n");
}

int * copy_radices(int how_many_radices, int * radices) {
    int * copy = NULL;
    int i;

    copy = malloc(how_many_radices * sizeof(int));
    if (!copy) {
        return NULL;
    }
    for (i = 0; i < how_many_radices; i++) {
        copy[i] = radices[i];
    }
    return copy;
}
