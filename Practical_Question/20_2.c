#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

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

// Recursive function to calculate the length of the linked list
int lengthOfList(struct Node* head) {
    if (head == NULL) {
        return 0; // Base case: end of the list
    }
    
    // Recursive case: 1 + length of the rest of the list
    return 1 + lengthOfList(head->next);
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Calculate and print the length of the linked list
    int length = lengthOfList(head);
    printf("Length of the linked list: %d\n", length);

    // Free allocated memory (optional)
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
