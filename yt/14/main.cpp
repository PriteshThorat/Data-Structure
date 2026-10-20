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

  head = (struct Node*) malloc(sizeof(struct Node));
  second = (struct Node*) malloc(sizeof(struct Node));
  third = (struct Node*) malloc(sizeof(struct Node));
  fourth = (struct Node*) malloc(sizeof(struct Node));

  head->data = 11;
  head->next = second;

  second->data = 22;
  second->next = third;

  third->data = 33;
  third->next = fourth;

  fourth->data = 44;
  fourth->next = NULL;

  linkedListTraversal(head);

  return 0;
}