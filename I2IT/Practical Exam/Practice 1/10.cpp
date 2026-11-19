// Represent a college campus map as a weighted graph, where vertices represent
// campus locations and edges represent the distances between them. Implement
// Prim’s Algorithm in C++ to find and display the Minimum Spanning Tree (MST)
// with its total minimum cost.

#include <iostream>
using namespace std;

#define MAX 20
#define INF 99999

class Graph {
  int vertices;
  int cost[MAX][MAX];

public:
  Graph(int v) {
    vertices = v;

    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        if (i == j) cost[i][j] = 0;
        else cost[i][j] = INF;
      }
    }
  }

  // Add weighted edge
  void addEdge(int u, int v, int weight) {
    if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
      cout << "Invalid location!\n";
      return;
    }

    if (weight <= 0) {
      cout << "Distance must be positive!\n";
      return;
    }

    cost[u][v] = weight;
    cost[v][u] = weight;

    cout << "Path added successfully.\n";
  }

  // Display adjacency matrix
  void display() {
    cout << "\nWeighted Adjacency Matrix:\n";

    for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
        if (cost[i][j] == INF) cout << "INF\t";
        else cout << cost[i][j] << "\t";
      }
      cout << endl;
    }
  }

  // Prim's Algorithm
  void primsMST() {
    int parent[MAX];
    int key[MAX];
    bool visited[MAX] = {false};

    for (int i = 0; i < vertices; i++) {
      key[i] = INF;
      parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < vertices; count++) {
      int min = INF;
      int u = -1;

      // Find minimum key vertex
      for (int i = 0; i < vertices; i++) {
        if (!visited[i] && key[i] < min) {
          min = key[i];
          u = i;
        }
      }

      // Check disconnected graph
      if (u == -1) {
        cout << "\nGraph is disconnected. MST cannot be formed.\n";
        return;
      }

      visited[u] = true;

      // Update adjacent vertices
      for (int v = 0; v < vertices; v++) {
        if (cost[u][v] != INF && cost[u][v] != 0 && !visited[v] && cost[u][v] < key[v]) {

          parent[v] = u;
          key[v] = cost[u][v];
        }
      }
    }

    int totalCost = 0;

    cout << "\nMinimum Spanning Tree (MST):\n";
    cout << "Campus Location 1 - Campus Location 2 - Distance\n";

    for (int i = 1; i < vertices; i++) {
      cout << "       " << parent[i] << "        -        " << i << "        -        " << cost[i][parent[i]]
           << " meters\n";

      totalCost += cost[i][parent[i]];
    }

    cout << "\nTotal Minimum Cost: " << totalCost << " meters\n";
  }
};

int main() {
  int v, choice, u, w, distance;

  cout << "Enter number of campus locations: ";
  cin >> v;

  if (v <= 0 || v > MAX) {
    cout << "Invalid number of locations!\n";
    return 0;
  }

  Graph g(v);

  do {
    cout << "\n--- College Campus Map ---\n";
    cout << "1. Add Path\n";
    cout << "2. Display Weighted Graph\n";
    cout << "3. Find Minimum Spanning Tree (Prim's Algorithm)\n";
    cout << "4. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter two locations and distance: ";
      cin >> u >> w >> distance;
      g.addEdge(u, w, distance);
      break;

    case 2:
      g.display();
      break;

    case 3:
      g.primsMST();
      break;

    case 4:
      cout << "Exiting program.\n";
      break;

    default:
      cout << "Invalid choice!\n";
    }

  } while (choice != 4);

  return 0;
}
