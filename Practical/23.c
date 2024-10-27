#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the circular queue

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
};

// Function to create and initialize the circular queue
struct CircularQueue* createQueue() {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Function to insert an element into the circular queue
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Initialize front if this is the first element
    }
    q->rear = (q->rear + 1) % MAX; // Move rear to the next position
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate queue is empty
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Reset the queue if it becomes empty after dequeue
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; // Move front to the next position
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    struct CircularQueue* q = createQueue();

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
    display(q);

    enqueue(q, 60); // This will cause overflow
    display(q);

    // Further dequeue operations
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q); // This will cause underflow
    display(q);

    // Free allocated memory for the queue
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
Queue elements: 20 30 40 50 
Enqueued: 60
Queue elements: 20 30 40 50 60 
Dequeued: 20
Dequeued: 30
Dequeued: 40
Dequeued: 50
Queue elements: 60 
[?2004h*/