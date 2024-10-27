#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
typedef struct Stack {
	Node* top;
} Stack;
Stack* createStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}
int isEmpty(Stack* stack) {
	return stack->top == NULL;
}
void push(Stack* stack, int item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		printf("Memory allocation failed!\n");
		return;
	}
	newNode->data = item;
	newNode->next = stack->top;
	stack->top = newNode;
	printf("Pushed %d onto stack\n", item);
}
int pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack underflow! Cannot pop\n");
		return -1;
	} else {
		Node* temp = stack->top;
		int poppedValue = temp->data;
		stack->top = stack->top->next;
		free(temp);
		return poppedValue;
	}
}
void display(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
	} else {
		Node* current = stack->top;
		printf("Stack elements: ");
		while (current != NULL) {
			printf("%d ", current->data);
			current = current->next;
		}
		printf("\n");
	}
}
void freeStack(Stack* stack) {
	while (!isEmpty(stack)) {
		pop(stack);
	}
	free(stack);
}
int main() {
	Stack* stack = createStack();
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	display(stack);
	printf("Popped %d from stack\n", pop(stack));
	printf("Popped %d from stack\n", pop(stack));
	display(stack);
	freeStack(stack);
	return 0;
}

/*[?2004l
Pushed 10 onto stack
Pushed 20 onto stack
Pushed 30 onto stack
Pushed 40 onto stack
Pushed 50 onto stack
Stack elements: 50 40 30 20 10 
Popped 50 from stack
Popped 40 from stack
Stack elements: 30 20 10 
[?2004h*/