#ifndef HASH_H
#define HASH_H 
#define WORDSIZE 100
#define TABLESIZE 19
struct node
{
	int in_use_;
	int key_;
	char word_[WORDSIZE];
};
typedef struct node node_t;

struct hash_table
{
  struct node elem_[TABLESIZE];
  int count_;
};
typedef struct hash_table hash_table_t;

void init_hash_table(hash_table_t *ptr_hash);
void deinit_hash_table(hash_table_t *ptr_hash);
void insert_word(hash_table_t *ptr_hash, int key, char s[]);
void delete_key(hash_table_t *ptr_hash, int key);
void disp_hash_table(hash_table_t *ptr_hash);
char* search(hash_table_t *ptr_hash, int key);
#endif 
