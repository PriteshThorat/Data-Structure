// Implement a Stack ADT using a singly linked list in C++.
// Use stack operations to convert a given infix expression into a postfix expression and evaluate the generated postfix
// expression.

#include <cctype>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Node structure
struct Node {
  double data;
  Node *next;

  Node(double value) {
    data = value;
    next = nullptr;
  }
};

// Stack ADT using Singly Linked List
class Stack {
  Node *topNode;

public:
  Stack() { topNode = nullptr; }

  // Push operation
  void push(double value) {
    Node *newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
  }

  // Pop operation
  double pop() {
    if (isEmpty()) throw runtime_error("Stack Underflow");

    Node *temp = topNode;
    double value = temp->data;

    topNode = topNode->next;
    delete temp;

    return value;
  }

  // Peek operation
  double peek() {
    if (isEmpty()) throw runtime_error("Stack is Empty");

    return topNode->data;
  }

  // Check whether stack is empty
  bool isEmpty() { return topNode == nullptr; }

  // Display stack
  void display() {
    Node *temp = topNode;

    cout << "Top -> ";

    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }

    cout << "NULL\n";
  }

  // Destructor
  ~Stack() {
    while (!isEmpty())
      pop();
  }
};

// Operator precedence
int precedence(char op) {
  if (op == '^') return 3;

  if (op == '*' || op == '/') return 2;

  if (op == '+' || op == '-') return 1;

  return 0;
}

// Check right associativity
bool isRightAssociative(char op) { return op == '^'; }

// Convert infix to postfix
string infixToPostfix(string infix) {
  Stack st;
  string postfix;

  for (int i = 0; i < (int)infix.length(); i++) {

    char ch = infix[i];

    // Skip spaces
    if (isspace((unsigned char)ch)) continue;

    // Operand (supports multi-digit numbers)
    if (isdigit((unsigned char)ch) || ch == '.') {

      while (i < (int)infix.length() && (isdigit((unsigned char)infix[i]) || infix[i] == '.')) {

        postfix += infix[i];
        i++;
      }

      postfix += ' ';
      i--;
    }

    // Opening parenthesis
    else if (ch == '(') {
      st.push(ch);
    }

    // Closing parenthesis
    else if (ch == ')') {

      while (!st.isEmpty() && st.peek() != '(') {
        postfix += (char)st.pop();
        postfix += ' ';
      }

      if (st.isEmpty()) throw runtime_error("Mismatched parentheses");

      st.pop();
    }

    // Operator
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {

      while (!st.isEmpty() && st.peek() != '(' &&
             (precedence((char)st.peek()) > precedence(ch) ||
              (precedence((char)st.peek()) == precedence(ch) && !isRightAssociative(ch)))) {

        postfix += (char)st.pop();
        postfix += ' ';
      }

      st.push(ch);
    } else {
      throw runtime_error("Invalid character in expression");
    }
  }

  // Pop remaining operators
  while (!st.isEmpty()) {

    if (st.peek() == '(') throw runtime_error("Mismatched parentheses");

    postfix += (char)st.pop();
    postfix += ' ';
  }

  return postfix;
}

// Evaluate postfix expression
double evaluatePostfix(string postfix) {
  Stack st;

  for (int i = 0; i < (int)postfix.length(); i++) {

    if (isspace((unsigned char)postfix[i])) continue;

    // Read number
    if (isdigit((unsigned char)postfix[i]) || postfix[i] == '.') {

      string num;

      while (i < (int)postfix.length() && (isdigit((unsigned char)postfix[i]) || postfix[i] == '.')) {

        num += postfix[i];
        i++;
      }

      st.push(stod(num));
      i--;
    }

    // Process operator
    else {

      if (st.isEmpty()) throw runtime_error("Invalid postfix expression");

      double b = st.pop();

      if (st.isEmpty()) throw runtime_error("Invalid postfix expression");

      double a = st.pop();
      double result;

      switch (postfix[i]) {

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
        if (b == 0) throw runtime_error("Division by zero");

        result = a / b;
        break;

      case '^':
        result = pow(a, b);
        break;

      default:
        throw runtime_error("Invalid operator");
      }

      st.push(result);
    }
  }

  if (st.isEmpty()) throw runtime_error("Invalid postfix expression");

  double answer = st.pop();

  if (!st.isEmpty()) throw runtime_error("Invalid postfix expression");

  return answer;
}

// Main function
int main() {

  string infix, postfix;

  cout << "Enter Infix Expression: ";
  getline(cin, infix);

  try {
    // Convert infix to postfix
    postfix = infixToPostfix(infix);

    cout << "\nInfix Expression: " << infix;

    cout << "\nPostfix Expression: " << postfix;

    // Evaluate postfix
    double result = evaluatePostfix(postfix);

    cout << "\nEvaluated Result: " << result << endl;

  } catch (const exception &e) {

    cout << "\nError: " << e.what() << endl;
  }

  return 0;
}