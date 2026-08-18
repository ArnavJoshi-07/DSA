#include <stdio.h>
#include "date.h"

/* Set the date */
void set_date(date_t *ptr_date, int dd, int mm, int yy)
{
    ptr_date->day = dd;
    ptr_date->month = mm;
    ptr_date->year = yy;
}

/* Display the date */
void disp_date(date_t *ptr_date)
{
    printf("Date: %02d-%02d-%04d\n",
           ptr_date->day,
           ptr_date->month,
           ptr_date->year);
}