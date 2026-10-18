client.exe: client.o bt.o
	gcc -Wall client.o bt.o -o client.exe
client.o : client.c bt.h
	gcc -Wall -c client.c 
bt.o : bt.c bt.h
	gcc -Wall -c bt.c