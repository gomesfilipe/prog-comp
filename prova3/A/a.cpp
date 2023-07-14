#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>
using namespace std;

int colors[200] = {-1};

// Graph class represents a directed graph
// using adjacency list representation
// class Graph {
// public:
//     map<int, bool> visited;
//     map<int, list<int> > adj;
 
//     // Function to add an edge to graph
//     void addEdge(int v, int w);
 
//     // DFS traversal of the vertices
//     // reachable from v
//     bool DFS(int v);
//     bool BFS(int v);
// };
 
// void Graph::addEdge(int v, int w)
// {
//     // Add w to v’s list.
//     adj[v].push_back(w);
// }
 
// bool Graph::DFS(int v)
// {
//     // Mark the current node as visited and
//     // print it
//     visited[v] = true;
 
//     // Recur for all the vertices adjacent
//     // to this vertex
//     list<int>::iterator i;
//     for (i = adj[v].begin(); i != adj[v].end(); ++i) {
//         if(visited[*i] && colors[v] == colors[*i]) {
//             return false;
//         }
        
//         else if (!visited[*i])
//             colors[*i] = colors[v] == 0 ? 1 : 0;
//             int x = DFS(*i);
//             if(x == false) return false;
//     }
    
//     return true;
// }

// C++ code to print BFS traversal from a given
// source vertex

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

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {

		// Dequeue a vertex from queue and print it
		s = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s.
		// If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (auto i : adj[s]) {
            if(visited[i] && colors[s] == colors[i]) {
                return false;
            }

			if (!visited[i]) {
                colors[i] = colors[s] == 0 ? 1 : 0;
				visited[i] = true;
				queue.push_back(i);
			}
		}

	}
    return true;
}
 
// Driver code
int main()
{
    int V, E;
    colors[0] = 0;
    while(true) {
        cin >> V;
        if(V == 0) break;
        cin >> E;

        Graph g(V);

        for(int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }

        if(g.BFS(0)) {
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }
    }
 
    return 0;
}
