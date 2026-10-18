CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = client.o clist.o josephus.o

step2: $(OBJS)
	$(CC) $(CFLAGS) -o step2 $(OBJS)

client.o:   client.c   clist.h josephus.h
clist.o:    clist.c    clist.h
josephus.o: josephus.c clist.h josephus.h

test: step2
	printf "7\n3\nAlice\nBob\nCarol\nDave\nEve\nFrank\nGrace\n" | ./step2

leaks: step2
	printf "7\n3\nAlice\nBob\nCarol\nDave\nEve\nFrank\nGrace\n" | valgrind --leak-check=full ./step2

clean:
	rm -f $(OBJS) step2

.PHONY: test leaks clean
