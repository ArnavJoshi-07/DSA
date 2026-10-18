client.exe : client.o stack.o
	gcc -Wall client.o stack.o -o client.exe

client.o : stack.h client.c
	gcc -Wall -c client.c

stack.o : stack.c stack.h
	gcc -Wall -c stack.c