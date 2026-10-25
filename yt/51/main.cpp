#include<iostream>

using namespace std;

void printArray (int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << "Element: " << arr[i] << "\n";
  }
}

void bubbleSort (int* arr, int size) {
  bool isSorted = true;

  for (int i = 0; i < size - 1; i++) {
    isSorted = true;

    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        isSorted = false;

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }

    if (isSorted) {
      return;
    }
  }
}

int main () {
  int arr[] = {55, 33, 11, 22, 44};

  cout << "Before Sorting:-\n";
  printArray(arr, 5);

  bubbleSort(arr, 5);

  cout << "After Sorting:-\n";
  printArray(arr, 5);

  return 0;
}