#include <stdio.h> 
#include "function.h" 

// for mymap
int sum_digits(int x)
{
	int sum = 0;
	while(x != 0)
	{
		sum = sum + x % 10;
		x = x / 10;
	}
	return sum;
}
int reverse(int x)
{
	int rev = 0;
	while(x != 0)
	{
		rev = rev * 10 + x % 10;
		x = x / 10;
	}
	return rev;
}

// for myfilter
int is_odd(int x) { return x % 2 != 0; }
int is_prime(int x)
{
	if(x < 2)
	{
		return 0;
	}
	for(int i = 2; i * i <= x; ++i)
	{
		if(x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

// for myreduce
int add(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

void disp(int a[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{

	int a[] = {123, 45, 7, 908, 61};
	int n = 5;
	int b[5];

	printf("input          : ");
	disp(a, n);

	mymap(a, b, n, sum_digits);
	printf("sum of digits  : ");
	disp(b, n);

	mymap(a, b, n, reverse);
	printf("reversed       : ");
	disp(b, n);

	//myfilter
	int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int nc = 12;
	int d[12];
	int m;

	printf("\ninput          : ");
	disp(c, nc);

	myfilter(c, nc, d, &m, is_odd);
	printf("odd numbers    : ");
	disp(d, m);

	myfilter(c, nc, d, &m, is_prime);
	printf("prime numbers  : ");
	disp(d, m);

	//myreduce
	int e[] = {1, 2, 3, 4, 5};
	int ne = 5;

	printf("\ninput          : ");
	disp(e, ne);
	printf("sum            : %d\n", myreduce(e, ne, 0, add));
	printf("product        : %d\n", myreduce(e, ne, 1, mul));
}
