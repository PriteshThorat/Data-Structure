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
        if (temp->coefficient > 0 && temp != head) {
            printf(" + ");
        }
        if (temp->coefficient < 0) {
            printf(" - ");
            printf("%dx^%d", -temp->coefficient, temp->exponent);
        } else {
            printf("%dx^%d", temp->coefficient, temp->exponent);
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials and return the sum polynomial
struct PolyNode* addPolynomials(struct PolyNode* P, struct PolyNode* Q) {
    struct PolyNode* result = NULL;
    struct PolyNode* ptr1 = P;
    struct PolyNode* ptr2 = Q;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exponent > ptr2->exponent) {
            insertTerm(&result, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        } else if (ptr1->exponent < ptr2->exponent) {
            insertTerm(&result, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        } else {
            int sumCoeff = ptr1->coefficient + ptr2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, ptr1->exponent);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    // Add remaining terms from P
    while (ptr1 != NULL) {
        insertTerm(&result, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }

    // Add remaining terms from Q
    while (ptr2 != NULL) {
        insertTerm(&result, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }

    return result;
}

int main() {
    struct PolyNode* P = NULL;
    struct PolyNode* Q = NULL;

    // Insert terms for polynomial P(x) = 3x^4 + 2x^3 - 4x^2 + 7
    insertTerm(&P, 3, 4);
    insertTerm(&P, 2, 3);
    insertTerm(&P, -4, 2);
    insertTerm(&P, 7, 0);

    // Insert terms for polynomial Q(x) = 5x^3 + 4x^2 - 5
    insertTerm(&Q, 5, 3);
    insertTerm(&Q, 4, 2);
    insertTerm(&Q, -5, 0);

    // Display the polynomials
    printf("P(x) = ");
    displayPolynomial(P);

    printf("Q(x) = ");
    displayPolynomial(Q);

    // Add the two polynomials
    struct PolyNode* sum = addPolynomials(P, Q);

    // Display the sum polynomial
    printf("P(x) + Q(x) = ");
    displayPolynomial(sum);

    return 0;
}
