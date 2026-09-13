#ifndef POLY_H
#define POLY_H

#include "term.h"

/*
 * insert_poly keeps the nodes in strictly decreasing order of exponent with
 * no duplicate exponents and no zero coefficients. Every other operation
 * relies on that.
 */

struct node
{
    term_t term;
    struct node *next;
};
typedef struct node node_t;

struct poly
{
    node_t *head_;
};
typedef struct poly poly_t;

poly_t create_poly(void);
void display_poly(poly_t poly);
void add_poly(poly_t poly1, poly_t poly2, poly_t *sum);
void destroy_poly(poly_t *poly);

double eval_poly(poly_t poly, double x);
poly_t integrate_poly(poly_t poly);

void init_poly(poly_t *ptr_poly);
void insert_poly(poly_t *ptr_poly, double coeff, int expo);

#endif
