#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void readVector(int n);
bool sortVector(int n);
int mdc(int num1, int num2);
int inter(int x, int a, int b, int minAll);

vector<int> v;

int main() {
  int t, n;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    readVector(n);
    if(sortVector(n)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    v.clear();
  }
}

void readVector(int n) {
  int x;
  for(int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
}

bool sortVector(int n) {
  int indexMinAll, minAll, indexMinSub, minSub, tmp;
  indexMinAll = distance(v.begin(), min_element(v.begin(), v.end()));
  minAll = v[indexMinAll];

  for(int i = 0; i < n; i++) {
    indexMinSub = distance(v.begin(), min_element(v.begin() + i, v.end()));
    minSub = v[indexMinSub];
    if(v[indexMinSub] == v[i]) {
      continue;
    
    } else if(mdc(v[i], minSub) == minAll) {
      tmp = v[i];
      v[i] = minSub;
      v[indexMinSub] = tmp;
    
    } else if(inter(minAll, minSub, v[i], minAll)) { // intermediário
      tmp = v[i];
      v[i] = minSub;
      v[indexMinSub] = tmp;

      return false;
    }
  }

  return true;
}

int mdc(int num1, int num2) {
  if(num1 % num2 == 0)
    return num2;
  else
    return mdc(num2, num1 % num2);
}

int inter(int x, int a, int b, int minAll) {
  return mdc(x, a) == minAll && mdc(x, b) == minAll && x != b;
}
