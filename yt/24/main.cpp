#include <iostream>

using namespace std;

struct Stack {
  int size;
  int top;
  int* arr;
};

bool isEmpty (struct Stack* ptr) {
  if (ptr->top == -1) {
    return true;
  }

  return false;
}

bool isFull (struct Stack* ptr) {
  if (ptr->top == ptr->size-1) {
    return true;
  }

  return false;
}

int main () {
  // struct Stack s;
  // s.size = 80;
  // s.top = -1;
  // s.arr = new int[s.size];
  struct Stack* s;
  s->size = 80;
  s->top = -1;
  s->arr = new int[s->size];

  // s->arr[0] = 4;
  // s->top++;

  if (isEmpty(s)) {
    cout << "The Stack is Empty\n";
  } else {
    cout << "The Stack is not Empty\n";
  }

  if (isFull(s)) {
    cout << "The Stack is Full\n";
  } else {
    cout << "The Stack is not Full\n";
  }

  return 0;
}