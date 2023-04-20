#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void readSet(int n);
void countMoves();

set<int> s;

int main() { 
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++) {
    countMoves();
    s.clear();
  }

  return 0;
}

void readSet(int n) {
  int x;
  for(int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
  }
}

void countMoves() {
  int n, min = 0;
  cin >> n;
  readSet(n);

  while(!s.empty()) {
    int maxNum = *s.rbegin();
    s.erase(maxNum);
    if(maxNum % 2 == 0) {
      s.insert(maxNum / 2);
      min++;
    }
  }

  cout << min << endl;
}
