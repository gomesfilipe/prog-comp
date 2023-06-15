#include <iostream>
#include <set>
using namespace std;

set<int> s;
int uniques[100000];
int num[100000];

int main() {
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    cin >> num[i];
  }

  for(int i = n - 1; i >= 0; i--) {
    s.insert(num[i]);
    uniques[i] = s.size();
  }

  for(int i = 0; i < m; i++) {
    int aux;
    cin >> aux;
    cout << uniques[aux - 1] << endl;
  }

  return 0;
}
