#include <stdio.h>
#include "term.h"

void set_term(term_t *ptr_term, int coeff, int expo)
{
    ptr_term->coeff = coeff;
    ptr_term->expo = expo;
}

void print_term(term_t *ptr_term, int is_first)
{
    int coeff = ptr_term->coeff;
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

    if(coeff != 1 || expo == 0)
        printf("%d", coeff);

    if(expo == 1)
        printf("x");
    else if(expo != 0)
        printf("x^%d", expo);
}

int compare_expo(term_t *left, term_t *right)
{
    return left->expo - right->expo;
}
