input : Given an array implementation of  binary search tree
with insert and display(inorder)
TODO:
provide a memory manager
	acts like a stack 
	initially every index of the array is pushed on the stack
	on allocation, top element of the stack is released 
	for use by popping.
	on deallocation, the current index is pushed on the stack 
	if stack full, push will fail 
	if stack empty, pop will fail
support insert and delete functions in a menu driven program

Additional exercise :
support functions for :
	1. # of nodes 
	2. # of leaves
	3. compare trees 
	4. copy trees 
	
