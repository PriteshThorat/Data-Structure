#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

void linkedListTraversal (struct Node* head) {
  struct Node* ptr = head;

  do {
    cout << "Element is " << ptr->data << "\n";

    ptr = ptr->next;
  } while (ptr != head);
}

struct Node* insertAtFirst (struct Node* head, int data) {
  struct Node* ptr = new Node;
  ptr->data = data;

  struct Node* p = head->next;

  while (p->next != head) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = head;
  head = ptr;

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
  fourth->next = head;

  cout << "Circular Linked List before Insertion\n";
  linkedListTraversal(head);
  head = insertAtFirst(head, 99);
  cout << "Circular Linked List after Insertion\n";
  linkedListTraversal(head);

  delete head;
  delete second;
  delete third;
  delete fourth;

  return 0;
}