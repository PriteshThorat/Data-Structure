#include <stdio.h>
#include <stdlib.h>
struct Node {
	int coeff, exp;
	struct Node* next;
};
// Create a new node
struct Node* createNode(int coeff, int exp) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->next = NULL;
	return newNode;
}
// Insert a term in the polynomial
void insertTerm(struct Node** poly, int coeff, int exp) {
	struct Node* newNode = createNode(coeff, exp);
	newNode->next = *poly;
	*poly = newNode;
}
// Display the polynomial
void display(struct Node* poly) {
	while (poly) {
		printf("%dx^%d ", poly->coeff, poly->exp);
		poly = poly->next;
		if (poly) printf("+ ");
	}
	printf("\n");
}
// Add two polynomials
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
	struct Node* result = NULL;
	while (p1 || p2) {
		int coeff = 0, exp;
		if (p1 && (!p2 || p1->exp > p2->exp)) {
			coeff = p1->coeff;
			exp = p1->exp;
			p1 = p1->next;
		} else if (p2 && (!p1 || p2->exp > p1->exp) ) {
			coeff = p2->coeff;
			exp = p2->exp;
			p2 = p2->next;
		} else {
			coeff = p1->coeff + p2->coeff;
			exp = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
		}
		if (coeff != 0) insertTerm(&result, coeff, exp);
	}
	return result;
}
// Free memory
void freePoly(struct Node* poly) {
	while (poly) {
		struct Node* temp = poly;
		poly = poly->next;
		free(temp);
	}
}
int main() {
	struct Node *poly1 = NULL, *poly2 = NULL;

// Input for polynomial 1
	printf("Enter polynomial 1 (coeff exp), end with -1 -1:\n");
	while (1) {
		int c, e;
		scanf("%d %d", &c, &e);
		if (c == -1 && e == -1) break;
		insertTerm(&poly1, c, e);
	}
// Input for polynomial 2
	printf("Enter polynomial 2 (coeff exp), end with -1 -1:\n");
	while (1) {
		int c, e;
		scanf("%d %d", &c, &e);
		if (c == -1 && e == -1) break;
		insertTerm(&poly2, c, e);
	}
// Add polynomials
	struct Node* result = addPolynomials(poly1, poly2);
	printf("Result: ");
	display(result);
// Free memory
	freePoly(poly1);
	freePoly(poly2);
	freePoly(result);
	return 0;
}

/*[?2004l
Enter polynomial 1 (coeff exp), end with -1 -1:
5 8
4 6
-^[[6~1       -1 -1
Enter polynomial 2 (coeff exp), end with -1 -1:
87  6
9 1
-1 -1
Result: 8x^6 + 9x^1 + 5x^8 + 4x^6 
[?2004h*/