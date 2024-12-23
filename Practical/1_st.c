#include <stdio.h>

void createArray(int arr[], int n) {
    int i;
    printf("Enter elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void insertElement(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos > n) {
        printf("Invalid position for insertion.\n");
        return;
    }
    int i;
    for (i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = value;
}

void deleteElement(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position for deletion.\n");
        return;
    }
    int i;
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

void displayArray(int arr[], int n) {
    int i;
    printf("Array elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, choice, pos, value;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    createArray(arr, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                insertElement(arr, n, pos, value);
                n++;
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, n, pos);
                n--;
                break;
            case 3:
                displayArray(arr, n);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

/*[?2004l
Enter the size of the array: 3
Enter elements of the array:
2
4
7

Menu:
1. Insert
2. Delete
3. Display
Enter your choice: 1
Enter position and value to insert: 2
5

Menu:
1. Insert
2. Delete
3. Display
Enter your choice: 2
Enter position to delete: 1

Menu:
1. Insert
2. Delete
3. Display
Enter your choice: 3
Array elements:
2 5 7 

Menu:
1. Insert
2. Delete
3. Display
Enter your choice: */