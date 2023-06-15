#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int visited[110];
char type[110];
int dist[110];

void executeTestCase(int test);

int main() {
  int t;
  cin >> t;

  for(int i = 0; i < t; i++) {
    executeTestCase(i + 1);
  }

  return 0;
}

void executeTestCase(int test) {
  int n, d;
  cin >> n >> d;
  char typeStone, trash;
  int distStone;
  int maxLeap;

  for(int i = 1; i <= n; i++) {
    cin >> typeStone >> trash >> distStone;
    visited[i] = 0;
    type[i] = typeStone;
    dist[i] = distStone;        
  }

  visited[0] = 0;
  type[0] = 'B';
  dist[0] = 0;

  visited[n + 1] = 0;
  type[n + 1] = 'B';
  dist[n + 1] = d;

  maxLeap = dist[1];

  // ida
  for(int i = 1; i <= n; i++) {
    visited[i] = 1;

    if(type[i + 1] == 'B') { // prox é big
      maxLeap = max(maxLeap, dist[i + 1] - dist[i]);
    
    } else { // prox é small
      maxLeap = max(maxLeap, dist[i + 2] - dist[i]);
      i++;
    }
  }

  // volta
  for(int i = n + 1; i > 0; i--) {
      visited[i] = 1;

      if(type[i - 1] == 'B' || !visited[i - 1]) {
        maxLeap = max(maxLeap, dist[i] - dist[i - 1]);
      } else {
        maxLeap = max(maxLeap, dist[i] - dist[i - 2]);
        i--;
      }
  }

  cout << "Case " << test << ": " << maxLeap << endl;
}
