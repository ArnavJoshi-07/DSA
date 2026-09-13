#ifndef TERM_H
#define TERM_H

/*
 * The handout lists term_t *create_term(double, int), but node_t embeds a
 * term_t by value, so an allocating create_term would force a second malloc
 * and a copy. We fill a term in place with set_term instead.
 */

struct term
{
    int coeff;
    int expo;
};
typedef struct term term_t;

void set_term(term_t *ptr_term, int coeff, int expo);
void print_term(term_t *ptr_term, int is_first);
int compare_expo(term_t *left, term_t *right);

#endif
