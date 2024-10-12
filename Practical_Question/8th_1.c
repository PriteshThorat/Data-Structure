#include <stdio.h>
#include <conio.h>

int main() {
    int array[50];
    int n, i, j, min;

    printf("Enter Number of Elements (max 50): ");
    scanf("%d", &n);

    // Validate the input number of elements
    if (n <= 0 || n > 50) {
        printf("Invalid number of elements! Please enter a value between 1 and 50.\n");
        return 1; // Exit with error code
    }

    printf("Enter Array Elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Selection Sort
    for (i = 0; i < n - 1; i++) {
        min = array[i];
        int loc = i;

        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (min > array[j]) {
                min = array[j];
                loc = j; // Update location of the minimum element
            }
        }

        // Swap the found minimum element with the first element
        if (loc != i) {
            int temp = array[i];
            array[i] = array[loc];
            array[loc] = temp;
        }
    }

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }

    getch(); // Wait for a key press
    return 0;
}
