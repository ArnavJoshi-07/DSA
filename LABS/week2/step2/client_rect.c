#include <stdio.h>
#include "rect.h"

int main(void)
{
    rect_t r1, r2;
    float len, brd;

    printf("Enter length and breadth of rectangle 1 : ");
    scanf("%f %f", &len, &brd);
    set_rect(&r1, len, brd);

    printf("Enter length and breadth of rectangle 2 : ");
    scanf("%f %f", &len, &brd);
    set_rect(&r2, len, brd);

    printf("\nRectangle 1 -> ");
    display_rect(&r1);
    printf("Rectangle 2 -> ");
    display_rect(&r2);

    if (compare_rect(&r1, &r2))
        printf("\nRectangle 1 is smaller than Rectangle 2 (by area)\n");
    else if (compare_rect(&r2, &r1))
        printf("\nRectangle 2 is smaller than Rectangle 1 (by area)\n");
    else
        printf("\nBoth rectangles have equal area\n");

    return 0;
}