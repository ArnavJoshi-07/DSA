client.exe : term.o poly.o client.o
	gcc term.o poly.o client.o -o client.exe
term.o : term.c term.h
	gcc -Wall -c term.c
poly.o : poly.c poly.h term.h
	gcc -Wall -c poly.c
client.o : client.c poly.h term.h
	gcc -Wall -c client.c
clean :
	rm -f *.o client.exe
