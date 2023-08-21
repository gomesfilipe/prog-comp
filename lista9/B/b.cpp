#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Graph {
public:
  map<int, bool> visited;
  map<int, list<int> > adj;

  void addEdge(int v, int w);
  bool DFS(int v, int n);
};
 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}
 
bool Graph::DFS(int v, int n) {
  visited[v] = true;
  if(v == n) {
    return true;
  }

  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i]) {
      if(DFS(*i, n)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int n, a, t;
  cin >> n >> t;

  Graph g;

  for(int i = 1; i <= n - 1; i++) {
    cin >> a;
    g.addEdge(i, i + a);
  }

  if(g.DFS(1, t)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
