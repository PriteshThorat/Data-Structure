#include<iostream>
#include<cstring>

using namespace std;

struct Stack {
  int size;
  int top;
  char* arr;
};

int isEmpty (struct Stack* stack) {
  if (stack->top == -1) {
    cout << "Stack is Empty\n";

    return 1;
  }

  return 0;
}

int stackTop (struct Stack* stack) {
  return stack->arr[stack->top];
}

int push (struct Stack* stack, char value) {
  stack->top++;
  stack->arr[stack->top] = value;

  return 1;
} 

char pop (struct Stack* stack) {
  char value = stack->arr[stack->top];
  stack->top--;

  return value;
}

int isOperator (char ch) {
  if (
    ch == '/' ||
    ch == '*' ||
    ch == '-' ||
    ch == '+'
  ) {
    return 1;
  } 

  return 0;
}

int precedence (char ch) {
  if (ch == '*' || ch == '/') {
    return 3;
  } else if (ch == '+' || ch == '-') {
    return 2;
  }

  return 0;
}

char* infixToPostfix (char* infix) {
  struct Stack* stack = new Stack;
  stack->size = 50;
  stack->top = -1;
  stack->arr = new char[stack->size];
  
  char* postfix = new char[strlen(infix) + 1];
  int i = 0;
  int j = 0;

  while (infix[i] != '\0') {
    if (!isOperator(infix[i])) {
      postfix[j] = infix[i];

      i++;
      j++;
    } else {
      if (precedence(infix[i]) > precedence(stackTop(stack))) {
        push(stack, infix[i]);
        i++; 
      } else {
        postfix[j] = pop(stack);
        j++;
      }
    }
  }

  while (!isEmpty(stack)) {
    postfix[j] = pop(stack);
    j++;
  }
  postfix[j] = '\0';

  return postfix;
}

int main () {
  char* infix = "p-q-r/a";
  cout << "The Infix to Postfix of " << infix << " is " << infixToPostfix(infix) << "\n";

  return 0;
}