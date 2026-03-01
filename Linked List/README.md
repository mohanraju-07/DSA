**README.md**

# Folder Overview

This folder contains implementations of three different types of linked lists:

* `circularlinkedlist.c`: contains an implementation of a singly-linked list where the last node points back to the head of the list.
* `doublylinked.c`: contains an implementation of a doubly-linked list where each node maintains references to both the next and previous nodes.
* `linkedlist.c`: contains a basic implementation of a singly-linked list.

These files demonstrate various operations such as insertion, deletion, and traversal on these linked list data structures.

# File-by-File Explanation

## circularlinkedlist.c

This file contains an implementation of a singly-linked list in a circular manner. The last node in the list points back to the head of the list, forming a circle.

### Functions

* `create(int data)`: creates a new node with the specified data.
* `insert(int data, int pos, struct ll* first)`: inserts a new node at the specified position in the list.
* `delete(int data, struct ll* first)`: deletes the node with the specified data from the list.

### Example Use Cases

* Creating a circular-linked list with nodes containing data 10, 20, 30
* Inserting new nodes at positions 0 and 3
* Deleting nodes with data 1, 25, and 30

## doublylinked.c

This file contains an implementation of a doubly-linked list, where each node maintains references to both the next and previous nodes.

### Functions

* `create(int data)`: creates a new node with the specified data.
* `insertion(int data, int pos, struct dll* head)`: inserts a new node at the specified position in the list.
* `delete(int data, struct dll* head)`: deletes the node with the specified data from the list.
* `traverse(int way, struct dll* head)`: prints the list in the specified direction (forward or backward).

### Example Use Cases

* Creating a doubly-linked list with nodes containing data 10, 20
* Inserting new nodes at positions 0, 1, and -1 (appending to the end)
* Deleting nodes with data 20
* Traversing the list in both forward and backward directions

## linkedlist.c

This file contains a basic implementation of a singly-linked list.

### Functions

* `create(int data)`: creates a new node with the specified data.
* `search(int data, struct linkedlist* node)`: searches for a node with the specified data.
* `insertion(int pos, int data, struct linkedlist* head)`: inserts a new node at the specified position in the list.

### Example Use Cases

* Creating a linked list with nodes containing data 10, 20, 30
* Inserting new nodes at positions 0 and 2
* Searching for a node with data 20

# Dependencies used

* `stdio.h` for input/output operations
* `stdlib.h` for memory management functions (malloc, free)

# Compile and Run Instructions

To compile and run the code, use the following commands in your terminal:

```bash
gcc circularlinkedlist.c -o circularlinkedlist
./circularlinkedlist

gcc doublylinked.c -o doublylinked
./doublylinked

gcc linkedlist.c -o linkedlist
./linkedlist
```