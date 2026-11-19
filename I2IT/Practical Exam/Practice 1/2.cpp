// Develop a C++ program to manage e-commerce product records and implement Selection Sort and Insertion Sort to sort
// products by customer rating (descending order) and product name (alphabetical order).

#include <iostream>
#include <string>

using namespace std;

struct Product {
  int id;
  string name;
  float price;
  float rating;
};

// Function to display products
void displayProducts(Product p[], int n) {
  cout << "\nID\tName\t\tPrice\tRating\n";
  cout << "------------------------------------------\n";

  for (int i = 0; i < n; i++) {
    cout << p[i].id << "\t" << p[i].name << "\t\t" << p[i].price << "\t" << p[i].rating << endl;
  }
}

// Selection Sort by Rating (Descending)
void selectionSort(Product p[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int maxIndex = i;

    for (int j = i + 1; j < n; j++) {
      if (p[j].rating > p[maxIndex].rating) {
        maxIndex = j;
      }
    }

    // Swap products
    if (maxIndex != i) {
      Product temp = p[i];
      p[i] = p[maxIndex];
      p[maxIndex] = temp;
    }
  }
}

// Insertion Sort by Name (Alphabetical)
void insertionSort(Product p[], int n) {
  for (int i = 1; i < n; i++) {
    Product key = p[i];
    int j = i - 1;

    while (j >= 0 && p[j].name > key.name) {
      p[j + 1] = p[j];
      j--;
    }

    p[j + 1] = key;
  }
}

int main() {
  int n;

  cout << "Enter number of products: ";
  cin >> n;

  if (n <= 0) {
    cout << "Invalid number of products!";
    return 0;
  }

  Product *products = new Product[n];

  // Input product details
  for (int i = 0; i < n; i++) {
    cout << "\nEnter details of Product " << i + 1 << endl;

    cout << "Product ID: ";
    cin >> products[i].id;

    cin.ignore();

    cout << "Product Name: ";
    getline(cin, products[i].name);

    cout << "Product Price: ";
    cin >> products[i].price;

    cout << "Customer Rating (out of 5): ";
    cin >> products[i].rating;
  }

  cout << "\nOriginal Product Records:";
  displayProducts(products, n);

  int choice;

  do {
    cout << "\n\n===== E-COMMERCE PRODUCT MANAGEMENT =====";
    cout << "\n1. Sort by Customer Rating (Descending)";
    cout << "\n2. Sort by Product Name (Alphabetical)";
    cout << "\n3. Display Products";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      selectionSort(products, n);
      cout << "\nProducts Sorted by Rating (Descending):";
      displayProducts(products, n);
      break;

    case 2:
      insertionSort(products, n);
      cout << "\nProducts Sorted by Name (A-Z):";
      displayProducts(products, n);
      break;

    case 3:
      displayProducts(products, n);
      break;

    case 4:
      cout << "\nExiting Program...";
      break;

    default:
      cout << "\nInvalid Choice!";
    }

  } while (choice != 4);

  // Free dynamically allocated memory
  delete[] products;

  return 0;
}