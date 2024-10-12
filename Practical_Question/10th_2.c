#include <stdio.h>

// Function to count inversions using insertion sort
int insertionSortCountInversions(int array[], int n) {
    int i, j, key, inversions = 0;

    // Traverse through 1 to n-1
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        // Move elements of array[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];  // Shift element to the right
            j = j - 1;
            inversions++;  // Count the inversion
        }
        array[j + 1] = key;  // Insert the current element into its correct position
    }
    return inversions;
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {8, 4, 2, 1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original Array: \n");
    printArray(array, n);

    int inversions = insertionSortCountInversions(array, n);

    printf("Sorted Array: \n");
    printArray(array, n);

    printf("Number of Inversions: %d\n", inversions);

    return 0;
}
