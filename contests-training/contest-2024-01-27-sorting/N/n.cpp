#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> diffs;

int main() {
  int n, current, diff, first;
  cin >> n;
  cin >> first;

  int largest = first;
  int smallest = first;

  for(int i = 1; i < n; i++) {
    cin >> current;

    if(current > largest) {
      largest = current;
    }

    if (current < smallest) {
      smallest = current;
    }
  }

  cout << largest - smallest << endl;
  return 0;
}
