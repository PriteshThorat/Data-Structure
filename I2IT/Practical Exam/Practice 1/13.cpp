// Implement Heap Sort in C++ to sort integers in ascending order. Demonstrate
// heap construction and heapify, and analyze time and space complexity.

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) largest = left;

  if (right < n && arr[right] > arr[largest]) largest = right;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  // Build Max Heap
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  cout << "\nMax Heap: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  // Perform Heap Sort
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  int n;

  cout << "Enter number of elements: ";
  cin >> n;

  if (n <= 0) {
    cout << "Invalid array size!";
    return 0;
  }

  int *arr = new int[n];

  cout << "Enter " << n << " integers: ";

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nOriginal Array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  heapSort(arr, n);

  cout << "\n\nSorted Array (Ascending): ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  delete[] arr;

  return 0;
}