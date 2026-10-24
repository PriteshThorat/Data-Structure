#include<iostream>

using namespace std;

struct Queue {
  int size;
  int front;
  int rear;
  int* arr;
};

int isFull (struct Queue* queue) {
  if (queue->rear == queue->size - 1) {
    cout << "Queue is Full\n";

    return 1;
  }

  return 0;
}

int enqueue (struct Queue* queue, int value) {
  if (isFull(queue)) {
    return 0;
  }

  queue->rear++;
  queue->arr[queue->rear] = value;

  return 1;
}

int isEmpty (struct Queue* queue) {
  if (queue->front == queue->rear) {
    cout << "Queue is Empty\n";

    return 1;
  }

  return 0;
}

int dequeue (struct Queue* queue) {
  if (isEmpty(queue)) {
    return 0;
  }

  queue->front++;

  return 1;
}

int traverse (struct Queue* queue) {
  if (isEmpty(queue)) {
    return 0;
  }
  
  for (int i = queue->front + 1; i < queue->rear + 1; i++) {
    cout << "Element: " << queue->arr[i] << "\n";
  }

  return 1;
}

int main () {
  struct Queue* queue = new Queue;
  queue->front = -1;
  queue->rear = -1;
  queue->size = 10;
  queue->arr = new int[queue->size];

  cout << "Queue Before Enqueue:-\n";
  traverse(queue);

  enqueue(queue, 11);
  enqueue(queue, 22);
  enqueue(queue, 33);
  enqueue(queue, 44);

  cout << "Queue After Enqueue:-\n";
  traverse(queue);

  cout << "Queue Before Dequeue:-\n";
  traverse(queue);

  dequeue(queue);
  dequeue(queue);

  cout << "Queue After Dequeue:-\n";
  traverse(queue);

  return 0;
}