// Implement a Circular Queue using an array in C++ to simulate CPU task scheduling with enqueue, dequeue, and display
// operations, including overflow and underflow handling.

#include <iostream>

using namespace std;

#define SIZE 5

class CircularQueue {
  int queue[SIZE];
  int front, rear;

public:
  CircularQueue() {
    front = -1;
    rear = -1;
  }

  // Enqueue operation
  void enqueue(int task) {
    if ((rear + 1) % SIZE == front) {
      cout << "Queue Overflow! CPU Task Queue is Full.\n";
      return;
    }

    if (front == -1) {
      front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = task;

    cout << "Task " << task << " added successfully.\n";
  }

  // Dequeue operation
  void dequeue() {
    if (front == -1) {
      cout << "Queue Underflow! No tasks to execute.\n";
      return;
    }

    cout << "Task " << queue[front] << " executed and removed.\n";

    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % SIZE;
    }
  }

  // Display operation
  void display() {
    if (front == -1) {
      cout << "CPU Task Queue is Empty.\n";
      return;
    }

    cout << "Pending CPU Tasks: ";

    int i = front;

    while (true) {
      cout << queue[i] << " ";

      if (i == rear) break;

      i = (i + 1) % SIZE;
    }

    cout << endl;
  }
};

int main() {
  CircularQueue q;
  int choice, task;

  do {
    cout << "\n--- CPU Task Scheduling ---\n";
    cout << "1. Enqueue Task\n";
    cout << "2. Dequeue Task\n";
    cout << "3. Display Tasks\n";
    cout << "4. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter Task ID: ";
      cin >> task;
      q.enqueue(task);
      break;

    case 2:
      q.dequeue();
      break;

    case 3:
      q.display();
      break;

    case 4:
      cout << "Exiting CPU Scheduler.\n";
      break;

    default:
      cout << "Invalid Choice!\n";
    }

  } while (choice != 4);

  return 0;
}