#include <stdio.h>
#include <string.h>

#include "cayley.h"

int MAXELEMENTS = 10;

int cayley_adjacent(char * v1, char * v2, int n, int * d) {
    char temp[MAXELEMENTS + 1];
    int i;

    temp[0] = '\0';
    strcpy(temp, v1);
    for (i = 0; i < n - 1; i++) {
        swap_char(temp, i, i + 1);
        if (strcmp(temp, v2) == 0) {
            *d = i + 1;
            return 1;
        }
        swap_char(temp, i + 1, i);
    }
    *d = 0;
    return 0;
}

void swap_char(char * string, int i, int j) {
    char temp = string[i];

    string[i] = string[j];
    string[j] = temp;
}
