client.exe : client.o sll.o
	gcc client.o sll.o -o client

sll.o : sll.c sll.h
	gcc -Wall -c sll.c

client.o : client.c sll.h
	gcc -Wall -c client.c