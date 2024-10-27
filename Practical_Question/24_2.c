#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Define the circular queue structure
struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

// Function to create and initialize the circular queue
struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct CircularQueue* queue, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // If the queue is empty, initialize front and rear
    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = queue->front; // Point to itself
    } else {
        // Add the new node to the end and update the rear
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front; // Make it circular
    }

    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Return -1 to indicate the queue is empty
    }

    int dequeuedValue = queue->front->data;
    struct Node* temp = queue->front;

    // If there is only one node in the queue
    if (queue->front == queue->rear) {
        queue->front = NULL; // Queue is now empty
        queue->rear = NULL;  // Rear should also be NULL
    } else {
        // Move the front pointer to the next node
        queue->front = queue->front->next;
        queue->rear->next = queue->front; // Update rear's next to point to new front
    }

    free(temp); // Free the dequeued node
    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the current queue
void displayQueue(struct CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Current Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

// Function to free the queue
void freeQueue(struct CircularQueue* queue) {
    if (queue->front == NULL) return;

    struct Node* current = queue->front;
    struct Node* nextNode;
    
    // Loop until all nodes are deleted
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != queue->front);
    
    free(queue);
}

int main() {
    struct CircularQueue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
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
