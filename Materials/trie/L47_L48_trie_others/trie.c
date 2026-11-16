#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "trie.h"
#include "stack.h"

static node_t* create_node()
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	for(int i = 0; i < MAXSIZE; ++i)
	{
		temp->child[i] = NULL;
	}
	temp->is_word_end = 0;
	return temp;
}

void init_trie(trie_t *ptr_trie)
{
	ptr_trie->root_ = create_node();
}

static void deinit_recursive(node_t *temp)
{
	for(int i = 0; i < MAXSIZE; ++i)
	{
		if(temp->child[i])
		{
			deinit_recursive(temp->child[i]);
		}
		free(temp->child[i]);
	}
}
void deinit_trie(trie_t *ptr_trie)
{
	deinit_recursive(ptr_trie->root_);
}

void insert_word(trie_t *ptr_trie, char* s)
{
	node_t* pres = ptr_trie->root_;
	int ch;
	while((ch = *s++) != '\0')
	{
		if(pres->child[ch] == NULL)
		{
			pres->child[ch] = create_node();
		}
		pres = pres->child[ch];
	}
	pres->is_word_end = 1;
}

static void display_recursive(node_t *pres, char word[], int* ptr_len)
{
	for(int i = 0; i < MAXSIZE; ++i)
	{
		if(pres->child[i] != NULL)
		{
			word[(*ptr_len)++] = i;
			if(pres->child[i]->is_word_end)
			{
				word[*ptr_len] = '\0';
				printf("word : %s\n", word);
			}
			display_recursive(pres->child[i], word, ptr_len);
			--(*ptr_len); 
		}
	}
	
}

void display(trie_t *ptr_trie)
{
	char word[MAXSIZE] = ""; 
	int len = 0;
	display_recursive(ptr_trie->root_, word, &len);
}

static node_t* prefix(node_t* pres, char* s)
{
	int ch;
	while((ch = *s++) != '\0')
	{
		if(pres->child[ch] == NULL)
			return NULL;
		pres = pres->child[ch];
	}
	return pres;
}

int search(trie_t *ptr_trie, char* s)
{
	node_t* pres = prefix(ptr_trie->root_, s);
	return (pres != NULL) && pres->is_word_end;
}

void all_prefix(trie_t *ptr_trie, char* s)
{
	node_t* pres = prefix(ptr_trie->root_, s);
	if(pres == NULL)
		return;
	if(pres->is_word_end)
		printf("word: %s\n", s);
	char word[MAXSIZE];
	strcpy(word, s);
	int len = strlen(s);
	display_recursive(pres, word, &len);	
}

static int has_no_child(node_t* pres)
{
	for(int i = 0; i < MAXSIZE; ++i)
	{
		if(pres->child[i])
		{
			return 0;
		}
	}
	return 1;
}

void delete_word(trie_t *ptr_tree, char* s)
{
	stack_t st;
	init_stack(&st);
	
	int ch;
	node_t* parent = NULL;
	node_t* pres = ptr_tree->root_;
	while((ch = *s++) != '\0')
	{
		if(pres->child[ch] == NULL)
		{
			printf("word does not exist"); 
			deinit_stack(&st);
			return;
		}
		push(&st, pres);
		parent = pres;
		pres = pres->child[ch];
	}
	
	if(! pres->is_word_end)
	{
		printf("word does not exist"); 
		deinit_stack(&st);
		return;
		
	}
	pres->is_word_end = 0;
	
	// if this prefix has some other word, will have children
	if(! has_no_child(pres))
	{
		deinit_stack(&st);
		return;
	}
	 
	// prune nodes upwards 
	
	while(!is_empty(&st))
	{
		parent = pop(&st);
		for(int i = 0; i < MAXSIZE; ++i)
		{
			if(pres == parent->child[i])
			{
				parent->child[i] = NULL;
				break;
			}
		}
		free(pres);
		if(! has_no_child(parent) || parent->is_word_end)
		{
			deinit_stack(&st);
			return;
		}
		pres = parent;
	}
	deinit_stack(&st);
}

