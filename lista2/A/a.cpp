#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v;

int main() {
  int n, a, b;
  cin >> n;

  for(int i = 0; i < n - 1; i++) {
    v.push_back(i + 1);
  }

  cin >> a;
  for(int i = 0; i < n - 1; i++) {
    cin >> b;
    if(abs(b - a) > n - 1) {
      cout << "Not jolly" << endl;
      return 0;
    } else {
      if(binary_search(v.begin(), v.end(), abs(b - a))) {
        // cout << "encontrou " << abs(b - a) << endl;
        // printf("ponteiro: [%d]\n", *lower_bound(v.begin(), v.end(), abs(b - a)));
        v.erase(lower_bound(v.begin(), v.end(), abs(b - a)));
      } else {
        cout << "Not jolly" << endl;
        return 0;
      }
    }

    a = b;
  }

  // for(int& i : v) {
  //   cout << i << endl;
  // }

  cout << "Jolly" << endl;
  return 0;
}
