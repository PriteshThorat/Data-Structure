#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the circular queue

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create and initialize the circular queue
struct CircularQueue* createQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (queue->front == -1) {
        // Initialize front if the queue was empty
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Return -1 to indicate the queue is empty
    }

    int dequeuedValue = queue->items[queue->front];

    // If there's only one element left, reset the queue
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        // Circular increment
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the current queue
void displayQueue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Current Queue: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->items[i]);
        if (i == queue->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    struct CircularQueue* queue = createQueue();

    // Attempt to dequeue from an empty queue (underflow)
    dequeue(queue);

    // Enqueue elements
    enqueue(queue, 15);
    enqueue(queue, 48);
    enqueue(queue, 69);
    displayQueue(queue);

    // Attempt to enqueue beyond capacity (overflow)
    enqueue(queue, 12);
    enqueue(queue, 23);
    enqueue(queue, 34); // This should trigger overflow

    // Display the queue
    displayQueue(queue);

    // Dequeue all elements
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); // This should trigger underflow

    // Clean up
    free(queue);
    return 0;
}
