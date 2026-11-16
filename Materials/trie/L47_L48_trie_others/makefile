client.exe : client.o trie.o stack.o
	gcc client.o trie.o stack.o -o client.exe 
client.o : client.c trie.h 
	gcc -Wall -c client.c 
trie.o : trie.c trie.h 
	gcc -Wall -c trie.c 
stack.o : stack.h stack.c 
	gcc -Wall -c stack.c 
	
	
	