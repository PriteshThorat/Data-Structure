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

int stackTop (struct Stack* top) {
  if (top == NULL) {
    cout << "Stack is Empty";

    return -1;
  }

  return top->data;
}

int stackBottom (struct Stack* top) {
  if (top == NULL) {
    cout << "Stack is Empty";

    return -1;
  }
  struct Stack* ptr = top;
  
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  return ptr->data;
}

int peek (struct Stack* top, int pos) {
  if (pos < 1) {
    cout << "Invalid Postion\n";
  }
  struct Stack* ptr = top;
  int i = 1;

  while (ptr != NULL) {
    if (i == pos) {
      return ptr->data;
    }
    ptr = ptr->next;

    i++;
  }

  return -1;
}

int main () {
  struct Stack* top = new Stack; 

  top = NULL;

  top = push(top, 11);
  top = push(top, 22);
  top = push(top, 33);
  top = push(top, 44);

  // cout << "The Element at 2nd Position is " << peek(top, 2) << "\n";
  cout << "The Stack Top is " << stackTop(top) << "\n";
  cout << "The Stack Bottom is " << stackBottom(top) << "\n";

  top = pop(top);

  return 0;
}