README.md
==========

### Folder Overview

This folder contains C implementations of various tree data structures, including:

*   **AVL Tree**: Self-balancing binary search tree that maintains a balance between the height of the left and right subtrees.
*   **Binary Search Tree (BST)**: Basic binary tree where elements are inserted in ascending order and search, insert, and delete operations can be performed efficiently.
*   **Complete Binary Tree (CBT)**: Tree where every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
*   **Tree Traversal**: Basic tree traversal functions to perform inorder, preorder, and postorder traversals.

### File-by-File Explanation

#### **avl.c**

*   **Overview**:
    *   Implements an AVL tree to maintain balance between left and right subtrees.
    *   Provides functions for inserting nodes, calculating height, performing rotations, and performing an inorder traversal.
*   **Key Functions**:
    *   `create(int data)`: Allocates memory for a new node and initializes it with the given data.
    *   `insert(struct tree* root, int data)`: Inserts a new node into the AVL tree while maintaining balance.
    *   `height(struct tree* root)`: Calculates the height of the AVL tree.
    *   `rightrotate(struct tree* node)`: Performs a right rotation on the given node.
    *   `leftrotate(struct tree* node)`: Performs a left rotation on the given node.

#### **BST.c**

*   **Overview**:
    *   Implements a basic Binary Search Tree (BST) to efficiently search, insert, and delete elements.
*   **Key Functions**:
    *   `create(int data)`: Allocates memory for a new node and initializes it with the given data.
    *   `insert(struct tree* root, int data)`: Inserts a new node into the BST.
    *   `inorder(struct tree* root)`: Performs an inorder traversal of the BST.

#### **completeBT.c**

*   **Overview**:
    *   Implements a Complete Binary Tree (CBT) to check if a tree is full.
*   **Key Functions**:
    *   `checkFBT(struct tree* root)`: Checks if the given tree is a full binary tree.
*   **Example Usage**: Demonstrates how to create a CBT and call the `checkFBT` function to check if it's a full binary tree.

#### **tree.c**

*   **Overview**:
    *   Implements basic tree functions for creating nodes, performing traversals, and calculating height.
*   **Key Functions**:
    *   `create(int data)`: Allocates memory for a new node and initializes it with the given data.
    *   `inorder(struct tree* root)`: Performs an inorder traversal of the tree.
    *   `height(struct tree* root)`: Calculates the height of the tree.
    *   `lvl(int data, struct tree* root)`: Checks if a value exists in a binary tree.

### Functions/Classes explained

*   **Inorder Traversal**: Prints the values of a tree in ascending order.
*   **Insertion**: Inserts a new node into a tree while maintaining balance.
*   **Rotation**: Performs rotations on a tree to maintain balance.
*   **Height Calculation**: Calculates the height of a tree.
*   **Full Binary Tree Check**: Checks if a tree is a full binary tree.

### Dependencies used

*   None (pure C implementations)
*   **malloc**: Allocates memory for new nodes.
*   **scanf**: Reads input from the user for node creation and insertion.
*   **printf**: Prints output from tree traversals and other operations.