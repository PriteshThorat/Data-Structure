#include <stdio.h>
#include <stdlib.h>

// Structure for the node in the priority queue
struct Node {
    int data;             // The value of the node
    int priority;        // The priority of the node
    struct Node* next;   // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Structure for the priority queue
struct PriorityQueue {
    struct Node* front; // Pointer to the front of the queue
};

// Function to create and initialize the priority queue
struct PriorityQueue* createQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

// Function to check if the queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return (pq->front == NULL);
}

// Function to insert an element into the priority queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (isEmpty(pq) || pq->front->priority < priority) {
        // If the queue is empty or the new node has higher priority than the front
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        // Find the correct position to insert the new node
        struct Node* current = pq->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Enqueued: %d with priority %d\n", data, priority);
}

// Function to remove the element with the highest priority from the queue
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue Underflow! Cannot dequeue\n");
        return -1; // Indicate queue is empty
    }
    struct Node* temp = pq->front; // Store the front node
    int value = temp->data;         // Get the value to be dequeued
    pq->front = pq->front->next;    // Move front to the next node
    free(temp); // Free the memory of the dequeued node
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the priority queue
void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node* current = pq->front;
    printf("Priority Queue elements: ");
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    struct PriorityQueue* pq = createQueue();

    // Perform enqueue operations
    enqueue(pq, 10, 1);
    enqueue(pq, 20, 3);
    enqueue(pq, 30, 2);
    display(pq);

    // Perform dequeue operations
    dequeue(pq);
    display(pq);

    enqueue(pq, 40, 5);
    enqueue(pq, 50, 4);
    display(pq);

    // Further dequeue operations
    dequeue(pq);
    dequeue(pq);
    dequeue(pq);
    dequeue(pq); // This will cause underflow
    display(pq);

    // Free allocated memory for the queue
    free(pq);
    return 0;
}

/*[?2004l
Enqueued: 10 with priority 1
Enqueued: 20 with priority 3
Enqueued: 30 with priority 2
Priority Queue elements: (20, 3) (30, 2) (10, 1) 
Dequeued: 20
Priority Queue elements: (30, 2) (10, 1) 
Enqueued: 40 with priority 5
Enqueued: 50 with priority 4
Priority Queue elements: (40, 5) (50, 4) (30, 2) (10, 1) 
Dequeued: 40
Dequeued: 50
Dequeued: 30
Dequeued: 10
Priority Queue is empty.
[?2004h*/