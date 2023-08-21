#include <bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph {
 
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    vector<list<int> > adj;
 
public:
    // Constructor
    Graph(int V);
 
    // Function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints BFS traversal from a given source s
    bool BFS(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
bool Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V, false);

    vector<int> colors;
    colors.resize(V, -1);

    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    colors[s] = 0;
    queue.push_back(s);

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjacent : adj[s]) {
            if (!visited[adjacent]) {
                colors[adjacent] = colors[s] == 0 ? 1 : 0;
                visited[adjacent] = true;
                queue.push_back(adjacent);
            
            } else if(colors[s] == colors[adjacent]) {
              return false;
            }
        }
    }
    return true;
}
 
int main() {
  int n, l, a, b;
  
  while (true) {
    cin >> n;
    if (n == 0) break;
    cin >> l;

    Graph g(n);
    for(int i = 0; i < l; i++) {
      cin >> a >> b;
      g.addEdge(a, b);
      g.addEdge(b, a);
    }

    if(g.BFS(0)) {
      cout << "BICOLORABLE." << endl;
    } else {
      cout << "NOT BICOLORABLE." << endl;
    }
  }

  return 0;
}