date.exe : date.o client.o
	gcc date.o client.o -o date

date.o : date.c date.h
	gcc -Wall -c date.c

client.o : client.c date.h
	gcc -Wall -c client.c

