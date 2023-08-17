#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int heights[100000];
int costs[100000];

int minCost(int n) {
  if(n == 0 || costs[n] != -1) {
    return costs[n];
  }

  costs[n] = min(
    minCost(n - 1) + abs(heights[n] - heights[n - 1]),
    minCost(n - 2) + abs(heights[n] - heights[n - 2])
  );

  return costs[n];
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    costs[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  costs[0] = 0;
  costs[1] = abs(heights[1] - heights[0]);

  cout << minCost(n - 1) << endl;
  return 0;
}
