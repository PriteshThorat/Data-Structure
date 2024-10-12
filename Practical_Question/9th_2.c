#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 50   // Maximum number of strings
#define MAX_LENGTH 100   // Maximum length of each string

// Function to perform selection sort on an array of strings (case-insensitive)
void selectionSort(char array[MAX_STRINGS][MAX_LENGTH], int n) {
    int i, j, minIndex;
    char minString[MAX_LENGTH];

    // Traverse through the array
    for (i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        minIndex = i;
        strcpy(minString, array[i]);

        // Find the minimum string in the remaining unsorted array
        for (j = i + 1; j < n; j++) {
            // Use strcasecmp for case-insensitive comparison
            if (strcasecmp(array[j], minString) < 0) {
                strcpy(minString, array[j]);
                minIndex = j;
            }
        }

        // Swap the found minimum string with the first string of the unsorted part
        if (minIndex != i) {
            char temp[MAX_LENGTH];
            strcpy(temp, array[i]);
            strcpy(array[i], array[minIndex]);
            strcpy(array[minIndex], temp);
        }
    }
}

int main() {
    int n, i;
    char array[MAX_STRINGS][MAX_LENGTH];

    printf("Enter Number of Strings (max %d): ", MAX_STRINGS);
    scanf("%d", &n);

    // Input validation
    if (n <= 0 || n > MAX_STRINGS) {
        printf("Invalid number of strings! Please enter a value between 1 and %d.\n", MAX_STRINGS);
        return 1; // Exit with error code
    }

    // Input the strings
    printf("Enter the Strings (max length %d):\n", MAX_LENGTH - 1);
    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", array[i]);
    }

    // Sort the array using selection sort
    selectionSort(array, n);

    // Output the sorted array
    printf("\nSorted Array of Strings (Case-Insensitive):\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }

    return 0;
}
