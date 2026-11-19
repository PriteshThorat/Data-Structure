// Develop a C++ Student Record System using dynamic memory allocation.
// Implement Linear Search and Binary Search to find student records by ID and analyze the number of comparisons and
// time complexity.

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Student {
  int id;
  string name;
  float marks;
};

// Linear Search
int linearSearch(Student *s, int n, int key, int &comparisons) {
  comparisons = 0;

  for (int i = 0; i < n; i++) {
    comparisons++;

    if (s[i].id == key) {
      return i;
    }
  }

  return -1;
}

// Binary Search
// Records must be sorted by ID
int binarySearch(Student *s, int n, int key, int &comparisons) {
  int low = 0, high = n - 1;
  comparisons = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    comparisons++;

    if (s[mid].id == key) {
      return mid;
    } else if (s[mid].id < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int n;

  cout << "Enter number of students: ";
  cin >> n;

  if (n <= 0) {
    cout << "Invalid number of students!";
    return 0;
  }

  // Dynamic memory allocation
  Student *students = new Student[n];

  // Input student records
  for (int i = 0; i < n; i++) {
    cout << "\nEnter details of Student " << i + 1 << endl;

    cout << "Student ID: ";
    cin >> students[i].id;

    cin.ignore();

    cout << "Student Name: ";
    getline(cin, students[i].name);

    cout << "Marks: ";
    cin >> students[i].marks;
  }

  // Sort records by ID for Binary Search
  sort(students, students + n, [](const Student &a, const Student &b) { return a.id < b.id; });

  cout << "\n--- Student Records (Sorted by ID) ---\n";

  for (int i = 0; i < n; i++) {
    cout << "\nID: " << students[i].id;
    cout << "\nName: " << students[i].name;
    cout << "\nMarks: " << students[i].marks << endl;
  }

  int key, choice;
  int comparisons, result;

  cout << "\nEnter Student ID to search: ";
  cin >> key;

  cout << "\n1. Linear Search";
  cout << "\n2. Binary Search";
  cout << "\nEnter your choice: ";
  cin >> choice;

  if (choice == 1) {
    result = linearSearch(students, n, key, comparisons);
  } else if (choice == 2) {
    result = binarySearch(students, n, key, comparisons);
  } else {
    cout << "Invalid choice!";
    delete[] students;
    return 0;
  }

  if (result != -1) {
    cout << "\nStudent Found!";
    cout << "\nID: " << students[result].id;
    cout << "\nName: " << students[result].name;
    cout << "\nMarks: " << students[result].marks;
  } else {
    cout << "\nStudent Not Found!";
  }

  cout << "\nNumber of Comparisons: " << comparisons << endl;

  // Free dynamically allocated memory
  delete[] students;

  return 0;
}