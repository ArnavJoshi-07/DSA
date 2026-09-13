client.exe : client.o stack.o
	gcc client.o stack.o -o client.exe
stack.o: stack.h stack.c
	gcc -Wall -c stack.c
client.o : client.c stack.h
	gcc -Wall -c client.c