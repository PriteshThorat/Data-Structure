#include <stdio.h>
#include <stdlib.h>

// Definition of a polynomial term node
struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode* next;
};

// Function to create a new node for the polynomial
struct PolyNode* createNode(int coefficient, int exponent) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end of the polynomial linked list
void insertTerm(struct PolyNode** head, int coefficient, int exponent) {
    struct PolyNode* newNode = createNode(coefficient, exponent);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct PolyNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPolynomial(struct PolyNode* head) {
    struct PolyNode* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL && temp->coefficient >= 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct PolyNode* poly = NULL;

    // Insert terms for the polynomial 5x^4 + 3x^2 + 1
    insertTerm(&poly, 5, 4);
    insertTerm(&poly, 3, 2);
    insertTerm(&poly, 1, 0);

    // Display the polynomial
    printf("Polynomial: ");
    displayPolynomial(poly);

    return 0;
}
