#include <stdio.h>

#include "permutation_iterator.h"
#include "mixed_radix.h"

void visit(struct permutation_iterator * self) {
    print_permutation_iterator(self);
}

// Testing suffix criteria: It can't have a 3 in the 4th position,
// or a 2 in the 3rd position.
int valid_suffix(struct permutation_iterator * self, int k) {
    int length = self->how_many_elements;
    int last_element = self->elements[length - 1];
    int next_to_last;

    // Eliminate suffixes ending with 3
    if (last_element == 3) {
        return 0;
    }

    // If checking a long-enough suffix,
    // eliminate 2 in penultimate position.
    if (k > length - 2) {
        return 1;
    }
    next_to_last = self->elements[length - 2];
    if (next_to_last == 2) {
        return 0;
    }
    return 1;
}


int main() {
    struct permutation_iterator * test;

    printf("About to construct a new permutation_iterator\n");
    test = new_permutation_iterator(4);
    test->valid_suffix = &valid_suffix;
    printf("The new permutation iterator looks like:\n");
    print_permutation_iterator(test);
    print_mixed_radix(test->control);
    printf("About to iterate...\n");
    permutation_iterator_visit_valid(test, &visit);
    destroy_permutation_iterator(test);
}

