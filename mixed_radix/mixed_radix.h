#ifndef _MIXED_RADIX_H_
#define _MIXED_RADIX_H_

struct mixed_radix {
    int how_many_radices;
    int * radices;
    int * c;
};

struct mixed_radix * new_mixed_radix(int, int *);
void destroy_mixed_radix(struct mixed_radix *);
int increment_mixed_radix(struct mixed_radix *);
void print_mixed_radix(struct mixed_radix *);
int * copy_radices(int, int *);

#endif
