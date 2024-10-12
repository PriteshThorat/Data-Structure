#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

// Function to check if a string contains only valid characters (a-z, A-Z)
int isValidString(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;  // Invalid character found
        }
    }
    return 1;  // Valid string
}

void bubbleSortStrings(char arr[][MAX_LENGTH], int n) {
    int i, j;
    char temp[MAX_LENGTH];
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;  // Reset the swap flag before each pass

        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap arr[j] and arr[j + 1] (lexicographical order)
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);

                swapped = 1;  // Mark as swapped
            }
        }

        // If no swaps occurred during the pass, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n, i;
    char arr[MAX_STRINGS][MAX_LENGTH];

    printf("Enter the number of strings (max %d): ", MAX_STRINGS);
    scanf("%d", &n);

    // Validate the number of strings
    if (n <= 0 || n > MAX_STRINGS) {
        printf("Invalid number of strings. Please enter a number between 1 and %d.\n", MAX_STRINGS);
        return 1;  // Exit the program with an error code
    }

    printf("Enter %d strings (max length %d, alphabetic characters only):\n", n, MAX_LENGTH - 1);

    // Read and validate each string
    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i]);

        // Check if the string exceeds the maximum length
        if (strlen(arr[i]) >= MAX_LENGTH) {
            printf("Error: String exceeds maximum length of %d characters. Please re-enter.\n", MAX_LENGTH - 1);
            i--;  // Repeat the input for this index
            continue;
        }

        // Check if the string contains only alphabetic characters
        if (!isValidString(arr[i])) {
            printf("Error: Invalid characters in string. Only alphabetic characters are allowed. Please re-enter.\n");
            i--;  // Repeat the input for this index
        }
    }

    // Sort the strings
    bubbleSortStrings(arr, n);

    printf("Sorted array of strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
