#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    // Iterate through the array from the first element
    for (int i = 0; i < size; i++) {
        // If the current element matches the key, return its index
        if (arr[i] == key) {
            return i; // Element found at index i
        }
    }
    // If the loop completes and the key is not found, return -1
    return -1; // Element not found
}

int main() {
    int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);
    int key_to_find = 30;

    // Call the linearSearch function
    int result_index = linearSearch(arr, size, key_to_find);

    // Print the result based on the return value
    if (result_index == -1) {
        printf("Element %d not found in the array.\n", key_to_find);
    } else {
        printf("Element %d found at index: %d\n", key_to_find, result_index);
    }

    // Example with an element not present
    key_to_find = 100;
    result_index = linearSearch(arr, size, key_to_find);
    if (result_index == -1) {
        printf("Element %d not found in the array.\n", key_to_find);
    } else {
        printf("Element %d found at index: %d\n", key_to_find, result_index);
    }

    return 0;
}