#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int terrain[1000][1000];
int dists[1000][1000];
bool visited[1000][1000];

void inicTerrain(int r, int c, int* a, int* b, int* x, int* y) {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      terrain[i][j] = 1;
      visited[i][j] = false;
      // dists[i][j] = INT32_MAX;
    }
  }

  int rowsWithBombs, i, j, n;

  cin >> rowsWithBombs;

  for(int k = 0; k < rowsWithBombs; k++) {
    cin >> i >> n;
    for(int l = 0; l < n; l++) {
      cin >> j;
      terrain[i][j] = 0;
      dists[i][j] = INT16_MAX;
    }
  }

  cin >> *a >> *b; // start (a, b)
  cin >> *x >> *y; // end (x, y)
  dists[*x][*y] = 0;
  return;
}

bool validPosition(int i, int j, int r, int c) {
  return i >= 0 && i < r && j >= 0 && j < c;
}

int bfs(int x, int y, int a, int b, int r, int c) {
  int i, j;
  queue<pair<int, int>> q;
  visited[x][y] = true;
  q.push(make_pair(x, y));

  while(!q.empty()) {
    pair<int, int> s = q.front();
    q.pop();

    // printf("(%d, %d)\n", s.first, s.second);

    pair<int, int> adj[4] = { 
      make_pair(s.first - 1, s.second), 
      make_pair(s.first, s.second - 1), 
      make_pair(s.first, s.second + 1), 
      make_pair(s.first + 1, s.second) 
    };
    
    for(auto x : adj) {
      i = x.first;
      j = x.second;

      if(validPosition(i, j, r, c) && !visited[i][j] && terrain[i][j] == 1) {
        visited[i][j] = true;
        dists[i][j] = 1 + dists[s.first][s.second];
        q.push(make_pair(i, j));
      }

      if(i == a && j == b) return dists[a][b];
    }
  }
  return 0;
}

int main() {
  int r, c, a, b, x, y;
  
  while(true) {
    cin >> r >> c;
    if(r == 0 && c == 0) break;
    
    inicTerrain(r, c, &a, &b, &x, &y);
    cout << bfs(x, y, a, b, r, c) << endl;
  }

  return 0;
}
