CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = main.o tree.o stack.o

partA: $(OBJS)
	$(CC) $(CFLAGS) -o partA $(OBJS)

main.o:  main.c  tree.h stack.h
tree.o:  tree.c  tree.h stack.h
stack.o: stack.c stack.h

# make test -- sample: insert 50 30 70 20 40, display; expect 20 30 40 50 70
test: partA
	printf "1\n50\n1\n30\n1\n70\n1\n20\n1\n40\n2\n3\n" | ./partA

# make full -- 200 inserts use every index; the 201st pop fails and is reported
full: partA
	(for i in $$(seq 1 201); do printf "1\n$$i\n"; done; printf "3\n") | ./partA | tail -3

clean:
	rm -f $(OBJS) partA

.PHONY: test full clean
