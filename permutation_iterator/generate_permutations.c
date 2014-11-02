#include <stdio.h>
#include <stdlib.h>

#include "permutation_iterator.h"
#include "mixed_radix.h"

int main(int argc, char * argv[]) {
    char * arg_n;
    int n;
    struct permutation_iterator * self;

    if (argc >= 2) {
        arg_n = argv[1];
        n = atoi(arg_n);
    }
    else {
        n = 4;
    }
    self = new_permutation_iterator(n);
    do {
        print_permutation_iterator(self);
    } while (permutation_iterator_next(self));
    destroy_permutation_iterator(self);
    
}

