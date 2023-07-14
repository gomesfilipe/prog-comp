// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// To add an edge
void addEdge(vector<pair<int, int> > adj[], int u, int v,
			int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

// Prints shortest paths from src to all other vertices
void shortestPath(vector<pair<int, int> > adj[], int V,
				int src, int dest, int caso)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
	priority_queue<iPair, vector<iPair>, greater<iPair> >
		pq;

	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (!pq.empty()) {
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		// Get all adjacent of u.
		for (auto x : adj[u]) {
			// Get vertex label and weight of current
			// adjacent of u.
			int v = x.first;
			int weight = x.second;

			// If there is shorted path to v through u.
			if (dist[v] > dist[u] + weight) {
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	// printf("Vertex Distance from Source\n");
	// for (int i = 0; i < V; ++i)
	// 	printf("%d \t\t %d\n", i, dist[i]);

    printf("Case #%d: ", caso);

    if (dist[dest] == INF)
    {
        printf("unreachable\n");
    }
    else{
        printf("%d\n", dist[dest]);
    }

}

// Driver program to test methods of graph class
int main()
{
    int cases;

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        int n, m, s, t;

        cin >> n >> m >> s >> t;

        vector<iPair> adj[n];

        for (int j = 0; j < m; j++)
        {
            int u, v, weight;

            cin >> u >> v >> weight;

            addEdge(adj, u, v, weight);
        }

        shortestPath(adj, n, s, t, i + 1);        
    }
	return 0;
}
