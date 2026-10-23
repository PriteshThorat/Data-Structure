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

void traverse (struct Stack* ptr) {
  for (int i = 0; i < ptr->top+1; i++) {
    cout << "Element: " << ptr->arr[i] << "\n";
  }
}

int main () {
  struct Stack* s = new Stack;
  s->size = 80;
  s->top = -1;
  s->arr = new int[s->size];

  cout << "Before Push Operation:-\n";
  traverse(s);
  push(s, 11);
  push(s, 22);
  push(s, 33);
  push(s, 44);
  cout << "After Push Operation:-\n";
  traverse(s);

  cout << "Before Pop Operation:-\n";
  traverse(s);
  pop(s);
  pop(s);
  cout << "After Pop Operation:-\n";
  traverse(s);

  return 0;
}