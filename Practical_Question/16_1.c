#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
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

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed: %d\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return -1; // Return -1 to indicate error
    }
    return stack->arr[stack->top--];
}

// Function to display the current state of the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Current stack: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Perform stack operations
    push(&stack, 10);
    push(&stack, 20);
    displayStack(&stack);

    pop(&stack);
    displayStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    displayStack(&stack);

    pop(&stack);
    displayStack(&stack);

    pop(&stack);
    displayStack(&stack);

    pop(&stack);
    displayStack(&stack);

    push(&stack, 20);
    displayStack(&stack);

    pop(&stack);
    displayStack(&stack);

    return 0;
}
