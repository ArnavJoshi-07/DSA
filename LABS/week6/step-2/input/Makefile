client.exe : client.o dll.o queue.o
	gcc client.o dll.o queue.o -o client.exe
client.o : client.c dll.h 
	gcc -Wall -c client.c 
queue.o : queue.c dll.h
	gcc -Wall -c queue.c
dll.o : dll.c dll.h
	gcc -Wall -c dll.c 

