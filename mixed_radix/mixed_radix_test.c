#include <stdio.h>

#include "mixed_radix.h"

int main() {
    int radices[] = { 2, 3, 4 };
    int k;

    printf("About to try and construct a new mixed_radix\n");
    struct mixed_radix * test = new_mixed_radix(3, radices);
    printf("The newly-constructed mixed-radix number looks like:\n");
    print_mixed_radix(test);
    printf("After incrementing the mixed-radix number, it looks like:\n");
    increment_mixed_radix(test);
    print_mixed_radix(test);
    while (increment_mixed_radix(test) < 3) {
        print_mixed_radix(test);
    }
}
