#include <stdio.h>
#include "poly.h"

int main(){
	int n;
	poly_t ptr_poly;
	init_list(&ptr_poly);
	printf("Enter no of terms in the polynomial: ");scanf("%d",&n);
	int expo,coeff;
	for(int i = 0; i<n; i++){
		printf("Enter coefficient and exponent values: ");
		scanf("%d %d",&coeff,&expo);
		insert_list(&ptr_poly, coeff, expo);
	}
	disp_list(&ptr_poly);
	printf("\n");
	int x;
	printf("Enter value of x: ");scanf("%d",&x);
	int res = eval_poly(&ptr_poly,x);
	printf("Evaluated Polynomial: %d\n",res);
    poly_t dest;
    init_list(&dest);
    copy_list(&ptr_poly, &dest);
    printf("Displaying copy: \n");
    disp_list(&dest);
    poly_t dest_diff;
    init_list(&dest_diff);
    diff_list(&ptr_poly, &dest_diff);
    printf("Displaying Differentiated list: \n");
    disp_list(&dest_diff);
    free_list(&dest_diff);
}