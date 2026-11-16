#include <stdio.h>
#include "hash.h"
int get_option()
{
	int opt;
	printf("1. insert 2. delete 3. search 4. display : ");
	scanf("%d", &opt);
	return opt;
}
//program to implement quadratic probing
//index=hash(key)=key%size;
// if collision compute
// index=(hash(key)+i*i)%size for i=1,2,...tablesize

int main()
{
	hash_table_t h;
	init_hash_table(&h);
	char word[WORDSIZE];
	int key;
	int opt;
	opt = get_option();
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("enter a key and a word : "); 
					 scanf("%d %s", &key, word);
					 insert_word(&h, key, word);
					 break;
			case 2 : printf("enter a key to delete : ");
					 scanf("%d", &key);
					 delete_key(&h, key);
					 break;
			case 3 : printf("enter a key to search: ");
					 scanf("%d", &key);
					 char *s = search(&h, key);
					 if(s)
					 {
						 printf("found %s\n", s);
					 }
					 else 
					 {
						 printf("no such key\n");
					 }
					 break;
			case 4 : 
					 disp_hash_table(&h);
					 break;
					
		}
		opt = get_option();
	}
	deinit_hash_table(&h);
}
