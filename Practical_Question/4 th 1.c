#include <stdio.h>
#include <conio.h>

int main() {
    int i, array[20], first = -1, last = -1, mid;
    int find = 3;
    int n = 20;

    printf("Enter Array (sorted): \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Finding the first occurrence
    int left = 0, right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;

        if (array[mid] < find) {
            left = mid + 1;
        } else if (array[mid] > find) {
            right = mid - 1;
        } else {
            first = mid;   // found the element, but continue searching left
            right = mid - 1;
        }
    }

    // Finding the last occurrence
    left = 0;
    right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;

        if (array[mid] < find) {
            left = mid + 1;
        } else if (array[mid] > find) {
            right = mid - 1;
        } else {
            last = mid;   // found the element, but continue searching right
            left = mid + 1;
        }
    }

    if (first == -1) {
        printf("Element %d not found in the array.\n", find);
    } else {
        printf("First Occurrence: %d\n", first);
        printf("Last Occurrence: %d\n", last);
    }

    getch();
    return 0;
}
