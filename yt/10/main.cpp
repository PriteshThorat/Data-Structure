#include <iostream>

using namespace std;

void display (int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i];

    if (!(i == n-1)) {
      cout << ", ";
    }
  }

  cout << "\n";
}

int indInsertion (int arr[], int size, int element, int capacity, int index) {
  if (size >= capacity) {
    return -1;
  }

  for (int i = size - 1; i >= index; i--) {
    arr[i + 1] = arr[i];
  }

  arr[index] = element;
  return 1;
}

int main () {
  int arr[100] = {7, 8, 12, 27, 88};
  int size = 5, element = 45, index = 3;
  display(arr, size);
  int isInserted = indInsertion(arr, size, element, 100, index);

  if (isInserted) {
    size += 1;
    display(arr, size);
    cout << "Element Successfully Inserted at " << index << " index";
  } else {
    cout << "Element Insertion Unsuccessful, size is full of array";
  }

  return 0;
}