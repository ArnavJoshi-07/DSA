client.exe : client.o hash.o  
	gcc client.o hash.o   -o client.exe 
client.o : client.c hash.h 
	gcc -Wall -c client.c 
hash.o : hash.c hash.h 
	gcc -Wall -c hash.c 
 	
	