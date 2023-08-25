#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
	int V;
	list<pair<int, int> >* adj;

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	int shortestPath(int s, int t);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

int Graph::shortestPath(int src, int target)
{
	// cout << "entrou" << endl;
  priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty()) {
    // cout << "entrou1" << endl;
		int u = pq.top().second;
		pq.pop();

		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
  // cout << "saiu" << endl;
  return dist[target];
}

int cost(int a, int b, int c, int d) {
  return a * c + b * d;
}

// bool validPosition(int i, int j) {
//   return i >= 0 && i < 8 && j >= 0 && j < 8;
// }

bool validPosition(int p) {
  return p >= 0 && p < 64;
}

int main() {
  ios::sync_with_stdio(false);
  
  int a, b, c, d;

  while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4) {
    Graph g(64);

    for(int i = 0; i < 8; i++) {
      for(int j = 0; j < 8; j++) {
        iPair adj[8] = {
          make_pair(8*(i-2)+(j-1), cost(i, j, i-2, j-1)),
          make_pair(8*(i-2)+(j+1), cost(i, j, i-2, j+1)),
          make_pair(8*(i-1)+(j-2), cost(i, j, i-1, j-2)),
          make_pair(8*(i-1)+(j+2), cost(i, j, i-1, j+2)),
          make_pair(8*(i+1)+(j-2), cost(i, j, i+1, j-2)),
          make_pair(8*(i+1)+(j+2), cost(i, j, i+1, j+2)),
          make_pair(8*(i+2)+(j-1), cost(i, j, i+2, j-1)),
          make_pair(8*(i+2)+(j+1), cost(i, j, i+2, j+1))
        };

        for(iPair x : adj) {
          if(validPosition(x.first)) g.addEdge(8*i+j, x.first, x.second);
        } 
      }
    }

    int src = 8 * a + b;
    int target = 8 * c + d;

    cout << g.shortestPath(src, target) << endl;
  }

	return 0;
}
