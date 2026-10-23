#include <iostream>

using namespace std;

struct Stack {
  int size;
  int top;
  int* arr;
};

bool push (struct Stack* ptr, int value) {
  if (ptr->top == ptr->size-1) {
    cout << "The Stack is Full\n";

    return false;
  }
  ptr->top++;
  ptr->arr[ptr->top] = value;

  return true;
}

bool pop (struct Stack* ptr) {
  if (ptr->top == -1) {
    cout << "The Stack is Empty\n";

    return false;
  }
  ptr->top--;

  return true;
}

int stackTop (struct Stack* ptr) {
  if (ptr->top == -1) {
    cout << "The Stack is Empty\n";

    return -1;
  }

  return ptr->arr[ptr->top];
}

int stackBottom (struct Stack* ptr) {
  if (ptr->top == -1) {
    cout << "The Stack is Empty\n";

    return -1;
  }

  return ptr->arr[0];
}

int main () {
  struct Stack* s = new Stack;
  s->size = 80;
  s->top = -1;
  s->arr = new int[s->size];

  push(s, 11);
  push(s, 22);
  push(s, 33);
  push(s, 44);

  pop(s);
  pop(s);

  push(s, 99);

  cout << "The Top of Stack is " << stackTop(s) << "\n";
  cout << "The Bottom of Stack is " << stackBottom(s) << "\n";
  return 0;
}