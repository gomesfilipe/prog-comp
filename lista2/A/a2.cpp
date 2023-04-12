#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool jolly(int n);

int main() {
  int n;
  cin >> n;

  if(jolly(n)) {
    cout << "Jolly";
  } else {
    cout << "Not jolly";
  }

  return 0;
}

bool jolly(int n) {
  int a, b, diff;
  vector<bool> diffFound(n - 1, false);

  cin >> a;
  for(int i = 0; i < n - 1; i++) {
    cin >> b;
    diff = abs(b - a);
    if(diff < 1 || diff > n - 1 || diffFound[diff - 1]) {
      return false;
    } else {
      diffFound[diff - 1] = true;
    }
    a = b;
  }

  return true;
}
