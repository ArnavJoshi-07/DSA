#include <stdio.h>
#include "rect.h"
#include <stdlib.h>
int main(){
    rect_t r; float length, breadth;
    printf("Enter length: ");scanf("%f", &length);
    printf("Enter breadth: ");scanf("%f", &breadth);
    set_rect(&r, length, breadth);
    printf("\nRectangle Parameters:\n");
    display_rect(&r);
    printf("\nArea of Rectangle: %.2f\n",area_rect(&r));

}