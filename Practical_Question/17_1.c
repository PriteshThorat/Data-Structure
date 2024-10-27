#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Definition of the stack structure
struct Stack {
    struct Node* top; // Pointer to the top node
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL; // Stack is initially empty
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = stack->top; // Point new node to the previous top
    stack->top = newNode; // Update top to the new node
    printf("Pushed: %d\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return -1; // Return -1 to indicate error
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next; // Update top to the next node
    free(temp); // Free memory of the popped node
    return poppedValue;
}

// Function to display the current state of the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = stack->top;
        printf("Current stack: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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

    push(&stack, 20);
    displayStack(&stack);

    pop(&stack);
    displayStack(&stack);

    return 0;
}
