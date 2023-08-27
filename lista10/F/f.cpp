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

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

int Graph::shortestPath(int src, int timer) {
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
  
  int mice = 0;

  for(int x : dist) {
    if(x <= timer) mice++;
  }

  return mice;
}

int main() {
  ios::sync_with_stdio(false);
  
  int t, n, exit, timer, m, a, b, w;
  cin >> t;

  while(t--) {
    cin >> n >> exit >> timer >> m;

    Graph g(n);

    while(m--) {
      cin >> a >> b >> w;
      g.addEdge(a - 1, b - 1, w);
    }

    cout << g.shortestPath(exit - 1, timer) << endl;

    if(t) cout << endl;
  }

	return 0;
}
