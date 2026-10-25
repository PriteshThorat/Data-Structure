#include<iostream>

using namespace std;

void printArray (int* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << "Element: " << arr[i] << "\n";
  }
}

void merge (int* arr, int mid, int low, int high) {
  int i, j, k, copyArr[100];
  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high) {
    if (arr[i] < arr[j]) {
      copyArr[k] = arr[i];

      i++;
      k++;
    } else {
      copyArr[k] = arr[j];

      j++;
      k++;
    }
  }

  while (i <= mid) {
    copyArr[k] = arr[i];

    k++;
    i++;
  }
  while (j <= high) {
    copyArr[k] = arr[j];

    k++;
    j++;
  }
  
  for (int i = low; i <= high; i++) {
    arr[i] = copyArr[i];
  }
}

void mergeSort (int* arr, int low, int high) {
  int mid;

  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, mid, low, high);
  }
}

int main () {
  int arr[] = {33, 55, 11, 22, 44};
  int n = 5;

  cout << "Before Merge Sort:-\n";
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  cout << "After Merge Sort:-\n";
  printArray(arr, n);

  return 0;
}