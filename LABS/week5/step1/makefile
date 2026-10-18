CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = client.o clist.o josephus.o

step1: $(OBJS)
	$(CC) $(CFLAGS) -o step1 $(OBJS)

client.o:   client.c   clist.h josephus.h
clist.o:    clist.c    clist.h
josephus.o: josephus.c clist.h josephus.h

test: step1
	printf "7\n3\n" | ./step1

leaks: step1
	printf "7\n3\n" | valgrind --leak-check=full ./step1

clean:
	rm -f $(OBJS) step1

.PHONY: test leaks clean
