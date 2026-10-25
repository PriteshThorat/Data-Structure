#include<iostream>

using namespace std;

void printArray (int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << "Element: " << arr[i] << "\n";
  }
}

int partition (int* arr, int low, int high) {
  int pivot = arr[low];
  int i = low + 1;
  int j = high;

  do {
    while (arr[i] <= pivot) {
      i++;
    }

    while (arr[j] >= pivot) {
      j--;
    }

    if (i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  } while (i < j);

  int temp = arr[low];
  arr[low] = arr[j];
  arr[j] = temp;

  return j;
}

void quickSort (int* arr, int low, int high) {
  int partitionIndex;

  if (low < high) {
    partitionIndex = partition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
  }
}

int main () {
  int arr[] = {33, 11, 22, 55, 44};
  int size = 5;

  cout << "Before Quick Sort:-\n";
  printArray(arr, size);

  quickSort(arr, 0, size - 1);

  cout << "After Quick Sort:-\n";
  printArray(arr, 5);

  return 0;
}