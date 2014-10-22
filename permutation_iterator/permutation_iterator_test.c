#include <stdio.h>

#include "permutation_iterator.h"

int main() {
    printf("About to construct a new permutation_iterator\n");
    struct permutation_iterator * test = new_permutation_iterator(4);
    printf("The new permutation iterator looks like:\n");
    print_permutation_iterator(test);
    printf("About to iterate...\n");
    while (permutation_iterator_next(test)) {
        print_permutation_iterator(test);
    }
    destroy_permutation_iterator(test);
    printf("All done!\n");
}
