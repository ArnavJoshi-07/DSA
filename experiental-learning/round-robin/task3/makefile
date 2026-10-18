CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = client.o dll.o job.o

task3: $(OBJS)
	$(CC) $(CFLAGS) -o task3 $(OBJS)

client.o: client.c dll.h job.h
dll.o:    dll.c    dll.h job.h
job.o:    job.c    job.h

clean:
	rm -f $(OBJS) task3

.PHONY: clean
