#include <stdio.h>

#include "permutation_iterator.h"
#include "mixed_radix.h"

void visit(struct permutation_iterator * self) {
    print_permutation_iterator(self);
}

int main() {
    printf("About to construct a new permutation_iterator\n");
    struct permutation_iterator * test = new_permutation_iterator(4);
    printf("The new permutation iterator looks like:\n");
    print_permutation_iterator(test);
    print_mixed_radix(test->control);
    printf("About to iterate...\n");
    

    do {
        if (!permutation_iterator_skip_suffix(test)) {
            break;
        }
        visit(test);
    } while(permutation_iterator_next(test));

    /*
    while (permutation_iterator_next(test)) {
        print_permutation_iterator(test);
    }
    */
    destroy_permutation_iterator(test);
}

