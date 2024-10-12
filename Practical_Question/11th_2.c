#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of vowels in a string
int countVowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Custom comparison function that compares based on the number of vowels
int compareByVowels(const char *str1, const char *str2) {
    int vowels1 = countVowels(str1);
    int vowels2 = countVowels(str2);
    
    return vowels1 - vowels2;  // Sorting in ascending order of vowel count
}

// Function to perform insertion sort with a custom comparison function
void insertionSort(char array[][50], int n) {
    for (int i = 1; i < n; i++) {
        char key[50];
        strcpy(key, array[i]);
        int j = i - 1;

        // Use custom comparison to find the correct position
        while (j >= 0 && compareByVowels(array[j], key) > 0) {
            strcpy(array[j + 1], array[j]);
            j--;
        }
        strcpy(array[j + 1], key);
    }
}

// Function to print the array of strings
void printArray(char array[][50], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }
}

int main() {
    char array[50][50];
    int n;

    // Read input strings
    printf("Enter number of strings: ");
    scanf("%d", &n);
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", array[i]);
    }

    // Sort the strings using insertion sort and the custom comparison function
    insertionSort(array, n);

    // Print the sorted array
    printf("\nStrings sorted by number of vowels:\n");
    printArray(array, n);

    return 0;
}
