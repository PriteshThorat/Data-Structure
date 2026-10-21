#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

void linkedListTraversal (struct Node* ptr) {
  while (ptr != NULL) {
    cout << "Element: " << ptr->data << "\n"; 
    ptr = ptr->next;
  }
}

// Case 1: Deleting the First Node
struct Node* deleteFirst (struct Node* head) {
  struct Node* ptr = head;

  head = head->next;
  delete ptr;

  return head;
}

// Case 2: Deleting a Node in Between
struct Node* deleteAtIndex (struct Node* head, int index) {
  struct Node* p = head;
  struct Node* q = head->next;

  for (int i = 0; i < index - 1; i++) {
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  
  delete q;

  return head;
}

// Case 3: Delete the last Node
struct Node* deleteLast (struct Node* head) {
  struct Node* p = head;
  struct Node* q = head->next;

  while (q->next != NULL) {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;

  delete q;

  return head;
}

// Case 4: Delete a Node with a given Value
struct Node* deleteAtValue (struct Node* head, int value) {
  struct Node* p = head;
  struct Node* q = head->next;

  while (q->data != value && q->next != NULL) {
    p = p->next;
    q = q->next;
  }

  if (q->data == value) {
    p->next = q->next;

    delete q;
  }

  return head;
}

int main () {
  struct Node* head;
  struct Node* second;
  struct Node* third;
  struct Node* fourth;

  head = new Node;
  second = new Node;
  third = new Node;
  fourth = new Node;

  head->data = 11;
  head->next = second;

  second->data = 22;
  second->next = third;

  third->data = 33;
  third->next = fourth;

  fourth->data = 44;
  fourth->next = NULL;

  cout << "Linked List before Deletion:-\n";
  linkedListTraversal(head);
  // head = deleteFirst(head);
  // head = deleteAtIndex(head, 2);
  // head = deleteLast(head);
  head = deleteAtValue(head, 33);
  cout << "Linked List after Deletion:-\n";
  linkedListTraversal(head);

  return 0;
}