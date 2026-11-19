// Develop a C++ Student Record System using dynamic memory allocation.
// Implement Linear Search and Binary Search to find student records by ID and analyze the number of comparisons and
// time complexity.

#include <iostream>

using namespace std;

struct Data {
  int id;
  string name;
};

class Student {
  public:
    void input (Data* data, int size) {
      for (int i = 0; i < size; i++) {
        cout << "Enter the Student ID: ";
        cin >> data[i].id;
        cout << "Enter the Student Name: ";
        cin >> data[i].name;
      }
    }

    void display (Data* data, int size) {
      cout << "Student Data:-\n";

      for (int i = 0; i < size; i++) {
        cout << "Student ID: " << data[i].id << " | ";
        cout << "Student Name: " << data[i].name << endl;
      }
    }

    int linearSearch (Data* data, int size) {
      int comparisons = 0;
      int id;

      cout << "Linear Search:-\n";

      cout << "Enter the ID which you want to search: ";
      cin >> id;

      for (int i = 0; i < size; i++) {
        comparisons++;

        if (data[i].id == id) {
          cout << "The Student having ID " << id << ", with Name " << data[i].name << " is Found.\n";

          return comparisons;
        }
      }

      cout << "The Student with " << id << " ID Not Found.\n";
      
      return -1;
    }

    int binarySearch (Data* data, int size) {
      int low = 0;
      int high = size - 1;
      int comparisons = 0;
      int id;

      cout << "Binary Search:-\n";

      cout << "Enter the ID which you want to search: ";
      cin >> id;

      while (low <= high) {
        comparisons++;

        int mid = (low + high) / 2;

        if (data[mid].id == id) {
          cout << "The Student having ID " << id << ", with Name " << data[mid].name << " is Found.\n";

          return comparisons;
        } else if (data[mid].id < id) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }

      cout << "The Student with " << id << " ID Not Found.\n";
      
      return -1;
    }
};

int main () {
  Student* s = new Student();

  int size;

  cout << "Enter the number of students to be inserted: ";
  cin >> size;

  Data* data = new Data[size];
  s->input(data, size);
  s->display(data, size);

  cout << "The Number of Comparisons in Linear Search are: " << s->linearSearch(data, size) << endl;
  cout << "The Number of Comparisons in Binary Search are: " << s->binarySearch(data, size) << endl;

  return 0;
}