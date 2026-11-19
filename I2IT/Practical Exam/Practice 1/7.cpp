// Implement a Binary Search Tree in C++ supporting insertion, deletion, searching, traversals, height, mirroring,
// copying.

#include <iostream>

using namespace std;

// Node structure
struct Node {
  int data;
  Node *left;
  Node *right;
};

// Binary Search Tree
class BST {
  Node *root;

  // Create new node
  Node *createNode(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  // Insert node
  Node *insert(Node *node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);

    return node;
  }

  // Search node
  bool search(Node *node, int value) {
    if (node == NULL) return false;

    if (node->data == value) return true;

    if (value < node->data) return search(node->left, value);

    return search(node->right, value);
  }

  // Find minimum value node
  Node *findMin(Node *node) {
    while (node->left != NULL)
      node = node->left;

    return node;
  }

  // Delete node
  Node *deleteNode(Node *node, int value) {
    if (node == NULL) return NULL;

    if (value < node->data) {
      node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
      node->right = deleteNode(node->right, value);
    } else {
      // Case 1: No child
      if (node->left == NULL && node->right == NULL) {
        delete node;
        return NULL;
      }

      // Case 2: One child
      else if (node->left == NULL) {
        Node *temp = node->right;
        delete node;
        return temp;
      } else if (node->right == NULL) {
        Node *temp = node->left;
        delete node;
        return temp;
      }

      // Case 3: Two children
      Node *temp = findMin(node->right);
      node->data = temp->data;
      node->right = deleteNode(node->right, temp->data);
    }

    return node;
  }

  // Inorder traversal
  void inorder(Node *node) {
    if (node != NULL) {
      inorder(node->left);
      cout << node->data << " ";
      inorder(node->right);
    }
  }

  // Preorder traversal
  void preorder(Node *node) {
    if (node != NULL) {
      cout << node->data << " ";
      preorder(node->left);
      preorder(node->right);
    }
  }

  // Postorder traversal
  void postorder(Node *node) {
    if (node != NULL) {
      postorder(node->left);
      postorder(node->right);
      cout << node->data << " ";
    }
  }

  // Calculate height
  int height(Node *node) {
    if (node == NULL) return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return 1 + max(leftHeight, rightHeight);
  }

  // Mirror tree
  void mirror(Node *node) {
    if (node == NULL) return;

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);
  }

  // Copy tree
  Node *copyTree(Node *node) {
    if (node == NULL) return NULL;

    Node *newNode = createNode(node->data);

    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
  }

  // Free memory
  void destroy(Node *node) {
    if (node != NULL) {
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }

public:
  BST() { root = NULL; }

  ~BST() { destroy(root); }

  void insert(int value) { root = insert(root, value); }

  void deleteValue(int value) { root = deleteNode(root, value); }

  void searchValue(int value) {
    if (search(root, value)) cout << value << " found in BST.\n";
    else cout << value << " not found in BST.\n";
  }

  void displayInorder() {
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
  }

  void displayPreorder() {
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
  }

  void displayPostorder() {
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
  }

  void displayHeight() { cout << "Height of BST: " << height(root) << endl; }

  void mirrorTree() {
    mirror(root);
    cout << "BST mirrored successfully.\n";
  }

  void copyTo(BST &other) {
    other.destroy(other.root);
    other.root = copyTree(root);
    cout << "BST copied successfully.\n";
  }
};

int main() {
  BST tree, copiedTree;
  int choice, value;

  do {
    cout << "\n--- Binary Search Tree ---\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Inorder Traversal\n";
    cout << "5. Preorder Traversal\n";
    cout << "6. Postorder Traversal\n";
    cout << "7. Height of BST\n";
    cout << "8. Mirror BST\n";
    cout << "9. Copy BST\n";
    cout << "10. Display Copied BST\n";
    cout << "11. Exit\n";

    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value: ";
      cin >> value;
      tree.insert(value);
      cout << "Node inserted successfully.\n";
      break;

    case 2:
      cout << "Enter value to delete: ";
      cin >> value;
      tree.deleteValue(value);
      cout << "Deletion operation completed.\n";
      break;

    case 3:
      cout << "Enter value to search: ";
      cin >> value;
      tree.searchValue(value);
      break;

    case 4:
      tree.displayInorder();
      break;

    case 5:
      tree.displayPreorder();
      break;

    case 6:
      tree.displayPostorder();
      break;

    case 7:
      tree.displayHeight();
      break;

    case 8:
      tree.mirrorTree();
      break;

    case 9:
      tree.copyTo(copiedTree);
      break;

    case 10:
      copiedTree.displayInorder();
      break;

    case 11:
      cout << "Exiting program.\n";
      break;

    default:
      cout << "Invalid choice!\n";
    }

  } while (choice != 11);

  return 0;
}