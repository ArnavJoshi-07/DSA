#include <stdio.h>
#include "rect.h"

void set_rect(rect_t *r, float length, float breadth)
{
    r->length  = length;
    r->breadth = breadth;
}

void display_rect(const rect_t *r)
{
    printf("Length : %.2f, Breadth : %.2f, Area : %.2f\n",
           r->length, r->breadth, area_rect(r));
}

float area_rect(const rect_t *r)
{
    return r->length * r->breadth;
}

int compare_rect(const rect_t *r1, const rect_t *r2)
{
    return area_rect(r1) < area_rect(r2);
}