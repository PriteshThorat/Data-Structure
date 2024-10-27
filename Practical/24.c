#include <stdio.h>
#include <stdlib.h>

// Structure for the node in the circular queue
struct Node {
    int data;
    struct Node* next;
};

// Structure for the circular queue
struct CircularQueue {
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

// Function to create and initialize the circular queue
struct CircularQueue* createQueue() {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == NULL);
}

// Function to insert an element into the circular queue
void enqueue(struct CircularQueue* q, int value) {
    struct Node* newNode = createNode(value);
    if (isEmpty(q)) {
        // If the queue is empty, both front and rear will point to the new node
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        q->rear->next = newNode; // Link the new node at the end
        q->rear = newNode;       // Update the rear pointer
        q->rear->next = q->front; // Make it circular
    }
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate queue is empty
    }
    struct Node* temp = q->front; // Store the front node
    int value = temp->data;        // Get the value to be dequeued

    if (q->front == q->rear) {
        // If the queue has only one node
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next; // Move front to the next node
        q->rear->next = q->front;   // Maintain the circular link
    }
    free(temp); // Free the memory of the dequeued node
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* current = q->front;
    printf("Queue elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != q->front);
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