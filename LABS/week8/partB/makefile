CC     = gcc
CFLAGS = -Wall -Wextra -g
OBJS   = main.o tree.o stack.o

partB: $(OBJS)
	$(CC) $(CFLAGS) -o partB $(OBJS)

main.o:  main.c  tree.h stack.h
tree.o:  tree.c  tree.h stack.h
stack.o: stack.c stack.h

MENU = grep -v -e "^1\. insert" -e "^6\. copy"

# make test -- insert 50 30 70 20 40 60 80, then every case of delete:
# leaf (20), both subtrees (70), not found (99), only right (30), only left (80);
# the next insert (20) reuses the last freed index; then copy / compare
test: partB
	printf "1\n50\n1\n30\n1\n70\n1\n20\n1\n40\n1\n60\n1\n80\n3\n5\n\
	2\n20\n3\n5\n2\n70\n3\n2\n99\n2\n30\n3\n2\n80\n3\n\
	1\n20\n3\n4\n5\n6\n7\n1\n90\n7\n8\n" | ./partB | $(MENU)

# make full -- 200 inserts use every index; the 201st pop fails and is reported
full: partB
	(for i in $$(seq 1 201); do printf "1\n$$i\n"; done; printf "8\n") | ./partB | $(MENU) | tail -3

clean:
	rm -f $(OBJS) partB

.PHONY: test full clean
