// Design and implement a C++ program to manage e-commerce product records containing Product ID, Product Name, and
// Price. Implement Bubble Sort and Merge Sort to arrange the products by price in both ascending and descending order.

#include <iostream>
#include <string>

using namespace std;

struct Product {
  int id;
  string name;
  float price;
};

// Display product records
void display(Product p[], int n) {
  cout << "\nID\tName\t\tPrice\n";
  cout << "--------------------------------\n";

  for (int i = 0; i < n; i++) {
    cout << p[i].id << "\t" << p[i].name << "\t\t" << p[i].price << endl;
  }
}

// Bubble Sort
// order = 1 for ascending
// order = 2 for descending
void bubbleSort(Product p[], int n, int order) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;

    for (int j = 0; j < n - i - 1; j++) {

      bool condition;

      if (order == 1) condition = p[j].price > p[j + 1].price;
      else condition = p[j].price < p[j + 1].price;

      if (condition) {
        Product temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;

        swapped = true;
      }
    }

    if (!swapped) break;
  }
}

// Merge two sorted portions
void merge(Product p[], int left, int mid, int right, int order) {

  int n1 = mid - left + 1;
  int n2 = right - mid;

  Product *L = new Product[n1];
  Product *R = new Product[n2];

  for (int i = 0; i < n1; i++)
    L[i] = p[left + i];

  for (int j = 0; j < n2; j++)
    R[j] = p[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {

    bool takeLeft;

    if (order == 1) takeLeft = L[i].price <= R[j].price;
    else takeLeft = L[i].price >= R[j].price;

    if (takeLeft) p[k++] = L[i++];
    else p[k++] = R[j++];
  }

  while (i < n1)
    p[k++] = L[i++];

  while (j < n2)
    p[k++] = R[j++];

  delete[] L;
  delete[] R;
}

// Merge Sort
void mergeSort(Product p[], int left, int right, int order) {

  if (left < right) {

    int mid = left + (right - left) / 2;

    mergeSort(p, left, mid, order);

    mergeSort(p, mid + 1, right, order);

    merge(p, left, mid, right, order);
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

  // Dynamic memory allocation
  Product *products = new Product[n];

  // Input product details
  for (int i = 0; i < n; i++) {

    cout << "\nEnter Product " << i + 1 << " details:\n";

    cout << "Product ID: ";
    cin >> products[i].id;

    cin.ignore();

    cout << "Product Name: ";
    getline(cin, products[i].name);

    cout << "Price: ";
    cin >> products[i].price;
  }

  int choice, order;

  do {
    cout << "\n===== E-COMMERCE PRODUCT MANAGEMENT =====";
    cout << "\n1. Bubble Sort";
    cout << "\n2. Merge Sort";
    cout << "\n3. Display Products";
    cout << "\n4. Exit";

    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1 || choice == 2) {

      cout << "\n1. Ascending Order";
      cout << "\n2. Descending Order";
      cout << "\nEnter sorting order: ";
      cin >> order;

      if (order != 1 && order != 2) {
        cout << "\nInvalid sorting order!";
        continue;
      }

      if (choice == 1) {

        bubbleSort(products, n, order);

        cout << "\nProducts Sorted Using Bubble Sort";
      } else {

        mergeSort(products, 0, n - 1, order);

        cout << "\nProducts Sorted Using Merge Sort";
      }

      display(products, n);
    } else if (choice == 3) {

      cout << "\nProduct Records:";
      display(products, n);
    } else if (choice == 4) {

      cout << "\nExiting Program...";
    } else {

      cout << "\nInvalid Choice!";
    }

  } while (choice != 4);

  // Release dynamically allocated memory
  delete[] products;

  return 0;
}