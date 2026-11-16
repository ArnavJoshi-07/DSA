#include <stdio.h>
#include "tree.h"

int main()
{
	tree_t t;
	init(&t);

	int choice, key;
	while(1)
	{
		printf("1. insert  2. display  3. exit\n");
		printf("choice : ");
		if(scanf("%d", &choice) != 1)
		{
			break;
		}
		switch(choice)
		{
			case 1 : printf("key : ");
				 if(scanf("%d", &key) == 1)
				 {
					insert(&t, key);
				 }
				 break;
			case 2 : disp(&t);
				 break;
			case 3 : return 0;
			default : printf("invalid choice\n");
		}
	}
	return 0;
}
