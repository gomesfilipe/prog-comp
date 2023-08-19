#include <iostream>
#include <algorithm>

using namespace std;

int m[100];
pair<int, int> table[101][10001];

pair<int, int> minn(pair<int, int> a, pair<int, int> b) {
  if(a.first < b.first) {
    return a;
  } else if(b.first < a.first) {
    return b;
  } else {
    if(a.second <= b.second) {
      return a;
    } else {
      return b;
    }
  }
  return make_pair(-1, -1);
}

void init(int n, int v) {
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= v; j++) {
      if(i == 0 || j == 0) {
        table[i][j] = make_pair(1000000, 1000000); 
      
      } else {
        table[i][j] = make_pair(-1, -1);
      }
    }
  }

  return;
}

pair<int, int> solve(int n, int v) {
  for(int i = 0; i <= n; i++) table[i][0] = make_pair(1000000, 1000000);
  for(int j = 0; j <= v; j++) table[0][j] = make_pair(1000000, 1000000);

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= v; j++) {
      if(m[i - 1] >= j) {
        table[i][j] = minn(make_pair(m[i - 1], 1), table[i - 1][j]);
      
      } else {
        table[i][j] = minn(
          make_pair(m[i - 1] + table[i - 1][j - m[i - 1]].first, 1 + table[i - 1][j - m[i - 1]].second),
          table[i - 1][j]
        );
      }
    }
  }

  return table[n][v];
}

int main() {
  int t, v, n;
  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> v >> n;

    for(int j = 0; j < n; j++) {
      cin >> m[j];
    }

    init(n, v);
    pair<int, int> result = solve(n, v);
    cout << result.first << " " << result.second << endl;
  }
  
  return 0;
}
