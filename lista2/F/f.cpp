#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void cookies(int c, int r);
bool divideBy(int x, int y);

vector<int> v;

int main() {
  int n, r, c;
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> c >> r;
    
    cout << "Case #" << i << ":";
    cookies(c, r);
  }

  return 0;
}

void cookies(int c, int r) {
  if(r == c) {
    cout << " 0" << endl;
    return;
  }

  for(int i = 1; i <= floor(sqrt(c - r)); i++) {
    if(divideBy(i, c - r)) {
      if(r < i) cout << " " << i;
      if(r < (c - r) / i) v.push_back((c - r) / i);
    }
  }

  if(floor(sqrt(c - r)) * floor(sqrt(c - r)) == c - r && r < floor(sqrt(c - r))) { // eh quadrado perfeito, evitando repetição
    v.pop_back();
  }

  for(int i = v.size() - 1; i >= 0; i--) {
    cout << " " << v[i];
    v.pop_back();
  }

  cout << endl;
}

bool divideBy(int x, int y) {
  return y % x == 0;
}
