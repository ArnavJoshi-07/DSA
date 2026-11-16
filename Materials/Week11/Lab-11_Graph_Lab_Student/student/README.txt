Graph Lab - Student Starter Files
=================================
problem1/  Adjacency list     : edit graph.c      (graph.h, main1.c are given)
problem2/  Adjacency matrix   : edit graph_2.c    (graph_2.h, main2.c are given)

Complete every function marked TODO. Build and run each folder separately:
  cd problem1 && make && ./p1
  cd problem2 && make && ./p2
The files compile as given (with warnings about unused parameters) but print
nothing useful until you fill in the TODOs.

Expected output, Problem 1
--------------------------
displaying
A : 1
B : 0 2
C : 1
D : 4
E : 3
F : 6
G : 5
H :

Expected output, Problem 2 (last part)
--------------------------------------
Before: 4 groups
Components = 4, connections needed = 3
Connect A - D
Connect D - F
Connect F - H
Added 3 edges
After: 1 group
(connected_components also prints "count : n" and the DFS visit order.)

Self-check
----------
1. Problem 1: why must deinit_graph free the nodes rather than call init_list?
2. Problem 2: why do k groups need exactly k - 1 new connections?
3. Would the answer change if you picked different representative cities?
