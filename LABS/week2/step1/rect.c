#include <stdio.h>
#include "rect.h"

void set_rect(rect_t* r, float length, float breadth)
{
    r->length = length;
    r->breadth = breadth;
}

void display_rect(const rect_t *r)
{
    printf("Length  : %.2f\n", r->length);
    printf("Breadth : %.2f\n", r->breadth);
}

float area_rect(const rect_t *r)
{
    return r->length * r->breadth;
}