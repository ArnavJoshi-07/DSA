CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = client.o poly.o term.o

partB: $(OBJS)
	$(CC) $(CFLAGS) -o partB $(OBJS)

client.o: client.c poly.h term.h
poly.o:   poly.c   poly.h term.h
term.o:   term.c   term.h

# make test -- feeds the Section 14 sample; expect 12.0000
test: partB
	printf "2\n3 2\n2 1\n0\n2\n" | ./partB

# make leaks -- Section 16 requires no leaks
leaks: partB
	printf "2\n3 2\n2 1\n0\n2\n" | valgrind --leak-check=full ./partB

clean:
	rm -f $(OBJS) partB

.PHONY: test leaks clean
