#include <stdio.h>
#include "term.h"

void set_term(term_t *ptr_term, double coeff, int expo)
{
    ptr_term->coeff = coeff;
    ptr_term->expo = expo;
}

void print_term(term_t *ptr_term, int is_first)
{
    double coeff = ptr_term->coeff;
    int expo = ptr_term->expo;

    if(is_first){
        if(coeff < 0)
            printf("-");
    }
    else{
        if(coeff < 0)
            printf(" - ");
        else
            printf(" + ");
    }

    if(coeff < 0)
        coeff = -coeff;

    /* exact compare: the "omit the 1" rule is cosmetic, so a coefficient that
     * is only near 1 is better printed in full than silently dropped */
    if(coeff != 1 || expo == 0)
        printf("%g", coeff);

    if(expo == 1)
        printf("x");
    else if(expo != 0)
        printf("x^%d", expo);
}

int compare_expo(term_t *left, term_t *right)
{
    return left->expo - right->expo;
}

/*
 * Power rule: c*x^n -> (c/(n+1))*x^(n+1), written into the caller's term.
 *
 * Assumption for n == -1 (handout Section 11): the integral of x^-1 is ln|x|,
 * which is not of the form c*x^n, and the power rule would divide by n+1 == 0.
 * Such a term is reported on stderr and given a zero coefficient; insert_poly
 * drops zero-coefficient terms, so it is excluded from the result rather than
 * producing a wrong answer.
 */
void integrate_term(term_t *ptr_term, term_t *ptr_integrated_term)
{
    if(ptr_term->expo == -1){
        fprintf(stderr, "Warning: x^-1 integrates to ln|x|; term skipped.\n");
        set_term(ptr_integrated_term, 0, 0);
        return;
    }
    set_term(ptr_integrated_term,
             ptr_term->coeff / (ptr_term->expo + 1),
             ptr_term->expo + 1);
}
