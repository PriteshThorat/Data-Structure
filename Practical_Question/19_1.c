#include <stdio.h>
#include <string.h>

// Function to check if the string is a palindrome recursively
int isPalindrome(char str[], int left, int right) {
    // Base case: if left index is greater than or equal to right index
    if (left >= right) {
        return 1; // It's a palindrome
    }
    
    // Check characters at the left and right indices
    if (str[left] != str[right]) {
        return 0; // Not a palindrome
    }

    // Recursive case: check the next pair of characters
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    char str[100];

    // Input string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character if present

    // Calculate the length of the string
    int length = strlen(str);

    // Check if the string is a palindrome
    if (isPalindrome(str, 0, length - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
