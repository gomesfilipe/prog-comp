#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
using namespace std;

vector<int> path;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
 
    // Function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    bool DFS(int v, int n);
};
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
bool Graph::DFS(int v, int n)
{
    visited[v] = true;
    if(v == n) {
      return true;
    }

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
      if (!visited[*i]) {
        if(DFS(*i, n)) {
          path.push_back(*i);
          return true;
        }
      }
    }
    return false;
}

int main() {
  int n, j;
  cin >> n;

  Graph g;

  for(int i = 1; i <= n - 1; i++) {
    cin >> j;
    g.addEdge(j - 1, i);
    g.addEdge(i, j - 1);
  }

  g.DFS(0, n - 1);

  path.push_back(0);
  for(int i = path.size() - 1; i >= 0; --i) {
    cout << path[i] + 1;
    if(i != 0) cout << " ";
  }

  cout << endl;
  return 0;
}
