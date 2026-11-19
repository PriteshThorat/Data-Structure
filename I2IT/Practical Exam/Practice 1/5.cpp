// Implement a Stack ADT using a singly linked list in C++.
// Use stack operations to convert a given infix expression into a prefix expression and evaluate the generated prefix
// expression.

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

// Node structure
struct Node {
  char data;
  Node *next;
};

// Stack ADT using Singly Linked List
class Stack {
  Node *top;

public:
  Stack() { top = NULL; }

  void push(char value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
  }

  char pop() {
    if (isEmpty()) {
      return '\0';
    }

    Node *temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;

    return value;
  }

  char peek() {
    if (isEmpty()) {
      return '\0';
    }
    return top->data;
  }

  bool isEmpty() { return top == NULL; }
};

// Operator precedence
int precedence(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;

  return 0;
}

// Reverse infix and interchange brackets
string reverseExpression(string infix) {
  reverse(infix.begin(), infix.end());

  for (int i = 0; i < infix.length(); i++) {
    if (infix[i] == '(') infix[i] = ')';
    else if (infix[i] == ')') infix[i] = '(';
  }

  return infix;
}

// Convert infix to prefix
string infixToPrefix(string infix) {
  Stack s;
  string reversed = reverseExpression(infix);
  string result = "";

  for (int i = 0; i < reversed.length(); i++) {
    char ch = reversed[i];

    if (ch == ' ') continue;

    if (isalnum(ch)) {
      result += ch;
    } else if (ch == '(') {
      s.push(ch);
    } else if (ch == ')') {
      while (!s.isEmpty() && s.peek() != '(')
        result += s.pop();

      if (!s.isEmpty()) s.pop();
    } else {
      while (!s.isEmpty() && s.peek() != '(' &&
             (precedence(s.peek()) > precedence(ch) || (precedence(s.peek()) == precedence(ch) && ch == '^'))) {
        result += s.pop();
      }

      s.push(ch);
    }
  }

  while (!s.isEmpty())
    result += s.pop();

  reverse(result.begin(), result.end());

  return result;
}

// Evaluate prefix expression
int evaluatePrefix(string prefix) {
  Stack s;
  string reversed = prefix;
  reverse(reversed.begin(), reversed.end());

  for (int i = 0; i < reversed.length(); i++) {
    char ch = reversed[i];

    if (ch == ' ') continue;

    if (isdigit(ch)) {
      s.push(ch);
    } else {
      int a = s.pop() - '0';
      int b = s.pop() - '0';
      int result = 0;

      switch (ch) {
      case '+':
        result = a + b;
        break;
      case '-':
        result = a - b;
        break;
      case '*':
        result = a * b;
        break;
      case '/':
        result = a / b;
        break;
      case '^':
        result = pow(a, b);
        break;
      }

      // Store result as a character
      s.push(result + '0');
    }
  }

  return s.pop() - '0';
}

int main() {
  string infix;

  cout << "Enter infix expression: ";
  cin >> infix;

  string prefix = infixToPrefix(infix);

  cout << "Prefix Expression: " << prefix << endl;

  int result = evaluatePrefix(prefix);

  cout << "Evaluation Result: " << result << endl;

  return 0;
}
