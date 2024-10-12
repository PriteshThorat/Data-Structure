#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

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

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    bubbleSortStrings(arr, n);

    printf("Sorted array of strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
