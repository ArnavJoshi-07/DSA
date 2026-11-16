# THREADED BINARY TREES (TBT)

## 1. Introduction

A Threaded Binary Tree is a modified binary tree in which NULL pointers are replaced with special pointers called **threads**.

In a normal binary tree, every node contains two pointers:
- Left pointer
- Right pointer

If a node does not have a left or right child, the corresponding pointer is NULL.

These NULL pointers are essentially unused. Threaded Binary Trees make use of them by storing information about the node's inorder predecessor or inorder successor.

**Main objective:** To perform tree traversal without using recursion or an auxiliary stack.

---

## 2. Understanding Inorder Traversal

Before understanding threading, we need to understand inorder traversal.

Inorder traversal follows:

**LEFT → ROOT → RIGHT**

Consider the following binary tree:

```text
          20
         /  \
        10   30
       / \
      5   15
```

Its inorder traversal is:

```text
5 → 10 → 15 → 20 → 30
```

Two important terms:

**Inorder Predecessor:**
The node that appears immediately before the current node during inorder traversal.

**Inorder Successor:**
The node that appears immediately after the current node during inorder traversal.

| Node | Predecessor | Successor |
|------|-------------|-----------|
| 5    | NULL        | 10        |
| 10   | 5           | 15        |
| 15   | 10          | 20        |
| 20   | 15          | 30        |
| 30   | 20          | NULL      |

---

## 3. Types of Threaded Binary Trees

### A. Left Threaded Binary Tree

In a left-threaded binary tree, every NULL left pointer is replaced with a thread pointing to the inorder predecessor.

Example:

If node 15 has no left child, its left pointer can point to node 10.

### B. Right Threaded Binary Tree

In a right-threaded binary tree, every NULL right pointer is replaced with a thread pointing to the inorder successor.

Example:

If node 15 has no right child, its right pointer can point to node 20.

### C. Fully / Double Threaded Binary Tree

In a double-threaded binary tree, both NULL left and NULL right pointers are replaced with threads.

- Left thread points to inorder predecessor.
- Right thread points to inorder successor.

This allows traversal in both forward and backward directions.

---

## 4. Structure of a Threaded Binary Tree Node

A normal binary tree node contains:

```c
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
```

A threaded binary tree requires two additional variables:

```c
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int lthread;
    int rthread;
} node_t;
```

Purpose of the thread flags:

| Flag | Value | Meaning |
|------|-------|---------|
| lthread | 0 | Left pointer is an actual child |
| lthread | 1 | Left pointer is a thread |
| rthread | 0 | Right pointer is an actual child |
| rthread | 1 | Right pointer is a thread |

**Important:** We need these flags because a pointer can represent either a child or a thread. Without flags, we cannot distinguish between the two.

---

## 5. How Threading Works

Consider:

```text
          20
         /  \
        10   30
       / \
      5   15
```

Inorder sequence:

```text
5 → 10 → 15 → 20 → 30
```

Now consider the NULL pointers.

- Node 5 has no left child. Its left thread points to NULL because it has no predecessor.
- Node 5 has no right child. Its right thread points to 10.
- Node 15 has no left child. Its left thread points to 10.
- Node 15 has no right child. Its right thread points to 20.
- Node 30 has no left child. Its left thread points to 20.
- Node 30 has no right child. Its right thread points to NULL.

Instead of wasting these pointers, we use them to connect nodes according to their inorder sequence.

---

## 6. Inorder Traversal Without Recursion

This is the most important advantage of a threaded binary tree.

In a normal binary tree, inorder traversal requires recursion or a stack.

In a threaded binary tree, we can perform inorder traversal using pointers alone.

### Step 1: Find the Leftmost Node

The first node in inorder traversal is always the leftmost node.

```c
node_t* leftmost(node_t *root) {

    if(root == NULL)
        return NULL;

    while(root->lthread == 0)
        root = root->left;

    return root;
}
```

Explanation:

- Start from the root.
- Continue moving left while the left pointer represents an actual child.
- Stop when the left pointer is a thread.
- Return the current node.

### Step 2: Find the Inorder Successor

```c
node_t* inorder_successor(node_t *ptr) {

    if(ptr->rthread == 1)
        return ptr->right;

    ptr = ptr->right;

    while(ptr->lthread == 0)
        ptr = ptr->left;

    return ptr;
}
```

Explanation:

There are two possibilities:

**Case 1: Right pointer is a thread.**

The thread already points to the inorder successor.

**Case 2: Right pointer is an actual child.**

Move to the right subtree and find its leftmost node.

That node is the inorder successor.

### Step 3: Perform Inorder Traversal

```c
void inorder(node_t *root) {

    node_t *cur = leftmost(root);

    while(cur != NULL) {

        printf("%d ", cur->data);

        cur = inorder_successor(cur);
    }
}
```

This performs inorder traversal without recursion or a stack.

Time Complexity: O(n)

Auxiliary Space Complexity: O(1)

---

## 7. Understanding Insertion

Insertion in a threaded binary tree is slightly more complicated than insertion in a normal BST.

When inserting a node, we must maintain the threads.

Consider inserting 15 into:

```text
       20
      /
     10
```

Initially, node 10 has:
- Left thread pointing to NULL.
- Right thread pointing to 20.

Now insert 15 as the right child of 10.

The new structure:

```text
       20
      /
     10
       \
        15
```

The new node 15 must have:
- Left thread pointing to 10 (its inorder predecessor).
- Right thread pointing to 20 (its inorder successor).

Node 10's right pointer must now point to 15 as an actual child rather than a thread.

Therefore:

```c
newnode->lthread = 1;
newnode->rthread = 1;

newnode->left = parent;
newnode->right = parent->right;

parent->rthread = 0;
parent->right = newnode;
```

This example assumes insertion as the right child of a node whose right pointer was previously a thread.

---

## 8. Understanding Deletion

Deletion is more complicated because removing a node can affect the threads of its predecessor and successor.

There are three cases:

### Case 1: Node is a Leaf

The node has no actual children.

We remove it and update its parent's pointer to become a thread.

### Case 2: Node Has One Child

The node has either a left child or a right child.

We replace the deleted node with its existing child and update the relevant threads.

### Case 3: Node Has Two Children

Find the inorder successor of the node.

Copy the successor's data into the node being deleted.

Then delete the inorder successor, which will have at most one actual child.

This is similar to deletion in a normal BST, but thread adjustments are also necessary.

---

## 9. Advantages

1. Inorder traversal without recursion.
2. No auxiliary stack required.
3. Makes use of otherwise unused NULL pointers.
4. Efficient access to inorder predecessor and successor.
5. Double-threaded trees support forward and backward traversal.

## 10. Disadvantages

1. Insertion is more complicated.
2. Deletion requires careful thread maintenance.
3. Additional flags are required.
4. Pointer manipulation is more complex than in a normal BST.

---

## 11. Time and Space Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Inorder traversal | O(n) |
| Find leftmost node | O(h) |
| Find inorder successor | O(h) worst case |
| Search in a threaded BST | O(h) |
| Insertion in a threaded BST | O(h) |
| Deletion in a threaded BST | O(h) |

Here, n represents the number of nodes and h represents the height of the tree.

Inorder traversal uses O(1) auxiliary space because it does not require recursion or a stack.

---

## 12. Important Viva Questions

**Q1. What is a Threaded Binary Tree?**

A binary tree in which NULL pointers are replaced with threads pointing to inorder predecessors or successors.

**Q2. Why do we use Threaded Binary Trees?**

To perform traversal