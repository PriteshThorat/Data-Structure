#include <stdio.h>

// Function to perform binary search to find the correct position for the current element
int binarySearch(int array[], int item, int low, int high) {
    if (high <= low) {
        return (item > array[low]) ? (low + 1) : low;
    }
    int mid = (low + high) / 2;

    if (item == array[mid])
        return mid + 1;
    
    if (item > array[mid])
        return binarySearch(array, item, mid + 1, high);
    
    return binarySearch(array, item, low, mid - 1);
}

// Function to perform modified insertion sort using binary search for finding positions
void insertionSortBinarySearch(int array[], int n) {
    int i, j, selected, pos;

    for (i = 1; i < n; i++) {
        selected = array[i];

        // Find location where the selected element should be inserted using binary search
        pos = binarySearch(array, selected, 0, i - 1);

        // Move all elements after location to one position ahead to make space for the element
        for (j = i - 1; j >= pos; j--) {
            array[j + 1] = array[j];
        }
        array[pos] = selected;
    }
}

// Function to perform standard insertion sort
void insertionSort(int array[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        // Move elements of array[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array1[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88};
    int array2[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88};
    int n = sizeof(array1) / sizeof(array1[0]);

    printf("Original Array: \n");
    printArray(array1, n);

    // Perform standard insertion sort
    insertionSort(array1, n);
    printf("\nSorted Array using Standard Insertion Sort: \n");
    printArray(array1, n);

    // Perform modified insertion sort with binary search
    insertionSortBinarySearch(array2, n);
    printf("\nSorted Array using Insertion Sort with Binary Search: \n");
    printArray(array2, n);

    return 0;
}
