// Represent a college campus map as a weighted graph, where vertices represent
// campus locations and edges represent the distances between them. Implement
// Kruskal’s Algorithm in C++ to find and display the Minimum Spanning Tree (MST)
// with its total minimum cost.

#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 50

// Structure to represent an edge
struct Edge {
  int src, dest, weight;
};

// Graph class
class Graph {
  int vertices, edgeCount;
  Edge edges[MAX];

  // Find parent of a vertex
  int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex) return vertex;

    return findParent(parent, parent[vertex]);
  }

  // Union of two sets
  void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
    else {
      parent[rootV] = rootU;
      rank[rootU]++;
    }
  }

public:
  Graph(int v) {
    vertices = v;
    edgeCount = 0;
  }

  // Add weighted edge
  void addEdge(int u, int v, int weight) {
    if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
      cout << "Invalid location!\n";
      return;
    }

    if (u == v || weight <= 0 || edgeCount >= MAX) {
      cout << "Invalid edge!\n";
      return;
    }

    edges[edgeCount].src = u;
    edges[edgeCount].dest = v;
    edges[edgeCount].weight = weight;

    edgeCount++;

    cout << "Path added successfully.\n";
  }

  // Kruskal's Algorithm
  void kruskalMST() {
    Edge sortedEdges[MAX];

    for (int i = 0; i < edgeCount; i++)
      sortedEdges[i] = edges[i];

    // Sort edges by weight
    sort(sortedEdges, sortedEdges + edgeCount, [](Edge a, Edge b) { return a.weight < b.weight; });

    int parent[MAX], rank[MAX] = {0};

    for (int i = 0; i < vertices; i++)
      parent[i] = i;

    int totalCost = 0;
    int selected = 0;

    cout << "\nMinimum Spanning Tree (MST):\n";
    cout << "Source\tDestination\tDistance\n";

    // Select minimum weight edges
    for (int i = 0; i < edgeCount && selected < vertices - 1; i++) {
      int u = sortedEdges[i].src;
      int v = sortedEdges[i].dest;

      int rootU = findParent(parent, u);
      int rootV = findParent(parent, v);

      // Check whether edge creates a cycle
      if (rootU != rootV) {
        cout << u << "\t" << v << "\t\t" << sortedEdges[i].weight << " meters\n";

        totalCost += sortedEdges[i].weight;

        unionSets(parent, rank, u, v);
        selected++;
      }
    }

    if (selected != vertices - 1) {
      cout << "\nGraph is disconnected. MST cannot be formed.\n";
    } else {
      cout << "\nTotal Minimum Cost: " << totalCost << " meters\n";
    }
  }

  // Display all edges
  void displayEdges() {
    cout << "\nCampus Paths:\n";
    cout << "Source\tDestination\tDistance\n";

    for (int i = 0; i < edgeCount; i++) {
      cout << edges[i].src << "\t" << edges[i].dest << "\t\t" << edges[i].weight << " meters\n";
    }
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
    cout << "2. Display Campus Paths\n";
    cout << "3. Find MST using Kruskal's Algorithm\n";
    cout << "4. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter source, destination and distance: ";
      cin >> u >> w >> distance;
      g.addEdge(u, w, distance);
      break;

    case 2:
      g.displayEdges();
      break;

    case 3:
      g.kruskalMST();
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