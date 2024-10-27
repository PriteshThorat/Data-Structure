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

// Function to search for a key element in the Binary Search Tree
struct Node* search(struct Node* root, int key) {
    // Base case: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's data, search in the right subtree
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than root's data, search in the left subtree
    return search(root->left, key);
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

    // Insert nodes into the Binary Search Tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for a key element in the BST
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Key %d found in the BST.\n", key);
    } else {
        printf("Key %d not found in the BST.\n", key);
    }

    // Clean up and free the memory
    freeTree(root);
    return 0;
}
