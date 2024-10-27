#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Define the maximum size of the queue

// Structure to represent a queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create and initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0; // Initialize front if the queue was empty
    }
    queue->rear++;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1; // Return -1 to indicate the queue is empty
    }
    int dequeuedValue = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        // Reset the queue when it's empty
        queue->front = queue->rear = -1;
    }
    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the current queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
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
