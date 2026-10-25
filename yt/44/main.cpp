#include<iostream>

using namespace std;

struct Queue {
  int size;
  int front;
  int rear;
  int* arr;
};

int isFull (struct Queue* queue) {
  if ((queue->rear + 1) % queue->size == queue->front) {
    cout << "Queue is Full\n";

    return 1;
  }

  return 0;
}

int enqueue (struct Queue* queue, int value) {
  if (isFull(queue)) {
    return 0;
  }

  queue->rear = (queue->rear + 1) % queue->size;
  queue->arr[queue->rear] = value;

  return 1;
}

int isEmpty (struct Queue* queue) {
  if (queue->rear == queue->front) {
    cout << "Queue is Empty\n";

    return 1;
  }

  return 0;
}

int dequeue (struct Queue* queue) {
  if (isEmpty(queue)) {
    return 0;
  }

  queue->front = (queue->front + 1) % queue->size;

  return 1;
}

int traverse (struct Queue* queue) {
  if (isEmpty(queue)) {
    return 0;
  }
  
  int i = (queue->front + 1) % queue->size;

  while (true) {
    cout << "Element: " << queue->arr[i] << "\n";

    if (i == queue->rear) {
      break;
    }

    i = (i + 1) % queue->size;
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