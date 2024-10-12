#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid == target) {
            return arr[mid];
        } else if (mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // This shouldn't occur for valid middle indices
}

int main() {
    int arr[15], i;

    printf("Enter 15 sorted integers: \n");
    for (i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }

    // Middle elements are at index 7 and 8 (0-based indexing)
    int middleIndex1 = 7;
    int middleIndex2 = 8;

    // Find the two middle elements using binary search
    int middleElement1 = binarySearch(arr, 15, middleIndex1);
    int middleElement2 = binarySearch(arr, 15, middleIndex2);

    printf("The middle elements are: %d and %d\n", middleElement1, middleElement2);

    return 0;
}
