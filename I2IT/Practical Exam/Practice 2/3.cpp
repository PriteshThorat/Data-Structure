// Design and implement a C++ program to manage e-commerce product records containing Product ID, Product Name, and
// Price. Implement Bubble Sort and Merge Sort to arrange the products by price in both ascending and descending order.

#include <iostream>
#include <string>

using namespace std;

struct ProductData {
  int productId;
  string productName;
  float productPrice;
};

class Product {
  public:
    void insert (ProductData* productData, int index, int productId, string productName, float productPrice) {
      productData[index].productId = productId;
      productData[index].productName = productName;
      productData[index].productPrice = productPrice;
    }

    void display (ProductData* productData, int size) {
      cout << "Product Data:-\n";

      for (int i = 0; i < size; i++) {
        cout << productData[i].productId << " | ";
        cout << productData[i].productName << " | ";
        cout << productData[i].productPrice << endl;
      }
    }

    void bubbleSort (ProductData* productData, int size) {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
          if (productData[j].productPrice > productData[j + 1].productPrice) {
            ProductData temp = productData[j];
            productData[j] = productData[j + 1];
            productData[j + 1] = temp;
          }
        }
      }
    }

    static void merge (ProductData* productData, int start, int mid, int end) {
      ProductData* temp = new ProductData[end - start + 1];

      int counter = 0;
      int i = start;
      int j = mid + 1;

      while (i <= mid && j <= end) {
        if (productData[i].productPrice >= productData[j].productPrice) {
          temp[counter] =  productData[i];

          i++;
          counter++;
        } else {
          temp[counter] = productData[j];

          j++;
          counter++;
        }
      }

      while (i <= mid) {
        temp[counter] =  productData[i];

        i++;
        counter++;
      }

      while (j <= end) {
        temp[counter] = productData[j];

        j++;
        counter++;
      }

      for (int idx = 0; idx < counter; idx++) {
        productData[idx + start] = temp[idx];
      }

      delete[] temp;
    }

    void mergeSort (ProductData* productData, int start, int end) {
      if (start < end) {
        int mid = (start + end) / 2;

        mergeSort(productData, start, mid);
        mergeSort(productData, mid + 1, end);

        merge(productData, start, mid, end);
      }
    }
};

int main () {
  Product* product = new Product();

  int size;

  cout << "Enter the number of products you will Enter: ";
  cin >> size;

  ProductData* productData = new ProductData[size];

  product->insert(productData, 0, 101, "B", 500);
  product->insert(productData, 1, 102, "D", 100);
  product->insert(productData, 2, 103, "A", 300.4);
  product->insert(productData, 3, 104, "S", 200);
  product->insert(productData, 4, 105, "C", 500);

  cout << "Before Bubble Sort:-\n";
  product->display(productData, size);

  product->bubbleSort(productData, size);

  cout << "After Bubble Sort:-\n";
  product->display(productData, size);

  cout << "Before Merge Sort:-\n";
  product->display(productData, size);

  product->mergeSort(productData, 0, size - 1);

  cout << "After Merge Sort:-\n";
  product->display(productData, size);

  return 0;
}