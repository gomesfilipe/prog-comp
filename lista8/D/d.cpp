#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int heights[100000];
int costs[100000];

int minCost(int n) {
  costs[0] = 0;
  costs[1] = abs(heights[1] - heights[0]);

  for(int i = 2; i < n; i++) {
    costs[i] = min(
      costs[i - 1] + abs(heights[i] - heights[i - 1]),
      costs[i - 2] + abs(heights[i] - heights[i - 2])
    );
  }

  return costs[n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  cout << minCost(n) << endl;
  return 0;
}
