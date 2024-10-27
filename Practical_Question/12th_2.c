#include <stdio.h>
#include <stdlib.h>

// Definition of the singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to detect cycle and find the starting node of the cycle
struct Node* detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // First phase: Detect if a cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            // Second phase: Find the start of the cycle
            struct Node* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;  // Entry is the start of the cycle
        }
    }
    return NULL;  // No cycle detected
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list (useful for debugging if no cycle exists)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Creating a cycle for testing
    head->next->next->next->next->next = head->next->next;

    struct Node* cycleStart = detectCycle(head);
    if (cycleStart != NULL) {
        printf("Cycle detected starting at node with data: %d\n", cycleStart->data);
    } else {
        printf("No cycle detected\n");
    }

    return 0;
}
