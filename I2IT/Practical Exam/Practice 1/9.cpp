// Represent a graph using an adjacency matrix or adjacency list and implement
// Breadth First Search (BFS) and Depth First Search (DFS).

#include <iostream>
#include <queue>

using namespace std;

#define MAX 20

class Graph {
  int adj[MAX][MAX];
  int vertices;

public:
  Graph(int v) {
    vertices = v;

    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        adj[i][j] = 0;
      }
    }
  }

  // Add edge
  void addEdge(int u, int v) {
    if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
      cout << "Invalid vertex!\n";
      return;
    }

    adj[u][v] = 1;
    adj[v][u] = 1;

    cout << "Edge added successfully.\n";
  }

  // Display adjacency matrix
  void display() {
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        cout << adj[i][j] << " ";
      }
      cout << endl;
    }
  }

  // Breadth First Search
  void BFS(int start) {
    if (start < 0 || start >= vertices) {
      cout << "Invalid starting vertex!\n";
      return;
    }

    bool visited[MAX] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      cout << current << " ";

      for (int i = 0; i < vertices; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
          visited[i] = true;
          q.push(i);
        }
      }
    }

    cout << endl;
  }

  // DFS Helper Function
  void DFSUtil(int vertex, bool visited[]) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < vertices; i++) {
      if (adj[vertex][i] == 1 && !visited[i]) {
        DFSUtil(i, visited);
      }
    }
  }

  // Depth First Search
  void DFS(int start) {
    if (start < 0 || start >= vertices) {
      cout << "Invalid starting vertex!\n";
      return;
    }

    bool visited[MAX] = {false};

    cout << "DFS Traversal: ";
    DFSUtil(start, visited);

    cout << endl;
  }
};

int main() {
  int v, choice, u, w, start;

  cout << "Enter number of vertices: ";
  cin >> v;

  if (v <= 0 || v > MAX) {
    cout << "Invalid number of vertices!\n";
    return 0;
  }

  Graph g(v);

  do {
    cout << "\n--- Graph Operations ---\n";
    cout << "1. Add Edge\n";
    cout << "2. Display Adjacency Matrix\n";
    cout << "3. Breadth First Search (BFS)\n";
    cout << "4. Depth First Search (DFS)\n";
    cout << "5. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter two vertices: ";
      cin >> u >> w;
      g.addEdge(u, w);
      break;

    case 2:
      g.display();
      break;

    case 3:
      cout << "Enter starting vertex: ";
      cin >> start;
      g.BFS(start);
      break;

    case 4:
      cout << "Enter starting vertex: ";
      cin >> start;
      g.DFS(start);
      break;

    case 5:
      cout << "Exiting program.\n";
      break;

    default:
      cout << "Invalid choice!\n";
    }

  } while (choice != 5);

  return 0;
}
