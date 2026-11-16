#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void init_hash_table(hash_table_t *ptr_hash_table)
{
	ptr_hash_table->count_ = 0;
	for(int i = 0; i < TABLESIZE; ++i)
	{
		ptr_hash_table->elem_[i].in_use_ = 0;
	}
}

void deinit_hash_table(hash_table_t *ptr_hash_table)
{
	ptr_hash_table->count_ = 0;
	for(int i = 0; i < TABLESIZE; ++i)
	{
		ptr_hash_table->elem_[i].in_use_ = 0;
	}
}



void insert_word(hash_table_t *ptr_hash_table, int key, char word[])
{
	if(ptr_hash_table->count_ == TABLESIZE)
	{
		printf("table full; cannot insert\n");
		return;
	}
	int index = key % TABLESIZE;
	while(ptr_hash_table->elem_[index].in_use_!=0)
	{
	     index =(index+1) % TABLESIZE;
	}
	ptr_hash_table->elem_[index].key_=key;
	strcpy(ptr_hash_table->elem_[index].word_, word);
	ptr_hash_table->elem_[index].in_use_ = 1;
	++ptr_hash_table->count_;
}

void delete_key(hash_table_t *ptr_hash_table, int key)
{
	if(ptr_hash_table->count_ == 0)
	{
		printf("empty table; cannot delete\n");
	}
	int index = key % TABLESIZE;
	
	int i = 0;
	while(i < ptr_hash_table->count_)
	{
		if(ptr_hash_table->elem_[index].in_use_)
		{
			++i;
			if(ptr_hash_table->elem_[index].key_ == key)
			{
				printf("deleting key : %d  word :%s\n",
					ptr_hash_table->elem_[index].key_,
					ptr_hash_table->elem_[index].word_);
				ptr_hash_table->elem_[index].in_use_ = 0;
				--ptr_hash_table->count_;
				return;
			}
		}
		index = (index + 1) % TABLESIZE;
	}
	printf("key not found\n");

}

void disp_hash_table(hash_table_t *ptr_hash_table)
{
	for(int index = 0; index < TABLESIZE; ++index)
	{
		if(ptr_hash_table->elem_[index].in_use_)
		{
			printf("index : %d key : %d word : %s\n", 
				index,
				ptr_hash_table->elem_[index].key_, 
				ptr_hash_table->elem_[index].word_);
		}
	}
}

char* search(hash_table_t *ptr_hash_table, int key) 
{
	if(ptr_hash_table->count_ == 0)
	{
		printf("empty table; cannot delete\n");
	}
	int index = key % TABLESIZE;
	int i = 0;
	while(i < ptr_hash_table->count_)
	{
		if(ptr_hash_table->elem_[index].in_use_)
		{
			++i;
			if(ptr_hash_table->elem_[index].key_ == key)
			{
				printf("found key : %d  word :%s\n",
					ptr_hash_table->elem_[index].key_,
					ptr_hash_table->elem_[index].word_);
				return ptr_hash_table->elem_[index].word_;
			}
		}
		index = (index + 1) % TABLESIZE;
	}
	printf("key not found\n");
	return "";
}