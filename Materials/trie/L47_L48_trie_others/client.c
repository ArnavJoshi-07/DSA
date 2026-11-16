#include <stdio.h>
#include "trie.h" 

int get_option()
{
	int opt;
	printf("1. insert 2. display 3 : search 4 : all prefix 5: delete ");
	scanf("%d", &opt);
	return opt;
}
int main()
{
	char word[20];
	trie_t t;
	init_trie(&t);
	int opt;
	opt = get_option();
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("enter a word : "); scanf("%s", word);
					 insert_word(&t, word); break; 
			case 2 : display(&t); break;
			case 3 : printf("enter a word : "); scanf("%s", word);
					 if(search(&t, word))
						printf("%s found\n", word);
					 else 
						printf("%s not found\n", word);
					 break; 
			case 4 : printf("enter a word : "); scanf("%s", word);
					 all_prefix(&t, word); break;
			case 5 : printf("enter a word : "); scanf("%s", word);
					 delete_word(&t, word); break;

		}
		opt = get_option();
		
	}
	deinit_trie(&t);
}