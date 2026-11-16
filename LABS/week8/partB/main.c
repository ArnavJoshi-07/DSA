#include <stdio.h>
#include "tree.h"

int main()
{
	tree_t t;
	init(&t);
	tree_t copy; // second tree for copy / compare
	init(&copy);

	int choice, key;
	while(1)
	{
		printf("1. insert  2. delete  3. display  4. # of nodes  5. # of leaves\n");
		printf("6. copy tree  7. compare with copy  8. exit\n");
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
			case 2 : printf("key : ");
				 if(scanf("%d", &key) == 1 && ! delete_key(&t, key))
				 {
					printf("%d : key not found\n", key);
				 }
				 break;
			case 3 : disp(&t);
				 break;
			case 4 : printf("# of nodes : %d\n", count_nodes(&t));
				 break;
			case 5 : printf("# of leaves : %d\n", count_leaves(&t));
				 break;
			case 6 : copy_tree(&copy, &t);
				 printf("copy : ");
				 disp(&copy);
				 break;
			case 7 : if(compare_trees(&t, &copy))
				 {
					printf("tree and copy are equal\n");
				 }
				 else
				 {
					printf("tree and copy are not equal\n");
				 }
				 break;
			case 8 : return 0;
			default : printf("invalid choice\n");
		}
	}
	return 0;
}
