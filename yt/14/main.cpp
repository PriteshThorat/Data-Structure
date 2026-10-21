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

  linkedListTraversal(head);

  delete head;
  delete second;
  delete third;
  delete fourth;

  return 0;
}