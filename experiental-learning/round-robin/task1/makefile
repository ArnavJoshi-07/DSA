CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = client.o dll.o

task1: $(OBJS)
	$(CC) $(CFLAGS) -o task1 $(OBJS)

client.o: client.c dll.h
dll.o:    dll.c    dll.h

clean:
	rm -f $(OBJS) task1

.PHONY: clean
