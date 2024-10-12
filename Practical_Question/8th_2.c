#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, j, minIndex;
    float array[50], min;

    printf("Enter Number of Elements (max 50): ");
    scanf("%d", &n);

    // Validate input number of elements
    if (n <= 0 || n > 50) {
        printf("Invalid number of elements! Please enter a value between 1 and 50.\n");
        return 1; // Exit with error code
    }

    printf("Enter Array of Floating-Point Numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    // Selection Sort for floating-point numbers
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        min = array[i];

        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (array[j] < min) {
                min = array[j];
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (minIndex != i) {
            float temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\n", array[i]);
    }

    getch(); // Wait for a key press
    return 0;
}
