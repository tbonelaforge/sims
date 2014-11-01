#include <stdio.h>

#include "permutation_iterator.h"
#include "mixed_radix.h"

int main() {
    printf("About to construct a new permutation_iterator\n");
    struct permutation_iterator * test = new_permutation_iterator(4);
    printf("The new permutation iterator looks like:\n");
    print_permutation_iterator(test);
    print_mixed_radix(test->control);
    printf("About to iterate...\n");
    
    while (permutation_iterator_next_valid(test)) {
        print_permutation_iterator(test);
        print_mixed_radix(test->control);
    }
}

