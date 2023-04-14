#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool jolly(int n);

int main() {
  int n;

  while(true) {
    // if(feof(stdin)) break;
    if(!(cin >> n)) break;
    // cout << n << endl;
    if(jolly(n)) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
    // cout << n << endl << feof(stdin) << endl << endl;

  }
  return 0;
}

bool jolly(int n) {
  int a, b, diff;
  string scape;
  vector<bool> diffFound(n - 1, false);

  cin >> a;
  for(int i = 0; i < n - 1; i++) {
    cin >> b;
    diff = abs(b - a);
    if(diff < 1 || diff > n - 1 || diffFound[diff - 1]) {
      getline(cin, scape);
      // cin.ignore();
      // cin.ignore();
      // cout << "scape " << scape << endl;
      return false;
    } else {
      diffFound[diff - 1] = true;
    }
    a = b;
  }
  return true;
}
