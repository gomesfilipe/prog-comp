#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void readVector(int n);

vector<int> v;

int main() {
  int n;
  cin >> n;
  readVector(n);
  sort(v.begin(), v.end());

  int min = n;
  int i = 0;
  int j = 1;

  while(j < n) {
    if(v[i] < v[j]) {
      min--;
      i++;
      j++;
    } else {
      j++;
    }
  }

  cout << min << endl;
  return 0;
}

void readVector(int n) {
  int x;
  for(int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
}
