// Implement a Stack ADT using a singly linked list in C++.
// Use stack operations to convert a given infix expression into a postfix expression and evaluate the generated postfix
// expression.

#include <iostream>
#include <string>

using namespace std;

struct LinkedList {
  int data;
  struct LinkedList* next;
};

bool isOperator (char ch) {
  if (
    ch == '+' ||
    ch == '-' || 
    ch == '*' ||
    ch == '/' ||
    ch == '^'
  ) {
    return true;
  }

  return false;
}

int prec (char ch) {
  if (ch == '^') {
    return 4;
  } else if (ch == '/' || ch == '*') {
    return 3;
  } else if (ch == '-' || ch == '+') {
    return 2;
  }

  return 1;
} 

int stackTop (struct LinkedList* top) {
  if (top == NULL) {
    cout << "Stack Underflow\n";

    return -1;
  }

  return top->data;
}

struct LinkedList* push (struct LinkedList* top, int data) {
  struct LinkedList* temp = new LinkedList;

  temp->data = data;
  temp->next = top;

  return temp;
}

char pop (struct LinkedList*& top) {
  if (top == NULL) {
    cout << "Stack Underflow\n";

    return '\0';
  }
  struct LinkedList* ptr = top;

  top = top->next;

  return ptr->data;
}

bool isEmpty (struct LinkedList* top) {
  if (top == NULL) {
    return true;
  }

  return false;
}

int main () {
  char infix[] = "a+b/c*f-g";
  char postfix[100];

  LinkedList* top = NULL;

  int i = 0;
  int j = 0;

  while (infix[i] != '\0') {
    if (!isOperator(infix[i])) {
      postfix[j++] = infix[i];
    }
    else {
      while (
        !isEmpty(top) &&
        prec(stackTop(top)) >= prec(infix[i])
      ) {
        postfix[j++] = pop(top);
      }

      top = push(top, infix[i]);
    }

    i++;
  }

  while (!isEmpty(top)) {
    postfix[j] = pop(top);
    j++;
  } 
  postfix[j] = '\0';

  cout << "The Postfix express of " << infix << " is " << postfix;

  return 0;
}