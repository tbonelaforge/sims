#include <stdio.h>

#include "cayley.h"

int main() {
    char * v1 = "abcd";
    char * v2 = "bacd";
    int n = 4;
    int d;


    printf("About to test if %s and %s are adjacent:\n", v1, v2);
    if (cayley_adjacent(v1, v2, n, &d)) {
        printf("%s and %s are adjacent with delta number %d.\n", v1, v2, d);
    }
    else {
        printf("%s and %s are not adjacent.\n", v1, v2);
    }

    v2 = "acbd";
    if (cayley_adjacent(v1, v2, n, &d)) {
        printf("%s and %s are adjacent with delta number %d.\n", v1, v2, d);
    }
    else {
        printf("%s and %s are not adjacent.\n", v1, v2);
    }

    v2 = "abdc";
    if (cayley_adjacent(v1, v2, n, &d)) {
        printf("%s and %s are adjacent with delta number %d.\n", v1, v2, d);
    }
    else {
        printf("%s and %s are not adjacent.\n", v1, v2);
    }

    v2 = "dcba";
    if (cayley_adjacent(v1, v2, n, &d)) {
        printf("%s and %s are adjacent with delta number %d.\n", v1, v2, d);
    }
    else {
        printf("%s and %s are not adjacent.\n", v1, v2);
    }
}
