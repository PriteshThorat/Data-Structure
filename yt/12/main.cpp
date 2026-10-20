#include <iostream>

using namespace std;

int linearSearch (int arr[], int size, int element) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == element) {
      return i;
    }
  }

  return -1;
}

int binarySearch (int arr[], int size, int element) {
  int low = 0;
  int high = size - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (arr[mid] == element) {
      return mid;
    } else if (arr[mid] < element) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main () {
  // Unsorted Array
  // int arr[] = {50, 40, 20, 10, 30};
  // int size = sizeof(arr) / sizeof(int);
  // int element = 20;
  // int searchIndex = linearSearch(arr, size, element);
  // cout << "The element " << element << " was found at index " << searchIndex; 

  // Sorted Array
  int arr[] = {10, 20, 30, 40, 50};
  int size = sizeof(arr) / sizeof(int);
  int element = 30;
  int searchIndex = binarySearch(arr, size, element);
  cout << "The element " << element << " was found at index " << searchIndex; 

  return 0;
}