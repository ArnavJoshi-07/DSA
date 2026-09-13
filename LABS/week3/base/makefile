evaluatePostfix.exe : evaluatePostfix.o stack.o
	gcc evaluatePostfix.o stack.o -o evaluatePostfix.exe
stack.o : stack.c stack.h
	gcc -Wall -c stack.c
evaluatePostfix.o : evaluatePostfix.c stack.h
	gcc -Wall -c evaluatePostfix.c
