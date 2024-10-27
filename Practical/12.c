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

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head; // Point the new node to the current head
    *head = newNode;       // Update the head to the new node
}

// Function to search for a node in the linked list
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Key found
        }
        current = current->next;
    }
    return 0; // Key not found
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

    // Insert some nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Display the linked list
    display(head);

    // Search for a key in the linked list
    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);
    
    if (search(head, key)) {
        printf("Value %d found in the linked list.\n", key);
    } else {
        printf("Value %d not found in the linked list.\n", key);
    }

    // Clean up and free the memory
    freeList(head);
    return 0;
}

/*[?2004l
Linked List: 30 -> 20 -> 10 -> NULL
Enter the value to search: 20
Value 20 found in the linked list.
[?2004h*/