#include <stdio.h>
#include <stdlib.h>
// Node structure for a polynomial term
struct Node {
	int coeff; // Coefficient
	int exp; // Exponent
	struct Node* next; // Pointer to the next term
};
// Function to create a new node
struct Node* createNode(int coeff, int exp) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->next = NULL;
	return newNode;
}
// Function to insert a term
void insertTerm(struct Node** poly, int coeff, int exp) {
	struct Node* newNode = createNode(coeff, exp);
	newNode->next = *poly;
	*poly = newNode;
}
// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
	struct Node* current = poly;
	while (current) {
		printf("%dx^%d ", current->coeff, current->exp);
		current = current->next;
		if (current) printf("+ ");
	}
	printf("\n");
}
// Main function
int main() {
	struct Node* poly1 = NULL;
	struct Node* poly2 = NULL;
// Input for the first polynomial
	printf("Enter terms for polynomial 1 (coeff exp), end with -1 -1:\n");
	while (1) {
		int coeff, exp;
		scanf("%d %d", &coeff, &exp);
		if (coeff == -1 && exp == -1) break;
		insertTerm(&poly1, coeff, exp);
	}
// Input for the second polynomial
	printf("Enter terms for polynomial 2 (coeff exp), end with -1 -1:\n");
	while (1) {
		int coeff, exp;
		scanf("%d %d", &coeff, &exp);
		if (coeff == -1 && exp == -1) break;
		insertTerm(&poly2, coeff, exp);
	}
// Display polynomials
	printf("Polynomial 1: ");
	displayPolynomial(poly1);
	printf("Polynomial 2: ");
	displayPolynomial(poly2);
// Free memory (not shown here for brevity)
	return 0;
}

/*[?2004l
Enter terms for polynomial 1 (coeff exp), end with -1 -1:
8 6
8 1
-1 -1
Enter terms for polynomial 2 (coeff exp), end with -1 -1:
9 2
4 3
-1 -^[[A     -1
Polynomial 1: 8x^1 + 8x^6 
Polynomial 2: 4x^3 + 9x^2 
[?2004h*/