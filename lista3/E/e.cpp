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
  int smallers = 0;
  int greaters;

  for(greaters = n / 2; greaters < n && smallers < n / 2; greaters++) {
    if(v[smallers] <= v[greaters] / 2) {
      min--;
      smallers++;
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
