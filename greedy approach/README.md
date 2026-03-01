# Folder Overview
=====================

This folder contains implementations of various algorithms that utilize the Greedy Approach. The Greedy Approach is a problem-solving strategy that makes the locally optimal choice at each step in the hopes that it will also lead to a global optimum solution.

The folder contains five C programs:

*   `dijkstras.c`: Implementation of Dijkstra's algorithm to find the shortest path in a graph.
*   `jobScheduling.c`: Implementation of a greedy approach to schedule jobs based on profit and deadline.
*   `knapsack.c`: Implementation of a greedy approach to solve the 0/1 Knapsack problem.
*   `kruskal's.c`: Implementation of Kruskal's algorithm for finding the Minimum Spanning Tree in a graph. (Note: The `create` function is not implemented in this version.)
*   `travellingsalesmanproblem.c`: Implementation of a greedy approach to solve the Traveling Salesman Problem.

# File-by-File Explanation
-------------------------

### dijkstras.c

This program implements Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a graph. The program uses an adjacency matrix to represent the graph.

*   The `main` function initializes the graph, selects a source node, and calls the `dijkstra` function to compute the shortest distances and paths.
*   The `dijkstra` function initializes the distances and parent arrays, then repeatedly selects the unvisited node with the minimum distance and updates the distances and parent arrays accordingly.
*   The `minfinder` function finds the unvisited node with the minimum distance.

### jobScheduling.c

This program implements a greedy approach to schedule jobs based on profit and deadline. The program sorts the jobs in descending order of profit and then schedules them based on their deadlines.

*   The `main` function calls the `job` function to schedule the jobs.
*   The `job` function sorts the jobs in descending order of profit, then schedules the jobs based on their deadlines.

### knapsack.c

This program implements a greedy approach to solve the 0/1 Knapsack problem. The program sorts the items in descending order of profit per unit weight and then selects the items that fit in the knapsack.

*   The `main` function calls the `knapsack` function to solve the Knapsack problem.
*   The `knapsack` function sorts the items in descending order of profit per unit weight and then selects the items that fit in the knapsack.

### kruskal's.c

This program implements Kruskal's algorithm for finding the Minimum Spanning Tree in a graph. However, the `create` function is not implemented in this version.

*   The `main` function would call the `create` function to create the graph and then call the `kruskal` function to find the Minimum Spanning Tree.

### travellingsalesmanproblem.c

This program implements a greedy approach to solve the Traveling Salesman Problem. The program finds the minimum cost Hamiltonian cycle in a graph.

*   The `main` function initializes the graph, selects a starting node, and calls the `tsp` function to find the minimum cost Hamiltonian cycle.
*   The `tsp` function tries all possible paths from the current node to the other nodes and recursively calls itself to find the minimum cost Hamiltonian cycle.

# Functions/Classes Explained
-----------------------------

### dijkstras.c

*   `int minfinder(int startnode)`: Finds the unvisited node with the minimum distance.
*   `void dijkstra(int startnode)`: Initializes the distances and parent arrays and finds the shortest paths and distances.

### jobScheduling.c

*   `void job()`: Schedules the jobs based on profit and deadline.

### knapsack.c

*   `void knapsack()`: Schedules the items based on profit per unit weight.

### kruskal's.c

*   `struct edge* create()`: (Not implemented in this version)
*   `int find(int node)`: (Not implemented in this version)
*   `void unionset(int x, int y)`: (Not implemented in this version)
*   `void mst()`: (Not implemented in this version)

### travellingsalesmanproblem.c

*   `void tsp(int city, int count, int cost, int start)`: Finds the minimum cost Hamiltonian cycle.
*   `int minCost` : Stores the current minimum cost.
*   `int bestPath[][]` : Stores the best path.

# Dependencies Used
-------------------

*   None

However, if you're running this code, you would need to link with the `stdio` library, which is included with the C standard library.

# Example Usage
----------------

To run the code, you would need to compile the C programs and run the `main` function from each program.

Here's an example of how to compile and run the code using GCC:

```bash
gcc dijkstra.c -o dijkstra
./dijkstra
```

This would call the `main` function from `dijkstra.c` and print the shortest distances and paths. Similarly, you can compile and run the other programs.

Note: This is a basic example of Greedy Approach in C programming. The examples are simplified for illustration purposes and may not be the most efficient or practical solutions to the problems.