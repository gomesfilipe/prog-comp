#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(100000);

int main() {
  int n, x, sum = 0;
  cin >> n;
  int happy = n;

  for(int i = 0; i < n; i++) {
    cin >> x;
    v[i] = x;
  }

  sort(v.begin(), v.begin() + n);

  for(int i = 0; i < n; i++) {
    // cout << v[i] << endl;
    if(sum <= v[i]) {
      sum += v[i];
    } else {
      happy--;
    }
  }

  cout << happy << endl;
  return 0;
}
