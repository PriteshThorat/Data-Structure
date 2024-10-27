#include <stdio.h>

// Function to calculate the sum of numbers from 1 to n recursively
int sum(int n) {
    if (n == 1) {
        return 1; // Base case: sum(1) = 1
    } else {
        return n + sum(n - 1); // Recursive case: n + sum of numbers from 1 to n-1
    }
}

int main() {
    int n;

    // Input the value of n
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check for valid input
    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
    } else {
        // Calculate and print the sum
        int result = sum(n);
        printf("The sum of numbers from 1 to %d is: %d\n", n, result);
    }

    return 0;
}
