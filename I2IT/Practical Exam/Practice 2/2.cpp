// Develop a C++ program to manage e-commerce product records and implement Selection Sort and Insertion Sort to sort
// products by customer rating (descending order) and product name (alphabetical order).

#include <iostream>
#include <string>

using namespace std;

struct ProductData {
  int productId;
  string productName;
  float productRating;
};

class Product {
  public:
    void input (ProductData* productData, int index, int productId, string productName, float productRating) {
      productData[index].productId = productId;
      productData[index].productName = productName;
      productData[index].productRating = productRating;
    }

    void display (ProductData* productData, int size) {
      cout << "Product Details:-\n";

      for (int i = 0; i < size; i++) {
        cout << "Product ID: " << productData[i].productId << " | ";
        cout << "Product Name: " << productData[i].productName << " | ";
        cout << "Product Rating: " << productData[i].productRating << endl;
      }
    }

    void selectionSort (ProductData* productData, int size) {
      for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
          if (productData[i].productRating < productData[j].productRating) {
            struct ProductData temp = productData[i];
            productData[i] = productData[j];
            productData[j] = temp;
          }
        }
      }
    }

    void insertionSort (ProductData* productData, int size) {
      for (int i = 1; i < size; i++) {
        struct ProductData current = productData[i];
        int prev = i - 1;

        while (prev >= 0 && productData[prev].productName.compare(current.productName) > 0) {
          productData[prev + 1] = productData[prev];

          prev--;
        }
        productData[prev + 1] = current;
      }
    }
};

int main () {
  Product* product = new Product();

  int size;

  cout << "Enter how many products you want to insert: ";
  cin >> size;

  ProductData* productData = new ProductData[size];

  product->input(productData, 0, 101, "B", 5);
  product->input(productData, 1, 102, "D", 1);
  product->input(productData, 2, 103, "A", 3.4);
  product->input(productData, 3, 104, "S", 2);
  product->input(productData, 4, 105, "C", 5);

  product->display(productData, size);

  product->selectionSort(productData, size);
  
  cout << "After Selection Sort:-\n";
  product->display(productData, size);

  product->insertionSort(productData, size);

  cout << "After Insertion Sort:-\n";
  product->display(productData, size);

  return 0;
}