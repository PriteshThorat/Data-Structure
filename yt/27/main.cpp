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

int peek (struct Stack* ptr, int pos) {
  if (pos < 1) {
    cout << "Invalid Position\n";

    return -1;
  }
  if (pos - 1 > ptr->top) {
    cout << "Invalid Position\n";

    return -1;
  }

  return ptr->arr[ptr->top - pos + 1];
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

  cout << "The element at 2nd postion is " << peek(s, 2) << "\n";

  pop(s);
  pop(s);

  push(s, 99);
  cout << "The element at 1st postion is " << peek(s, 1) << "\n";

  return 0;
}