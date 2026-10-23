#include<iostream>

using namespace std;

struct Stack {
  int data;
  struct Stack* next;
};

struct Stack* push (struct Stack* top, int data) {
  struct Stack* ptr = new Stack;
  ptr->data = data;
  ptr->next = top;

  return ptr;
}

struct Stack* pop (struct Stack* top) {
  if (top == NULL) {
    cout << "Stack is Empty\n";
  }
  
  struct Stack* ptr = top;

  top = top->next;

  delete ptr;

  return top;
}

void traverse (struct Stack* top) {
  struct Stack* ptr = top;

  while (ptr != NULL) {
    cout << ptr->data << "\n";

    ptr = ptr->next;
  }
}

int main () {
  struct Stack* top = new Stack; 

  top = NULL;

  cout << "Before Push on Stack of Linked List:-\n";
  traverse(top);
  top = push(top, 11);
  top = push(top, 22);
  top = push(top, 33);
  top = push(top, 44);
  cout << "After Push on Stack of Linked List:-\n";
  traverse(top);

  cout << "Before Pop on Stack of Linked List:-\n";
  traverse(top);
  top = pop(top);
  cout << "After Pop on Stack of Linked List:-\n";
  traverse(top);

  return 0;
}