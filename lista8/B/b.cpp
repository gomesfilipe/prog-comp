#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int happiness[100000][3];
int points[100000][3];

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
  }
  
  points[0][0] = happiness[0][0];
  points[0][1] = happiness[0][1];
  points[0][2] = happiness[0][2];

  for(int i = 1; i < n; i++) {
    points[i][0] = happiness[i][0] + max(points[i - 1][1], points[i - 1][2]);
    points[i][1] = happiness[i][1] + max(points[i - 1][0], points[i - 1][2]);
    points[i][2] = happiness[i][2] + max(points[i - 1][0], points[i - 1][1]);
  }

  cout << max(points[n - 1][0], max(points[n - 1][1], points[n - 1][2])) << endl;
  return 0;
}
