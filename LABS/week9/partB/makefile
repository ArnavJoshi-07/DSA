client.exe : client.o tree.o queue.o
	gcc client.o tree.o queue.o -o client.exe
tree.o : tree.c tree.h queue.h
	gcc -Wall -c tree.c 
queue.o : queue.c queue.h tree.h
	gcc -Wall -c queue.c
client.o : client.c tree.h 
	gcc -Wall -c client.c 
	