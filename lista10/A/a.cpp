#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> iPair;

int values[999][18278];

class Graph {
public:
    map<iPair, bool> visited;
    map<iPair, list<iPair>> adj;

    void addEdge(iPair v, iPair w);
    int DFS(const iPair& v);
};
 
void Graph::addEdge(iPair v, iPair w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
int Graph::DFS(const iPair& v) {
    if(values[v.first][v.second] != -1) {
      return values[v.first][v.second];
    }

    visited[v] = true;
 
    int sum = 0;
    list<iPair>::iterator i;

    for(auto& p : adj[v]) {
      values[p.first][p.second] = DFS(p);
      sum += values[p.first][p.second];
    }

    values[v.first][v.second] = sum;
    return sum;
}

bool isUpper(char c) {
  return c >= 'A' && c <= 'Z';
}

void celltoInt(string cell, int* i, int* j) {
  int index;
  for(index = cell.size() - 1; index >= 0; index--) {
    if(isUpper(cell[index])) {
      index++;
      break;
    }

  }
  *j = 0;
  int exp = 0;
  int pos = index - 1;
  for(int k = 0; k < index; k++) {
    *j += (cell[pos] - 'A' + 1) * pow(26, exp);
    exp++;
    pos--;
  }

  (*j)--;
  *i = stoi(cell.substr(index)) - 1;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  int t, columns, rows;
  string cell;

  cin >> t;

  while(t--) {
    vector<string> tokens;
    string token;

    Graph g;

    cin >> columns >> rows;

    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
        cin >> cell;

        if(cell[0] == '=') {
          istringstream tokenizer { cell.substr(1) }; // tirando '=' do começo
          values[i][j] = -1;

          while(getline(tokenizer, token, '+')) {
            int a, b;
            celltoInt(token, &a, &b);
            g.addEdge(make_pair(i, j), make_pair(a, b));
          }

        } else {
          values[i][j] = stoi(cell);
        }
      }
    }

    for(auto& x : g.adj) {
      g.DFS(x.first);
    }

    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
        cout << values[i][j];
        if(j != columns - 1) cout << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
