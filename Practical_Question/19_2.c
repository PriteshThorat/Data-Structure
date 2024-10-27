#include <stdio.h>

// Recursive function to copy a string
void copyString(char *source, char *destination) {
    // Base case: if the source string reaches the null character
    if (*source == '\0') {
        *destination = '\0'; // Null-terminate the destination string
        return;
    }

    // Copy current character from source to destination
    *destination = *source;

    // Recursive call for the next character
    copyString(source + 1, destination + 1);
}

int main() {
    char source[100], destination[100];

    // Input string from the user
    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0; // Remove the newline character if present

    // Copy the source string to destination using recursion
    copyString(source, destination);

    // Print the copied string
    printf("Copied string: %s\n", destination);

    return 0;
}
