**.\\Search Algorithms**
======================

**Folder Overview**
-----------------

This folder contains a C implementation of a linear search algorithm, a simple and naive method for finding an element in an unsorted array.

### Table of Contents

*   [File-by-File Explanation](#file-by-file-explanation)
*   [Functions/Classes explained](#functionsclasses-explained)
*   [Dependencies used](#dependencies-used)

**File-by-File Explanation**
---------------------------

### `linearSearch.c`

*   **Linear search function**: This C file contains the implementation of a linear search algorithm. The `linearSearch` function iterates through the array from the first element, comparing each element with the target key. If a match is found, the function returns the index of the element.

    **Function Signature**:

    ```c
int linearSearch(int arr[], int size, int key);
```

    **Parameters**:

    *   `arr`: The input array to search in.
    *   `size`: The number of elements in the array.
    *   `key`: The target element to search for.

    **Return Value**: The index of the target element if found, or -1 if not found.

**Functions/Classes explained**
-------------------------------

### `linearSearch`

*   This function performs a linear search on the input array using a simple iterative approach.
*   The function takes three parameters: the input array, its size, and the target key to search for.
*   It iterates through the array, comparing each element with the target key.
*   If a match is found, the function returns the index of the target element.
*   If the loop completes without finding a match, the function returns -1 to indicate that the element was not found.

### `main`

*   This is the entry point of the program.
*   In the `main` function, we define an example array `arr` containing some sample elements.
*   We calculate the size of the array by using the `sizeof` operator and dividing it by the size of each element.
*   We define the target key `key_to_find` as 30, which is an element present in the array.
*   We call the `linearSearch` function with the array, its size, and the target key as arguments.
*   Based on the return value of the `linearSearch` function, we print the result whether the element was found or not.
*   We repeat the process by searching for an element not present in the array (100) to demonstrate the function's behavior.

**Dependencies used**
---------------------

*   The `stdio.h` header file is included to provide input/output functions such as `printf`.
*   No other external libraries or dependencies are required to build and run this code.

To build and run the code, save the `linearSearch.c` file in a location of your choice, navigate to that location in your terminal or command prompt, and compile the code using a C compiler, such as `gcc`, like so:

```bash
gcc linearSearch.c -o linearSearch.exe
```

After compilation, you can execute the `main` function by running the generated executable:

```bash
./linearSearch.exe
```

The output will display the results of searching for the specified key in the array.

```console
Element 30 found at index: 2
Element 100 not found in the array.
```