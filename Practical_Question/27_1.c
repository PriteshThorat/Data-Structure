#include <stdio.h>
#include <stdlib.h>

// Define a structure for the tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the Binary Search Tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged root pointer
    return root;
}

// Function for pre-order traversal of the tree
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);      // Print node data
        preOrderTraversal(root->left);   // Visit left subtree
        preOrderTraversal(root->right);  // Visit right subtree
    }
}

// Function to free the allocated memory for the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);   // Free left subtree
        freeTree(root->right);  // Free right subtree
        free(root);             // Free the current node
    }
}

int main() {
    struct Node* root = NULL; // Initialize the root of the BST

    // Elements to be inserted into the Binary Search Tree
    int elements[] = {1, 5, 7, 8, 10, 12};
    int n = sizeof(elements) / sizeof(elements[0]);

    // Insert elements into the Binary Search Tree
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Display the tree using pre-order traversal
    printf("Pre-order Traversal of the Binary Search Tree:\n");
    preOrderTraversal(root);
    printf("\n");

    // Clean up and free the memory
    freeTree(root);
    return 0;
}
