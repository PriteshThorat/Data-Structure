#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create and initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to insert an element into the queue
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) {
        // If the queue is empty, both front and rear will point to the new node
        q->front = q->rear = newNode;
        printf("Enqueued: %d\n", value);
        return;
    }
    q->rear->next = newNode; // Link the new node at the end of the queue
    q->rear = newNode;       // Update the rear pointer
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate queue is empty
    }
    struct Node* temp = q->front; // Store the front node
    int value = temp->data;        // Get the value to be dequeued
    q->front = q->front->next;     // Move front to the next node
    // If the front becomes NULL, also reset the rear
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp); // Free the memory of the dequeued node
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* current = q->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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
Dequeued: 20
Dequeued: 30
Dequeued: 40
Dequeued: 50
Queue is empty.
[?2004h*/