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

pair<int, int> solve(int i, int v) {
  if(table[i][v].first != -1) return table[i][v];
  
  if(m[i - 1] >= v) {
    return minn(
      make_pair(m[i - 1], 1), 
      solve(i - 1, v)
    );

  } else {
    pair<int, int> pair1 = solve(i - 1, v - m[i - 1]);
    pair1.first += m[i - 1];
    pair1.second += 1;

    pair<int, int> pair2 = solve(i - 1, v);
    
    return minn(pair1, pair2);
  }

  return make_pair(-1, -1);
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
