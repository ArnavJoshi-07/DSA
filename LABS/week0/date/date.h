#ifndef DATE_H
#define DATE_H

typedef struct
{
    int day;
    int month;
    int year;
} date_t;


void set_date(date_t *ptr_date, int dd, int mm, int yy);
void disp_date(date_t *ptr_date);

#endif



