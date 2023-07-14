// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>

using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// Function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w) {
	// Add w to v’s list.
	adj[v].push_back(w);
}

void Graph::DFS(int v) {
	visited[v] = true;

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

void printLine(int n_nodes) {
    printf("+");
    for(int j = 0; j < n_nodes; j++) {
      if(j != n_nodes - 1)
        printf("-");
      printf("-");
    }
    printf("+\n");
}

// Driver code
int main()
{
  int cases;
  cin >> cases;

  for(int i = 0; i < cases; i++) {
    Graph g;
    int n_nodes;
    cin >> n_nodes;

    for (int j = 0; j < n_nodes; j++) {
      for(int k = 0; k < n_nodes; k++) {
        int aux;
        cin >> aux;

        if(aux == 1) {
          g.addEdge(j, k);
        }
      }
    }

    g.DFS(0);

    printf("Case %d:\n", i + 1);

    for(int j = 0; j < n_nodes; j++) {
      Graph g_clone = g;
      g_clone.visited.clear();
      g_clone.adj[j].clear();
      g_clone.DFS(0);
      printLine(n_nodes);

      for(int k = 0; k < n_nodes; k++) {
        if(k == j) {
          if(g.visited[j] == true)
            printf("|Y");
          else
            printf("|N");
        } else{
          if(g_clone.visited[k] == true || g.visited[k] == false) {
            printf("|N");
          
          } else {
            printf("|Y");
          }
        }
      }
      printf("|\n");
    }
    printLine(n_nodes);
  }

  return 0;
}
