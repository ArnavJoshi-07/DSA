#ifndef TERM_H
#define TERM_H

/*
 * Coefficients are double here: integration divides by (expo + 1), so an int
 * coefficient would truncate the integral of 3x^3 from 0.75x^4 to 0x^4.
 *
 * The handout lists term_t *create_term(double, int), but node_t embeds a
 * term_t by value, so an allocating create_term would force a second malloc
 * and a copy. We fill a term in place with set_term instead.
 */

struct term
{
    double coeff;
    int expo;
};
typedef struct term term_t;

void set_term(term_t *ptr_term, double coeff, int expo);
void print_term(term_t *ptr_term, int is_first);
int compare_expo(term_t *left, term_t *right);
void integrate_term(term_t *ptr_term, term_t *ptr_integrated_term);

#endif
