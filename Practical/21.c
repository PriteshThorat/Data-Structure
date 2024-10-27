#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the queue

// Structure to represent the queue
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to create and initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to insert an element into the queue
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Initialize front if this is the first element
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate queue is empty
    }
    int value = q->items[q->front];
    q->front++;
    // Reset the queue if it becomes empty after the dequeue
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    struct Queue* q = createQueue();

    // Perform enqueue operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    // Perform dequeue operations
    dequeue(q);
    display(q);

    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60); // This will cause overflow
    display(q);

    // Further dequeue operations
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q); // This will cause underflow
    display(q);

    // Free allocated memory
    free(q);
    return 0;
}

/*[?2004l
Enqueued: 10
Enqueued: 20
Enqueued: 30
Queue elements: 10 20 30 
Dequeued: 10
Queue elements: 20 30 
Enqueued: 40
Enqueued: 50
Queue Overflow! Cannot enqueue 60
Queue elements: 20 30 40 50 
Dequeued: 20
Dequeued: 30
Dequeued: 40
Dequeued: 50
Queue is empty.
[?2004h*/