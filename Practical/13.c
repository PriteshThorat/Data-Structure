#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If the list is empty, make the new node the head
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next; // Traverse to the end of the list
    }
    current->next = newNode; // Link the new node at the end
}

// Function to insert a node after a specific node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next; // Link new node to the next of prevNode
    prevNode->next = newNode;       // Link prevNode to the new node
}

// Function to delete a node with a specific value
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* previous = NULL;

    // If the head node itself holds the key
    if (current != NULL && current->data == key) {
        *head = current->next; // Change head
        free(current);         // Free the old head
        return;
    }

    // Search for the key to be deleted
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // If the key was not present in the list
    if (current == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from the linked list
    previous->next = current->next;
    free(current); // Free the memory of the deleted node
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the allocated memory for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next; // Store the next node
        free(current);            // Free the current node
        current = nextNode;      // Move to the next node
    }
}

int main() {
    struct Node* head = NULL; // Initialize the head of the linked list

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    display(head);

    // Insert a node after a specific node (20)
    insertAfter(head->next, 25);
    display(head);

    // Delete a node
    printf("Deleting 20 from the list.\n");
    deleteNode(&head, 20);
    display(head);

    // Try to delete a node that doesn't exist
    printf("Trying to delete 100 from the list.\n");
    deleteNode(&head, 100);
    display(head);

    // Clean up and free the memory
    freeList(head);
    return 0;
}

/*[?2004l
Linked List: 10 -> 20 -> 30 -> NULL
Linked List: 10 -> 20 -> 25 -> 30 -> NULL
Deleting 20 from the list.
Linked List: 10 -> 25 -> 30 -> NULL
Trying to delete 100 from the list.
Value 100 not found in the list.
Linked List: 10 -> 25 -> 30 -> NULL
[?2004h*/