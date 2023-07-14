#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
 
#define V 128
#define FROM 0
#define TO 1

int graph[V][V];
int parent[V];
bool bfs(int s, int t, int parent[]) {
  bool visited[V];
  memset(visited, 0, sizeof(visited));

  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  // Standard BFS Loop
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v = 0; v < V; v++) {
      if (visited[v] == false && graph[u][v] > 0) {
        if (v == t) {
          parent[v] = u;
          return true;
        }
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
 
  return false;
}
 
int fordFulkerson(int s, int t) {
    int u, v;
    int parent[V]; 
    int max_flow = 0; // There is no flow initially
 
    while (bfs(s, t, parent)) {
      int path_flow = INT_MAX;
      for (v = t; v != s; v = parent[v]) {
        u = parent[v];
        path_flow = min(path_flow, graph[u][v]);
      }

      for (v = t; v != s; v = parent[v]) {
        u = parent[v];
        graph[u][v] -= path_flow;
        graph[v][u] += path_flow;
      }

      max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}
 
// Driver program to test above functions
int main()
{
  int qtd = 0;
  vector<int> arestas;
  char linha[100];

  while(cin.getline(linha, 100)){
    if(linha[0] == '\0'){
      for(int i = '0'; i <= '9'; i++){
          graph[i][TO] = 1;
      }

        
      int flow = fordFulkerson(FROM, TO);

      if(flow != qtd){
          cout << "!" << endl;
      }
      else{
        for(int i = '0'; i <= '9'; i++){
          bool flag = false;
          for(int j = 0; j < arestas.size(); j++){
            if(graph[i][arestas[j]] == 1){
              cout << char(arestas[j]);
              flag = true;
              break;
            }
          }
          if(!flag){
            cout << "_";
          }
        }
        cout << endl;
      }

      fill(graph[0], graph[0] + V * V, 0);
      arestas.clear();
      qtd = 0;
      // imprimir
    } else{
      char letter = linha[0];
      char number = linha[1];

      graph[FROM][letter] = number-'0';
      arestas.push_back(letter);

      qtd += number-'0';

      for(int i = 3; linha[i] != ';'; i++){
        graph[letter][linha[i]] = 1;
      }
    }

  }
  for(int i = '0'; i <= '9'; i++){
    graph[i][TO] = 1;
  }

  int flow = fordFulkerson(FROM, TO);
  if(flow != qtd){
      cout << "!" << endl;
  } else{
    for(int i = '0'; i <= '9'; i++){
      bool flag = false;
      for(int j = 0; j < arestas.size(); j++){
        if(graph[i][arestas[j]] == 1){
          cout << char(arestas[j]);
          flag = true;
          break;
        }
      }
      if(!flag){
        cout << "_";
      }
    }
    cout << endl;
  }

  return 0;
}
