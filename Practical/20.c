#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void printReverse(Node* head) {
	if (head == NULL) {
		return;
	}
	printReverse(head->next);
	printf("%d ", head->data);
}
void insertEnd(Node** head, int data) {
	Node* newNode = createNode(data);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}
int main() {
	Node* head = NULL;
	int n, data;
	printf("Enter number of elements in the linked list: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d", &data);
		insertEnd(&head, data);
	}
	printf("The linked list in reverse order is: ");
	printReverse(head);
	printf("\n");

	Node* current = head;
	Node* nextNode;
	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
	return 0;
}

/*[?2004l
Enter number of elements in the linked list: 2
Enter element 1: 52
Enter element 2: 45
The linked list in reverse order is: 45 52 
[?2004h*/