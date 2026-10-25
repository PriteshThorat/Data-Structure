#include<iostream>

using namespace std;

void printArray (int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << "Element: " << arr[i] << "\n";
  }
}

void selectionSort (int* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

int main () {
  int arr[] = {22, 33, 11, 44, 55};

  cout << "Before Selection Sort:-\n";
  printArray(arr, 5);

  selectionSort(arr, 5);
  
  cout << "After Selection Sort:-\n";
  printArray(arr, 5);

  return 0;
}