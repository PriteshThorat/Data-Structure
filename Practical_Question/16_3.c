#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Stack structure to hold characters
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1; // Stack is initially empty
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push %c\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character to indicate error
    }
    return stack->arr[stack->top--];
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    struct Stack stack;
    initializeStack(&stack);

    // Push each character onto the stack (consider only alphanumeric characters)
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            push(&stack, tolower(str[i])); // Convert to lowercase and push
        }
    }

    // Compare characters from the stack with the original string
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            if (tolower(str[i]) != pop(&stack)) {
                return 0; // Not a palindrome
            }
        }
    }
    return 1; // It is a palindrome
}

int main() {
    char str[MAX];

    // Input string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character if present

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
