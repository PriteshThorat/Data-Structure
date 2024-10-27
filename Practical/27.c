#include <stdio.h>
#include <stdlib.h>

// Structure for the node in the Binary Search Tree
struct Node {
    int data;              // The value of the node
    struct Node* left;     // Pointer to the left child
    struct Node* right;    // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(data);
    }
    // Recur down the tree to find the correct position
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Return the unchanged root pointer
    return root;
}

// Function for pre-order traversal of the BST
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        // First, visit the root
        printf("%d ", root->data);
        // Then, visit the left child
        preOrderTraversal(root->left);
        // Finally, visit the right child
        preOrderTraversal(root->right);
    }
}

// Function for post-order traversal of the BST
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        // First, visit the left child
        postOrderTraversal(root->left);
        // Then, visit the right child
        postOrderTraversal(root->right);
        // Finally, visit the root
        printf("%d ", root->data);
    }
}

// Main function to demonstrate BST operations
int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    // Perform pre-order traversal
    printf("Pre-Order Traversal of the BST: ");
    preOrderTraversal(root);
    printf("\n");

    // Perform post-order traversal
    printf("Post-Order Traversal of the BST: ");
    postOrderTraversal(root);
    printf("\n");

    // Free allocated memory for the BST (not shown here for simplicity)
    // Proper memory management should be implemented in a complete program.

    return 0;
}

/*[?2004l
Pre-Order Traversal of the BST: 10 5 3 7 15 12 18 
Post-Order Traversal of the BST: 3 7 5 12 18 15 10 
[?2004h*/