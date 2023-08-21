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
  void removeEdge(int v, int w);
  bool DFS(int v, int n);
  int groups(int n);
};

void Graph::removeEdge(int v, int w) {
  if(adj[v].size() > 0) {
    adj[v].remove(w);
  }
}

int Graph::groups(int n) {
  int counter = 0;
  vector<pair<int, int>> toRemove;

  while(true) {
    for(int i = 1; i <= n; ++i) {
      if(adj[i].size() == 1) {
        toRemove.push_back(make_pair(i, adj[i].front()));
      }
    }

    if(toRemove.size() > 0) {
      counter++;

      for(pair<int, int> j : toRemove) {
        removeEdge(j.first, j.second);
        removeEdge(j.second, j.first);
      }
      
      toRemove.clear();
    } else {
      break;
    }
  }

  return counter;
}

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
  int n, m, a, b;
  cin >> n >> m;

  Graph g;

  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    g.addEdge(a, b);
    g.addEdge(b, a);
  }

  cout << g.groups(n) << endl;
  return 0;
}
