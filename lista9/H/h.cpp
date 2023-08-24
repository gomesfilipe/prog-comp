#include <iostream>
#include <algorithm>
#include <queue>
#include<tuple>

using namespace std;

int configs[10][10][10][10];
int dists[10][10][10][10];
int visited[10][10][10][10];


void inicConfigs(
  int a1, int a2, int a3, int a4,
  int b1, int b2, int b3, int b4
) {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      for(int k = 0; k < 10; k++) {
        for(int l = 0; l < 10; l++) {
          configs[i][j][k][l] = 1;
          visited[i][j][k][l] = false;
        }
      }
    }
  }
  dists[a1][a2][a3][a4] = 0;
  return;
}

bool validPosition(int i, int j, int k, int l) {
  return i >= 0 && i < 10 && j >= 0 && j < 10 && k >= 0 && k < 10 && l >= 0 && l < 10;
}

int bfs(
  int a1, int a2, int a3, int a4,
  int b1, int b2, int b3, int b4
) {
  int i, j, k, l;
  queue<tuple<int, int, int, int>> q;
  visited[a1][a2][a3][a4] = true;
  
  q.push(make_tuple(a1, a2, a3, a4));

  while(!q.empty()) {
    tuple<int, int, int, int> s = q.front();
    q.pop();

    tuple<int, int, int, int> adj[8] = { 
      make_tuple((get<0>(s) + 1) % 10, get<1>(s), get<2>(s), get<3>(s)), 
      make_tuple((get<0>(s) + 9) % 10, get<1>(s), get<2>(s), get<3>(s)), 
      
      make_tuple(get<0>(s), (get<1>(s) + 1) % 10, get<2>(s), get<3>(s)), 
      make_tuple(get<0>(s), (get<1>(s) + 9) % 10, get<2>(s), get<3>(s)),

      make_tuple(get<0>(s), get<1>(s), (get<2>(s) + 1) % 10, get<3>(s)), 
      make_tuple(get<0>(s), get<1>(s), (get<2>(s) + 9) % 10, get<3>(s)),

      make_tuple(get<0>(s), get<1>(s), get<2>(s), (get<3>(s) + 1) % 10), 
      make_tuple(get<0>(s), get<1>(s), get<2>(s), (get<3>(s) + 9) % 10)
    };
    
    for(auto x : adj) {
      i = get<0>(x);
      j = get<1>(x);
      k = get<2>(x);
      l = get<3>(x);

      int di = get<0>(s);
      int dj = get<1>(s);
      int dk = get<2>(s);
      int dl = get<3>(s);

      if(validPosition(i, j, k, l) && !visited[i][j][k][l] && configs[i][j][k][l] == 1) {
        visited[i][j][k][l] = true;
        dists[i][j][k][l] = 1 + dists[di][dj][dk][dl];
        q.push(make_tuple(i, j, k, l));
      }

      if(i == b1 && j == b2 && k == b3 && l == b4) return dists[b1][b2][b3][b4];
    }
  }
  return -1;
}

int main() {
  int t;
  cin >> t;

  while(t--) {
    int a1, a2, a3, a4;
    int b1, b2, b3, b4;
    int f1, f2, f3, f4;
    int n;

    cin >> a1 >> a2 >> a3 >> a4;
    cin >> b1 >> b2 >> b3 >> b4;
    
    inicConfigs(a1, a2, a3, a4, b1, b2, b3, b4);

    cin >> n;

    while(n--) {
      cin >> f1 >> f2 >> f3 >> f4;
      configs[f1][f2][f3][f4] = 0;
    }

    cout << bfs(a1, a2, a3, a4, b1, b2, b3, b4) << endl;
  }

  return 0;
}
