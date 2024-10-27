#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct Stack {
	int items[MAX];
	int top;
} Stack;
void initStack(Stack *s) {
	s->top = -1;
}
int isFull(Stack *s) {
	return s->top == MAX - 1;
}
int isEmpty(Stack *s) {
	return s->top == -1;
}
void push(Stack *s, int item) {
	if (isFull(s)) {
		printf("Stack overflow! Cannot push %d\n", item);
	} else {
		s->items[++(s->top)] = item;
		printf("Pushed %d onto stack\n", item);
	}
}
int pop(Stack *s) {
	if (isEmpty(s)) {
		printf("Stack underflow! Cannot pop\n");
		return -1;
	} else {
		return s->items[(s->top)--];
	}
}
void display(Stack *s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
	} else {
		printf("Stack elements: ");
		for (int i = 0; i <= s->top; i++) {
			printf("%d ", s->items[i]);
		}
		printf("\n");
	}
}
int main() {
	Stack s;
	initStack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	push(&s, 40);
	push(&s, 50);
	push(&s, 60);
	display(&s);

	printf("Popped %d from stack\n", pop(&s));
	printf("Popped %d from stack\n", pop(&s));
	display(&s);
	return 0;
}

/*[?2004l
Pushed 10 onto stack
Pushed 20 onto stack
Pushed 30 onto stack
Pushed 40 onto stack
Pushed 50 onto stack
Stack overflow! Cannot push 60
Stack elements: 10 20 30 40 50 
Popped 50 from stack
Popped 40 from stack
Stack elements: 10 20 30 
[?2004h*/