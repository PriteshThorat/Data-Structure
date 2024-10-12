#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int binarySearch(char arr[][MAX_LENGTH], int n, char target[]) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0) {
            return mid; // Target string found
        } else if (cmp < 0) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Target string not found
}

int main() {
    int n, i;
    char arr[MAX_STRINGS][MAX_LENGTH], target[MAX_LENGTH];

    printf("Enter the number of strings (max %d): ", MAX_STRINGS);
    scanf("%d", &n);

    printf("Enter %d sorted strings:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    printf("Enter the target string to search for: ");
    scanf("%s", target);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        printf("Target string '%s' found at index %d.\n", target, result);
    } else {
        printf("Target string '%s' not found.\n", target);
    }

    return 0;
}
