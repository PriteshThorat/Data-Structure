// Implement a Binary Search Tree in C++ supporting insertion, deletion, searching,
// traversals, parent-child display, leaf-node display, and level-wise traversal.

#include <iostream>
#include <queue>

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

  // Find minimum node
  Node *findMin(Node *node) {
    while (node->left != NULL)
      node = node->left;

    return node;
  }

  // Delete node
  Node *deleteNode(Node *node, int value) {
    if (node == NULL) return NULL;

    if (value < node->data) node->left = deleteNode(node->left, value);

    else if (value > node->data) node->right = deleteNode(node->right, value);

    else {
      // No child
      if (node->left == NULL && node->right == NULL) {
        delete node;
        return NULL;
      }

      // Only right child
      else if (node->left == NULL) {
        Node *temp = node->right;
        delete node;
        return temp;
      }

      // Only left child
      else if (node->right == NULL) {
        Node *temp = node->left;
        delete node;
        return temp;
      }

      // Two children
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

  // Parent-child display
  void parentChild(Node *node) {
    if (node == NULL) return;

    if (node->left != NULL) cout << "Parent: " << node->data << " Left Child: " << node->left->data << endl;

    if (node->right != NULL) cout << "Parent: " << node->data << " Right Child: " << node->right->data << endl;

    parentChild(node->left);
    parentChild(node->right);
  }

  // Display leaf nodes
  void leafNodes(Node *node) {
    if (node == NULL) return;

    if (node->left == NULL && node->right == NULL) {
      cout << node->data << " ";
      return;
    }

    leafNodes(node->left);
    leafNodes(node->right);
  }

  // Level-wise traversal
  void levelOrder(Node *node) {
    if (node == NULL) return;

    queue<Node *> q;
    q.push(node);

    while (!q.empty()) {
      Node *current = q.front();
      q.pop();

      cout << current->data << " ";

      if (current->left != NULL) q.push(current->left);

      if (current->right != NULL) q.push(current->right);
    }
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

  void displayParentChild() {
    if (root == NULL) {
      cout << "BST is empty.\n";
      return;
    }

    cout << "Parent-Child Relationships:\n";
    cout << "Root Node: " << root->data << endl;
    parentChild(root);
  }

  void displayLeafNodes() {
    if (root == NULL) {
      cout << "BST is empty.\n";
      return;
    }

    cout << "Leaf Nodes: ";
    leafNodes(root);
    cout << endl;
  }

  void displayLevelOrder() {
    if (root == NULL) {
      cout << "BST is empty.\n";
      return;
    }

    cout << "Level-wise Traversal: ";
    levelOrder(root);
    cout << endl;
  }
};

int main() {
  BST tree;
  int choice, value;

  do {
    cout << "\n--- Binary Search Tree ---\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Inorder Traversal\n";
    cout << "5. Preorder Traversal\n";
    cout << "6. Postorder Traversal\n";
    cout << "7. Parent-Child Display\n";
    cout << "8. Leaf Node Display\n";
    cout << "9. Level-wise Traversal\n";
    cout << "10. Exit\n";

    cout << "Enter your choice: ";
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
      tree.displayParentChild();
      break;

    case 8:
      tree.displayLeafNodes();
      break;

    case 9:
      tree.displayLevelOrder();
      break;

    case 10:
      cout << "Exiting program.\n";
      break;

    default:
      cout << "Invalid choice!\n";
    }

  } while (choice != 10);

  return 0;
}
