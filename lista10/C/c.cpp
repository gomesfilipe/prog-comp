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
	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
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

  return dist[target];
}

int main() {
	int N, n, m, S, T, u, v, w;
  
  cin >> N;
  for(int t = 0; t < N; t++) {
    cin >> n >> m >> S >> T;

    Graph g(n);
    
    for(int e = 0; e < m; e++) {
      cin >> u >> v >> w;
      g.addEdge(u, v, w);
    }

    int result = g.shortestPath(S, T);
    
    cout << "Case #" << t + 1 << ": ";

    if(result == INF) cout << "unreachable" << endl;
    else cout << result << endl;
  }

	return 0;
}
