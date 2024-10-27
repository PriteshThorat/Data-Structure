#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return '\0'; // Return null character to indicate error
    }
    return stack->arr[stack->top--];
}

// Function to reverse a string using stack
void reverseString(char* str) {
    struct Stack stack;
    initializeStack(&stack);

    // Push each character onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    // Pop characters from the stack and place them back in the string
    int i = 0;
    while (!isEmpty(&stack)) {
        str[i++] = pop(&stack);
    }
    str[i] = '\0'; // Null-terminate the reversed string
}

int main() {
    char str[MAX];

    // Input string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character if present

    // Reverse the string
    reverseString(str);

    // Display the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
