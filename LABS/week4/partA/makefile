CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = client.o poly.o term.o

partA: $(OBJS)
	$(CC) $(CFLAGS) -o partA $(OBJS)

client.o: client.c poly.h term.h
poly.o:   poly.c   poly.h term.h
term.o:   term.c   term.h

# make test -- feeds the Section 7 sample input
test: partA
	printf "3\n5 3\n-2 2\n7 0\n2\n3 2\n4 1\n" | ./partA

# make leaks -- Section 16 requires no leaks
leaks: partA
	printf "3\n5 3\n-2 2\n7 0\n2\n3 2\n4 1\n" | valgrind --leak-check=full ./partA

clean:
	rm -f $(OBJS) partA

.PHONY: test leaks clean
