#ifndef FUNCTION_H 
#define FUNCTION_H 
void mymap(int a[], int b[], int n, int (*op)(int));
void filter(int a[], int n, int b[], int *ptr_m, int (*op)(int));
int reduce(int a[], int n, int init, int (*op)(int));
#endif 