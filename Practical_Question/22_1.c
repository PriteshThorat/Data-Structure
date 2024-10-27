#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create and initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // Queue is empty, both front and rear will point to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Add the new node at the end and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1; // Return -1 to indicate the queue is empty
    }

    struct Node* temp = queue->front;
    int dequeuedValue = temp->data;

    // Move front to the next node
    queue->front = queue->front->next;

    // If front becomes NULL, then update rear to NULL as well
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp); // Free the memory of the dequeued node
    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the current queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = queue->front;
    printf("Current Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    // Perform the specified operations
    enqueue(queue, 15);
    enqueue(queue, 48);
    enqueue(queue, 69);
    displayQueue(queue);

    dequeue(queue);
    enqueue(queue, 12);
    enqueue(queue, 23);
    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);

    // Clean up
    free(queue);
    return 0;
}
