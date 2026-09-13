a.exe : cll.o client.o
	gcc cll.o client.o -o client.exe
clist.o : cll.c cll.h
	gcc -Wall -c cll.c 
client.o : client.c cll.h
	gcc -Wall -c client.c 
	
