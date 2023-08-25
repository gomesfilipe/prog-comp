#include <bits/stdc++.h>
using namespace std;

#define INF 1000000
int V;
 
void floydWarshall(int** dist) {
  int i, j, k;

  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (
          dist[i][j] > (dist[i][k] + dist[k][j])
          && (dist[k][j] != INF
          && dist[i][k] != INF)
        )
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}
 
int main() {
  int t, n, r, p, q, sum = 0;
  cin >> t;

  for(int k = 0; k < t; k++) {
    cin >> V;

    int** dist = (int**) malloc(sizeof(int*) * 50);

    for(int i = 0; i < V; i++) {
      dist[i] = (int*) malloc(sizeof(int) * 50);
    }
    
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
        cin >> dist[i][j];
      }
    }

    floydWarshall(dist);

    cin >> r;
    for(int i = 0; i < r; i++) {
      cin >> p >> q;
      sum += dist[p - 1][q - 1];
    }

    cout << "Case #" << k + 1 << ": " << sum << endl;
    sum = 0;
  }
  return 0;
}
