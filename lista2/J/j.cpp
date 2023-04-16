#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

void readVector(int n);
void printVector(int n);

vector<int> v;

int main() {
  int t, n;
  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> n;
    readVector(n);
    
    if(next_permutation(v.begin(), v.end())) {
      printVector(n);
    } else {
      cout << -1 << endl;
    }

    v.clear();
  }

  return 0;
}

void readVector(int n) {
  int x;
  for(int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
}

void printVector(int n) {
  int x;
  for(int i = 0; i < n; i++) {
    cout << v[i];
  }
  cout << endl;
}
