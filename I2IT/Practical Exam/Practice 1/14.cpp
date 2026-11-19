// Design a C++ hash table for library book management using Book ID as the key.
// Handle collisions using Linear Probing and Chaining and compare their collision
// counts.

#include <iostream>
#include <list>
#include <string>

using namespace std;

const int SIZE = 7;

struct Book {
  int id;
  string title;
};

// Hash function
int hashFunction(int id) { return id % SIZE; }

// Linear Probing
class LinearProbing {
  Book table[SIZE];
  bool occupied[SIZE] = {};

public:
  int collisions = 0;

  void insert(int id, string title) {
    int index = hashFunction(id);
    int start = index;

    while (occupied[index]) {
      collisions++;
      index = (index + 1) % SIZE;

      if (index == start) {
        cout << "Hash Table is Full!\n";
        return;
      }
    }

    table[index] = {id, title};
    occupied[index] = true;
  }

  void display() {
    cout << "\nLinear Probing:\n";

    for (int i = 0; i < SIZE; i++) {
      cout << i << " : ";

      if (occupied[i]) cout << table[i].id << " - " << table[i].title;
      else cout << "Empty";

      cout << endl;
    }
  }
};

// Chaining
class Chaining {
  list<Book> table[SIZE];

public:
  int collisions = 0;

  void insert(int id, string title) {
    int index = hashFunction(id);

    if (!table[index].empty()) collisions++;

    table[index].push_back({id, title});
  }

  void display() {
    cout << "\nChaining:\n";

    for (int i = 0; i < SIZE; i++) {
      cout << i << " : ";

      for (auto book : table[i]) {
        cout << "[" << book.id << " - " << book.title << "] -> ";
      }

      cout << "NULL\n";
    }
  }
};

int main() {
  int n, id;
  string title;

  LinearProbing lp;
  Chaining ch;

  cout << "Enter number of books: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "\nEnter Book ID: ";
    cin >> id;

    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);

    lp.insert(id, title);
    ch.insert(id, title);
  }

  lp.display();
  ch.display();

  cout << "\nCollision Comparison:\n";
  cout << "Linear Probing Collisions: " << lp.collisions << endl;

  cout << "Chaining Collisions: " << ch.collisions << endl;

  return 0;
}
