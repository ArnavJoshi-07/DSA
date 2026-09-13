#include <stdio.h>
#include "poly.h"

int main()
{
	poly_t p;
	init_list(&p);

	
	int coeff[] = { 5,  3, -2,  7,  4,  6};
	int expo[]  = { 2,  5,  0,  3,  2,  5};
	int n = 6;

	for(int i = 0; i < n; ++i)
	{
		insert_list(&p, coeff[i], expo[i]);
	}

	printf("Polynomial:\n");
	disp_list(&p);

	free_list(&p);
	return 0;
}
