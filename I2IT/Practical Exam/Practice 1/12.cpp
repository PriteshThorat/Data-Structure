// Implement Dijkstra’s algorithm in C++ to find and display the shortest distances
// and paths from a given source vertex to all other vertices in a weighted graph
// with non-negative edge weights.

#include <climits>
#include <iostream>
using namespace std;

#define V 5

int minDistance(int dist[], bool visited[]) {
  int min = INT_MAX;
  int minIndex = -1;

  for (int i = 0; i < V; i++) {
    if (!visited[i] && dist[i] <= min) {
      min = dist[i];
      minIndex = i;
    }
  }

  return minIndex;
}

void printPath(int parent[], int vertex) {
  if (parent[vertex] == -1) return;

  printPath(parent, parent[vertex]);
  cout << " -> " << parent[vertex] + 1;
}

void dijkstra(int graph[V][V], int source) {
  int dist[V];
  bool visited[V] = {false};
  int parent[V];

  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX;
    parent[i] = -1;
  }

  dist[source] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, visited);

    if (u == -1) break;

    visited[u] = true;

    for (int v = 0; v < V; v++) {
      if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
    }
  }

  cout << "\nShortest distances and paths from Vertex " << source + 1 << ":\n";

  for (int i = 0; i < V; i++) {
    cout << "\nVertex " << i + 1 << ": ";

    if (dist[i] == INT_MAX) {
      cout << "No path available";
    } else {
      cout << "Distance = " << dist[i];
      cout << ", Path = " << source + 1;

      printPath(parent, i);
      cout << " -> " << i + 1;
    }

    cout << endl;
  }
}

int main() {
  int graph[V][V] = {
      {0, 100, 150, 120, 0}, {100, 0, 80, 90, 200}, {150, 80, 0, 0, 130}, {120, 90, 0, 0, 100}, {0, 200, 130, 100, 0}};

  int source;

  cout << "Enter source vertex (1-5): ";
  cin >> source;

  if (source < 1 || source > V) {
    cout << "Invalid source vertex!";
    return 0;
  }

  dijkstra(graph, source - 1);

  return 0;
}
