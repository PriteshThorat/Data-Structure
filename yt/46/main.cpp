#include<iostream>

using namespace std;

struct Queue {
  int data;
  struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

void traversal () {
  struct Queue* ptr = front;

  while (ptr != NULL) {
    cout << "Element: " << ptr->data << "\n";

    ptr = ptr->next;
  }
}

int dequeue () {
  if (front == NULL) {
    cout << "Queue is Empty\n";

    return 0;
  }
  struct Queue* ptr = front;
  front = front->next;

  if (front == NULL) {
    rear = NULL;  
  }

  delete ptr;

  return 1;
}

int enqueue (int value) {
  struct Queue* ptr = new Queue;

  if (ptr == NULL) {
    cout << "Queue is Full\n";

    return 0;
  }
  ptr->data = value;
  ptr->next = NULL;

  if (front == NULL) {
    front = rear = ptr;
  } else {
    rear->next = ptr;
    rear = ptr;
  }
}

int main () {
  cout << "Queue Before Enqueue:-\n";
  traversal();

  enqueue(11);
  enqueue(22);
  enqueue(33);
  enqueue(44);

  cout << "Queue After Enqueue:-\n";
  traversal();

  cout << "Queue Before Dequeue:-\n";
  traversal();

  dequeue();
  dequeue();

  cout << "Queue After Dequeue:-\n";
  traversal();

  return 0;
}