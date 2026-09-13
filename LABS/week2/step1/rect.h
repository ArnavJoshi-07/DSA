#ifndef RECT_H
#define RECT_H

typedef struct
{
    float length;
    float breadth;
} rect_t;
void set_rect(rect_t *r, float length, float breadth);
void display_rect(const rect_t *r);
float area_rect(const rect_t *r);

#endif