#include <stdio.h>
#include "date.h"

int main()
{
    date_t d;

    int dd, mm, yy;

    printf("Enter day month year: ");
    scanf("%d %d %d", &dd, &mm, &yy);

    set_date(&d, dd, mm, yy);

    printf("Stored ");
    disp_date(&d);

    return 0;
}