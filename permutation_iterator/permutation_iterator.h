#ifndef _PERMUTATION_ITERATOR_H_
#define _PERMUTATION_ITERATOR_H_

#include <stdlib.h>

#include "mixed_radix.h"

struct permutation_iterator;

typedef void (*ptr2tau_fn)(struct permutation_iterator *, int, int);
typedef void (*ptr2omega_fn)(struct permutation_iterator *, int);
typedef void (*ptr2inverse_fn)(struct permutation_iterator *, int);
typedef int (*ptr2suffix_fn)(struct permutation_iterator *, int);

struct permutation_iterator {
    int how_many_elements;
    int * elements;
    struct mixed_radix * control;
    ptr2tau_fn tau;
    ptr2omega_fn omega;
    ptr2inverse_fn sigma_k_k_inverse;
    ptr2suffix_fn valid_suffix;
    int k;
};

struct permutation_iterator * new_permutation_iterator(int);
void destroy_permutation_iterator(struct permutation_iterator *);
struct mixed_radix * new_permutation_control(int);
struct permutation_iterator * permutation_iterator_next(struct permutation_iterator *);
struct permutation_iterator * permutation_iterator_next_valid(struct permutation_iterator *);
struct permutation_iterator * permutation_iterator_skip_suffix(struct permutation_iterator *);
struct permutation_iterator * permutation_iterator_next_block(struct permutation_iterator *, int);
void initialize_permutation_iterator_elements(struct permutation_iterator *);
void print_permutation_iterator(struct permutation_iterator *);
void default_omega(struct permutation_iterator *, int);
void default_tau(struct permutation_iterator *, int, int);
void default_sigma_k_k_inverse(struct permutation_iterator *, int);
int default_valid_suffix(struct permutation_iterator *, int);

#endif
