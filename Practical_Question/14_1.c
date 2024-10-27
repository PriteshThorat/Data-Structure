#include <stdio.h>
#include <stdlib.h>

// Definition of a polynomial term node
struct PolyNode {
    int coefficient;  // Coefficient of the term
    int exponent;     // Exponent of the term
    struct PolyNode* next;  // Pointer to the next term
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
