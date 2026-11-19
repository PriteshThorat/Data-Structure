// Implement a Circular Queue using an array in C++ to simulate CPU task scheduling with enqueue, dequeue, and display
// operations, including overflow and underflow handling.

#include <iostream>

using namespace std;

#define SIZE 100

int arr[SIZE];
int front = -1;
int rear = -1;

void enqueue (int data) {
  if (rear == SIZE - 1) {
    cout << "Queue Overflow\n";
  }

  rear++;
  arr[rear] = data;
}

void dequeue () {
  if (front == rear) {
    cout << "Queue Underflow\n";
  }

  front++;
}

void traverse () {
  for (int i = front + 1; i <= rear; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main () {
  traverse();

  enqueue(11);
  enqueue(22);
  enqueue(33);
  enqueue(44);
  enqueue(55);

  traverse();

  dequeue();

  traverse();

  return 0;
}