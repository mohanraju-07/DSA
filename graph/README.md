**README.md**

**Folder Overview**
================

This folder contains C implementations for various graph algorithms and data structures. It includes implementations for detecting cycles in a graph, Depth-First Search (DFS), Breadth-First Search (BFS), and Prim's algorithm for finding the minimum spanning tree.

**File-by-File Explanation**
================-----------

### detectingcycle.c

This file implements a function `cycle` to detect whether a cycle exists in a directed or undirected graph. The graph is represented using an adjacency list, and the function uses a queue to perform a traversal of the graph.

*   `create` function is used to create a new linked list node.
*   `creategraph` function is used to create a new graph with a specified number of vertices.
*   `addedge` function is used to add a new edge between two vertices in the graph.
*   `printGraph` function is used to print the adjacency list representation of the graph.
*   `enqueue` function is used to add a new element to the end of the queue.
*   `dequeue` function is used to remove an element from the front of the queue.
*   `cycle` function is used to detect whether a cycle exists in the graph.

### dfs.c

This file implements a function `dfs` to perform a Depth-First Search traversal of a graph represented using an adjacency matrix.

*   `addEdge` function is used to add a new edge between two vertices in the graph.
*   `display` function is used to print the adjacency matrix representation of the graph.
*   `dfs` function is used to perform a DFS traversal of the graph starting from a specified node.

### graph.c

This file implements a function `bfs` to perform a Breadth-First Search traversal of a graph represented using an adjacency matrix.

*   `addEdge` function is used to add a new edge between two vertices in the graph.
*   `display` function is used to print the adjacency matrix representation of the graph.
*   `enqueue` function is used to add a new element to the end of the queue.
*   `dequeue` function is used to remove an element from the front of the queue.
*   `bfs` function is used to perform a BFS traversal of the graph starting from a specified node.

### prims.c

This file implements a function `prims` to find the minimum spanning tree of a graph represented using an adjacency matrix.

*   `min` function is used to find the vertex with the minimum key value.
*   `prims` function is used to find the minimum spanning tree of the graph.

### primssample.c

This file implements an example usage of Prim's algorithm for finding the minimum spanning tree of a graph.

*   `g` is an adjacency matrix representing the graph.
*   `minKey` function is used to find the vertex with the minimum key value.

**Dependencies Used**
================

This code uses the following C standard library functions:

*   `malloc` to dynamically allocate memory.
*   `printf` to print to the console.
*   `scanf` to read input from the user (not used in this code).
*   `exit` to terminate the program.

The code also uses the following custom functions:

*   `create` to create a new linked list node.
*   `creategraph` to create a new graph with a specified number of vertices.
*   `addedge` to add a new edge between two vertices in the graph.
*   `printGraph` to print the adjacency list representation of the graph.
*   `enqueue` to add a new element to the end of the queue.
*   `dequeue` to remove an element from the front of the queue.
*   `min` to find the vertex with the minimum key value.
*   `bfs` to perform a BFS traversal of the graph starting from a specified node.
*   `dfs` to perform a DFS traversal of the graph starting from a specified node.
*   `prims` to find the minimum spanning tree of the graph.
*   `minKey` to find the vertex with the minimum key value.

Note: The code assumes that the graph is represented using an adjacency list or adjacency matrix. The code also assumes that the graph is connected, unless explicitly stated otherwise.