#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Define the priority queue structure
struct PriorityQueue {
    struct Node* front;
};

// Function to create and initialize the priority queue
struct PriorityQueue* createQueue() {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->front = NULL;
    return queue;
}

// Function to add an element to the priority queue (enqueue)
void enqueue(struct PriorityQueue* queue, int value, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    // If the queue is empty or the new node has higher priority than the front
    if (queue->front == NULL || priority > queue->front->priority) {
        newNode->next = queue->front; // Point to the current front
        queue->front = newNode;        // Make new node the front
    } else {
        // Traverse the queue to find the appropriate position
        struct Node* current = queue->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next; // Move to the next node
        }
        newNode->next = current->next; // Insert the new node in the correct position
        current->next = newNode;
    }

    printf("Enqueued: %d with priority: %d\n", value, priority);
}

// Function to remove an element from the priority queue (dequeue)
int dequeue(struct PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Return -1 to indicate the queue is empty
    }

    struct Node* temp = queue->front; // Node to be dequeued
    int dequeuedValue = temp->data;   // Save the value to return
    queue->front = queue->front->next; // Move front to the next node
    free(temp); // Free the dequeued node

    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the current priority queue
void displayQueue(struct PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    
    struct Node* temp = queue->front;
    printf("Current Priority Queue: ");
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the priority queue
void freeQueue(struct PriorityQueue* queue) {
    struct Node* current = queue->front;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(queue);
}

int main() {
    struct PriorityQueue* queue = createQueue();

    // Enqueue elements with priorities
    enqueue(queue, 10, 1);
    enqueue(queue, 20, 3);
    enqueue(queue, 30, 2);
    displayQueue(queue);

    // Dequeue elements
    dequeue(queue);
    displayQueue(queue);

    dequeue(queue);
    displayQueue(queue);

    dequeue(queue);
    displayQueue(queue);

    // Attempt to dequeue from an empty queue (underflow)
    dequeue(queue);

    // Clean up
    freeQueue(queue);
    return 0;
}
