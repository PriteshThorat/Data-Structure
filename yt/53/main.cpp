#include<iostream>

using namespace std;

void printArray (int* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    cout << "Element: " << arr[i] << "\n";
  }
}

void insertionSort (int* arr, int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];

      j--;
    }
    arr[j + 1] = key;
  }
}

int main () {
  int arr[] = {55, 11, 22, 44, 33};

  cout << "Before Insertion Sort:-\n";
  printArray(arr, 5);

  insertionSort(arr, 5);

  cout << "After Insertion Sort:-\n";
  printArray(arr, 5);

  return 0;
}