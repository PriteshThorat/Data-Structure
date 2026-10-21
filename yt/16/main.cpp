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

// Case 1: Insert at the Beginning
struct Node* insertAtFirst (struct Node* head, int data) {
  struct Node* ptr = new Node;

  ptr->next = head;
  ptr->data = data;

  return ptr;
}

// Case 2: Insert in Between
struct Node* insertAtIndex (struct Node* head, int data, int index) {
  struct Node* ptr = new Node;
  struct Node* p = head;
  int i = 0;

  while (i != (index - 1)) {
    p = p->next;

    i++;
  } 
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;

  return head;
}

// Case 3: Insert at the End
struct Node* insertAtEnd (struct Node* head, int data) {
  struct Node* ptr = new Node;
  struct Node* p = head;
  ptr->data = data;

  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;

  return head;
}

// Case 4: Insert after a Node
struct Node* insertAfterNode (struct Node* head, struct Node* preNode, int data) {
  struct Node* ptr = new Node;
  ptr->data = data;

  ptr->next = preNode->next;
  preNode->next = ptr;

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

  cout << "Linked List before Traversal:-\n";
  linkedListTraversal(head);

  // head = insertAtFirst(head, 99);
  // head = insertAtIndex(head, 99, 1);
  // head = insertAtEnd(head, 99);
  head = insertAfterNode(head, second, 99);
  
  cout << "Linked List after Traversal:-\n";
  linkedListTraversal(head);

  delete head;
  delete second;
  delete third;
  delete fourth;

  return 0;
}