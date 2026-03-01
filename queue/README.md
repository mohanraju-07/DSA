# README.md

## Folder Overview
====================================================

The `queue` folder contains a simple implementation of a queue data structure in C. A queue is a fundamental data structure that follows the First-In-First-Out (FIFO) principle, where the first element that is inserted into the queue will be the first one to be removed.

## File-by-File Explanation
==========================

### queue.c
----------------

This file implements a queue with the following features:

*   `queue`: an array that stores the elements of the queue.
*   `front`: an index indicating the position of the front element of the queue.
*   `rear`: an index indicating the position of the rear element of the queue.

### Functions/Classes Explained
-----------------------------

#### `insert(int data)`
-------------------------

*   **Purpose:** Adds an element to the end of the queue.
*   **Parameters:** `data` - the element to be added to the queue.
*   **Returns:** None.
*   **Description:** If the queue is full, an error message is printed. Otherwise, the element is added to the queue, and its presence is confirmed by a success message.
*   **Example usage:** `insert(10);`

#### `display()`
----------------

*   **Purpose:** Displays all elements in the queue.
*   **Parameters:** None.
*   **Returns:** None.
*   **Description:** If the queue is empty, an error message is printed. Otherwise, all elements in the queue are printed, starting from the front position and ending at the rear position.
*   **Example usage:** `display();`

#### `main()`
------------

*   **Purpose:** Demonstrates the usage of the queue implementation.
*   **Parameters:** None.
*   **Returns:** None.
*   **Description:** In the `main()` function, two elements (10 and 3) are inserted into the queue using the `insert()` function. The `display()` function is then called to show the elements in the queue.

## Dependencies Used
---------------------

The implementation uses the following C standard library functions:

*   `printf()` for printing messages and error messages.
*   `scanf()` is not used, as the inputs are hardcoded values.

Note that this implementation uses a fixed-size array `queue` to store the elements of the queue. A more robust implementation would use a dynamic data structure, such as a linked list, to accommodate variable-sized arrays.

To compile and run this code, create a new C file (e.g., `main.c`) that includes the `queue.c` file and implements the `main()` function as follows:
```c
#include "queue.c"
#include <stdio.h>

int main() {
    // Your implementation here
    return 0;
}
```
Then, compile and run the code using the following commands:
```bash
gcc main.c queue.c -o queue_example
./queue_example
```
This will demonstrate the usage of the queue implementation and print the elements in the queue.