#include <stdio.h>
#include <string.h>

void printArray(char array[][50], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}

void insertionSortStep(char array[][50], int n, int step) {
    char key[50];
    int j;
    strcpy(key, array[step]);
    j = step - 1;

    while (j >= 0 && strcmp(array[j], key) > 0) {
        strcpy(array[j + 1], array[j]);
        j--;
    }
    strcpy(array[j + 1], key);

    printf("Step %d: ", step);
    printArray(array, n);
}

int main() {
    char array[50][50];
    int n, step = 1;
    int choice;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    printf("Enter strings: \n");
    for (int i = 0; i < n; i++) {
        scanf("%s", array[i]);
    }

    printf("\nInitial Array: ");
    printArray(array, n);

    while (step < n) {
        printf("Continue sorting (1-yes, 0-no): ");
        scanf("%d", &choice);

        if (choice == 1) {
            insertionSortStep(array, n, step);
            step++;
        } else {
            break;
        }
    }

    printf("\nFinal Sorted Array: ");
    printArray(array, n);

    return 0;
}
