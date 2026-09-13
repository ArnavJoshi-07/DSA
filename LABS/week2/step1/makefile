client.exe: client.o rect.o
	gcc client.o rect.o -o client.exe
rect.o: rect.c rect.h
	gcc -Wall -c rect.c
client.o: client.c rect.h
	gcc -Wall -c client.c